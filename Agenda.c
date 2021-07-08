#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

int cont=0;

void ordena_nome_cresc(p *a,int tam)
{
	int i,j;
	p aux;
	for(i=0;i<tam-1;i++)
		for(j=i+1;j<tam;j++)
		{
			if(strcmp((&a[i])->nome,(&a[j])->nome)>0)
			{
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		}
	
}
void leitura(p *a, int tam)
{
	p aux;
	int i;
	for(i=0;i<tam;i++)
	{
		printf("Digite seu nome: ");
		scanf("%s",&aux.nome);
		fflush(stdin);
		printf("Digite seu telefone: ");
		scanf("%s",&aux.telefone);
		fflush(stdin);
		printf("Digite seu e-mail: ");
		scanf("%s",&aux.email);
		fflush(stdin);
		printf("Digite sua cidade: ");
		scanf("%s",&aux.cidade);
		fflush(stdin);
		printf("Digite seu estado (dois caracteres): ");
		scanf("%s",&aux.estado);
		fflush(stdin);
		//aux.matricula=i+1;
		a[i]=aux;//gravando no vetor
		/*if(i%2==0)
			minha_agenda[i]=c;
		else
			minha_agenda[i]=d;*/	
	}
}
void escrita(p *a,int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		(&a[i])->id = cont;
		printf("\nNome: %s",(&a[i])->nome);
		printf("\nE-mail: %s",(&a[i])->email);
		printf("\nCidade: %s",(&a[i])->cidade);
		printf("\nEstado: %s",(&a[i])->estado);
		cont ++;
	}
}

void escrita_nome_ordem_alfa_cres(p *a,int tam)
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

void menu(){
	int i;
	p *minha_agenda;
	int tamanho=10;
	int tam;
	minha_agenda = malloc(tamanho*sizeof(p));
	
	printf("Bem vindo!\n\n");
	printf("O que deseja fazer?\n");
	printf("1 - Cadastrar\n");
	printf("2 - Excluir\n");
	printf("3 - Listar\n");
	printf("4 - Buscar\n");
	scanf("%d", &i);
	
	switch(i){
		case 1:
			system("PAUSE");
			printf("Quantas pessoas deseja cadastrar: ");
			scanf("%d", &tam);
			system("PAUSE");
			escrita(*minha_agenda, tam);
	}

}

//void escrita(tipo v[],int tamanho);

