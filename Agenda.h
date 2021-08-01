struct pessoa{
	int id;
	char nome[40];
	char telefone[11];
	char email[40];
	char cidade[40]; 
	char estado[2];
	int atv;
};

void menu();

void cadastrar();

void excluir();

void menuListar();

void exibeListagem();

void ordenaNomeCrescente();

void ordenaNomeDecrescente();

void ordenaEstado(pessoa vetor[], int esq, int dir);

int dividir(pessoa vetor[], int esq, int dir);

void ordenaCidade();

void menuBuscar();


