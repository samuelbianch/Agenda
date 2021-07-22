#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

int cont=0;

void ordena_nome_cresc(p a,int tam)
{
	int i,j;
	p aux;
	for(i=0;i<tam-1;i++)
		for(j=i+1;j<tam;j++)
		{
			if(strcmp((&a[i])->nome,(&a[j])->nome)>0)
			{
				*(aux)= a[i];
				a[i]=a[j];
				a[j] = *(aux);
			}
		}
	
}
void leitura(p a, int tam)
{
	p aux;
	int i;
	for(i=0;i<tam;i++)
	{
		fflush(stdin);
		printf("Digite seu nome: ");
		scanf("%c[^\n]",&aux->nome);
		fflush(stdin);
		printf("Digite seu telefone: ");
		scanf("%c[^\n]",&aux->telefone);
		fflush(stdin);
		printf("Digite seu e-mail: ");
		scanf("%c[^\n]",&aux->email);
		fflush(stdin);
		printf("Digite sua cidade: ");
		scanf("%c[^\n]",&aux->cidade);
		fflush(stdin);
		printf("Digite seu estado (dois caracteres): ");
		scanf("%c[^\n]",&aux->estado);
		fflush(stdin);
		aux->atv = 1;
		aux->id = cont;
		cont++;
		a[i] = *(aux);//gravando no vetor
			/*if(i%2==0)
				minha_agenda[i]=c;
			else
				minha_agenda[i]=d;*/	
	}
	menu();
}
void escrita(p a, int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		//(&a[i])->id = cont;
		fflush(stdin);
		printf("\nNome: %s",(&a[i])->nome);
		fflush(stdin);
		printf("\nTelefone: %s",(&a[i])->telefone);
		fflush(stdin);
		printf("\nE-mail: %s",(&a[i])->email);
		fflush(stdin);
		printf("\nCidade: %s",(&a[i])->cidade);
		fflush(stdin);
		printf("\nEstado: %s",(&a[i])->estado);
		fflush(stdin);
		//cont ++;
	}
}

void escrita_nome_ordem_alfa_cres(p a, int tam)
{
	ordena_nome_cresc(a,tam);
	escrita(a,tam);
}
void menuListar(){
	int i;
	
	printf("Listar por:\n");
	printf("1 - Nome ordem alfabética crescente\n");
	printf("2 - Nome ordem alfabética decrescente\n");
	printf("3 - Cidade ordem alfabética crescente\n");
	printf("4 - Cidade ordem alfabética decrescente\n");
	scanf("%d", &i);
	
}

/*void exclui(p *a, int id){
	int i;
	
	for(i=0; i<cont; i++){
		if (*(a)[i]->id) == id
			*(a)[i]->atv = 0
	}
	
}*/
void menu(){
	int i, id;
	p *minha_agenda;
	int tamanho=10;
	int tam;
	minha_agenda = malloc(tamanho*sizeof(p));
	
	
	//printf("Bem vindo!\n\n");
	printf("O que deseja fazer?\n");
	printf("1 - Cadastrar\n");
	printf("2 - Excluir\n");
	printf("3 - Listar\n");
	printf("4 - Buscar\n");
	scanf("%d", &i);
	
	switch(i){
		case 1:
			printf("\nQuantas pessoas deseja cadastrar: ");
			scanf("%d", &tam);
			leitura(minha_agenda, tam);
		break;
		case 2:
			printf("\nExcluir qual pessoa?");
			scanf("%d", &id);
			//exclui(minha_agenda, &id);
		break;
		case 3:
			escrita(minha_agenda, cont);
	}

}

//void escrita(tipo v[],int tamanho);

