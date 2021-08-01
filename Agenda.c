#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "Agenda.h"

pessoa contatos[10];
int cont = 0;
int contId = 0;

void menu() {
	char opc, sair;
	
	system("cls");
	printf(" ____________________ \n");
	printf("|                    |\n");
	printf("| Agenda de Contatos |\n");
	printf("|____________________|\n");
	printf("| Opcoes:            |\n");
	printf("| 1 - Cadastrar      |\n");
	printf("| 2 - Excluir        |\n");
	printf("| 3 - Listar         |\n");
	printf("| 4 - Buscar         |\n");
	printf("| 0 - Sair           |\n");
	printf("|____________________|\n");
	
	printf("Opcao: ");
	fflush(stdin);
	scanf("%c", &opc);
	
	if (opc == '1') { // cadastrar
		cadastrar();
	} else if (opc == '2') { // excluir
		excluir();
	} else if (opc == '3') { // listar
		menuListar();
	} else if (opc == '4') { // buscar
		
	} else if (opc == '0') {
		system("cls");
		printf("Deseja mesmo sair? (s/n): ");
		fflush(stdin);
		scanf("%c", &sair);
		
		if (sair == 's' || sair == 'S') {
			system("cls");
			printf("Ate mais...\n");
			system("pause");
		} else {
			menu();
		}
	} else {
		menu();
	}
}

void cadastrar() {
	char novoCadastro;
	
	system("cls");
	printf("Verificando agenda...\n");
	system("pause");
	
	if (cont == 10) {
		printf("Erro! Agenda ja possui 10 registros!\n");
		system("cls");
		menu();
	} else {
		printf("\nVerificacao concluida! Agenda possui espacos disponiveis!\n");
		system("pause");
		
		printf("\nInforme os dados do novo contato:\n");
		printf("    Nome: ");
		fflush(stdin);
		scanf("%[^\n]", contatos[cont].nome);
		printf("    Telefone: ");
		fflush(stdin);
		scanf("%[^\n]", contatos[cont].telefone);
		printf("    E-mail: ");
		fflush(stdin);
		scanf("%[^\n]", contatos[cont].email);
		printf("    Estado (sigla apenas): ");
		fflush(stdin);
		scanf("%[^\n]", contatos[cont].estado);
		printf("    Cidade: ");
		fflush(stdin);
		scanf("%[^\n]", contatos[cont].cidade);
		
		contatos[cont].id = contId;
		contatos[cont].atv = 1;
		
		
		system("cls");
		printf("Dados cadastrados: \n");
		printf("    ID: %d\n", contatos[cont].id);
		printf("    Nome: %s\n", contatos[cont].nome);
		printf("    Telefone: %s\n", contatos[cont].telefone);
		printf("    E-mail: %s\n", contatos[cont].email);
		printf("    Estado (sigla apenas): %s\n", contatos[cont].estado);
		printf("    Cidade: %s\n", contatos[cont].cidade);
		cont++;
		contId++;
		system("pause");
		menu();
	}
}

void excluir() {
	int idBusca, i, posi;
	bool achou = false;
	char excluir;
	
	system("cls");
	
	if (cont == 0) {
		printf("Nao existe nenhum contato cadastrado!\n");
		system("pause");
		menu();
	} else {
		printf("Informe o id do contato: ");
		fflush(stdin);
		scanf("%d", &idBusca);
		
		for(i=0; i<cont; i++) {
			if(contatos[i].id == idBusca && contatos[i].atv == 1) {
				achou = true;
				printf("\nDados encontrados: \n");
				printf("    Nome: %s\n", contatos[i].nome);
				printf("    Telefone: %s\n", contatos[i].telefone);
				printf("    E-mail: %s\n", contatos[i].email);
				printf("    Estado (sigla apenas): %s\n", contatos[i].estado);
				printf("    Cidade: %s\n", contatos[i].cidade);
				posi = i;
				break;
			}
		}
		
		if (achou == true) {
			printf("\nDeseja mesmo excluir o contato? (s/n): ");
			fflush(stdin);
			scanf("%c", &excluir);
			
			if(excluir == 's' || excluir == 'S') {
				contatos[posi].atv = 0;
				
				pessoa aux;
				
				aux = contatos[cont-1];
				contatos[cont-1] = contatos[posi];
				contatos[posi] = aux;
				
				cont--;
				
				printf("\nContato excluido com sucesso!\n");
				system("pause");
				menu();
			} else {
				menu();
			}
		} else {
			printf("\nID nao encontrado!\n");
			system("pause");
			menu();
		}
	}
}

