//definicao da estrutura
struct pessoa{
	int id;
	char nome[40];
	char telefone[11];
	char email[40];
	char cidade[40]; 
	char estado[2];
	int atv;
};

typedef struct pessoa *p;//tipo

void leitura(p a,int tam);
void escrita(p a);
void escrita_nome_ordem_alfa_cres(p a,int tam);
void exclui(p a, int id);
void menu(p minha_agenda);
void busca(p a);
