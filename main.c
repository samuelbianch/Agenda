#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"

int main(int argc, char *argv[]) {
	p minha_agenda;
	int tamanho=10;
	minha_agenda = malloc(tamanho*sizeof(p));
	
	menu(minha_agenda);
	return 0;
}
