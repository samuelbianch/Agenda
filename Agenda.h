//definicao da estrutura
struct pessoa{
	int id;
	char nome[40];
	char telefone[11];
	char email[40];
	char cidade[40]; 
	char estado[2]; 
};

typedef struct pessoa p;//tipo

void leitura(p *a,int tam);
void escrita(p *a,int tam);
void escrita_nome_ordem_alfa_cres(p *a,int tam);
void menu();