void menuListar() {
	char opcListar;
	
	system("cls");
	
	if (cont == 0) {
		printf("Nao existe nenhum contato cadastrado!\n");
		system("pause");
		menu();
	} else {
		printf("Escolha uma opcao de listagem: \n");
		printf("1 - Por nome (Crescente)\n");
		printf("2 - Por nome (Decrescente)\n");
		printf("3 - Por estado (Decrescente)\n");
		printf("4 - Por cidade (Decrescente)\n");
		printf("0 - Voltar\n");
		printf("Opcao: ");
		fflush(stdin);
		scanf("%c", &opcListar);
		
		if (opcListar == '1') {
			ordenaNomeCrescente();
			exibeListagem();
			system("pause");
			menuListar();
		} else if (opcListar == '2') {
			ordenaNomeDecrescente();
			exibeListagem();
			system("pause");
			menuListar();
		} else if (opcListar == '3') {
			ordenaEstado(contatos, 0, cont);
			exibeListagem();
			system("pause");
			menuListar();
		} else if (opcListar == '4') {
			ordenaCidade();
			exibeListagem();
			system("pause");
			menuListar();
		} else if (opcListar == '0') {
			menu();
		} else {
			menuListar();
		}	
	}
}

void exibeListagem() {
	int i;
	for(i=0; i<cont; i++) {
		if (contatos[i].atv == 1) {
			printf("Contato %d\n", i+1);
			printf("    ID: %d\n", contatos[i].id);
			printf("    Nome: %s\n", contatos[i].nome);
			printf("    Telefone: %s\n", contatos[i].telefone);
			printf("    E-mail: %s\n", contatos[i].email);
			printf("    Estado (sigla apenas): %s\n", contatos[i].estado);
			printf("    Cidade: %s\n", contatos[i].cidade);	
		}
	}
}

void ordenaNomeCrescente() {
	
	int i, j;
	pessoa aux;
	
	for(i=0; i<cont; i++) {
		for(j=i+1; j<cont; j++) {
			if(strcmp(contatos[i].nome, contatos[j].nome) > 0) {
				aux = contatos[i];
				contatos[i] = contatos[j];
				contatos[j] = aux;
			}
		}
	}
	
}

void ordenaNomeDecrescente() {
	int i, j;
	pessoa aux;
	
	for(i=0; i<cont; i++) {
		for(j=i+1; j<cont; j++) {
			if(strcmp(contatos[i].nome, contatos[j].nome) < 0) {
				aux = contatos[i];
				contatos[i] = contatos[j];
				contatos[j] = aux;
			}
		}
	}
}

void ordenaEstado(pessoa vetor[], int esq, int dir) {
	int pos;
	if (esq<dir) {
		pos = dividir(vetor, esq, dir);
		ordenaEstado(vetor, esq, pos-1);
		ordenaEstado(vetor, pos+1, dir);
	}
}

int dividir(pessoa vetor[], int esq, int dir) {
	pessoa aux;
	int i, contador=esq;
	
	for(i=esq+1; i<=dir; i++) {
		if(strcmp(vetor[i].estado, vetor[esq].estado)>0) {
			contador++;
			aux = vetor[i];
			vetor[i] = vetor[contador];
			vetor[contador] = aux;
		}
	}
	aux = vetor[esq];
	vetor[esq] = vetor[contador];
	vetor[contador] = aux;
	
	return contador;
}

void ordenaCidade() {
	int i, j;
	pessoa aux;
	
	for(i=0; i<cont; i++) {
		for(j=i+1; j<cont; j++) {
			if(strcmp(contatos[i].cidade, contatos[j].cidade) < 0) {
				aux = contatos[i];
				contatos[i] = contatos[j];
				contatos[j] = aux;
			}
		}
	}
}


