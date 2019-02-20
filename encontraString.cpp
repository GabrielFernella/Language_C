#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void localizar(char frase[], char palavra[], int quantidade, int *posicao){
	int qtdPalavra = strlen(palavra);
	
	int achoQtd;
	int auxQtd;
	
	for(int i = 0; i < quantidade; i++){
		achoQtd = 0;
		auxQtd = 0;
		if(frase[i] == palavra[0]){
			auxQtd = i;
			for(int j = 0; j < qtdPalavra; j++){
				if(frase[auxQtd] == palavra[j]){
					achoQtd++;
				}
				auxQtd++;
			}
		}
		*posicao = i;
		if(qtdPalavra == achoQtd){
			break;
		}
	}
	
}
main(){
	int quantidade = 20;
	
	char frase[quantidade];
	char palavra[quantidade];
	
	int posicao;
	
	strcpy(frase, "amor");
	strcpy(palavra, "mo");
	
	localizar(frase, palavra, quantidade, &posicao);
	
	posicao++;
	
	int auxQtd = strlen(palavra);
	
	printf("A variavel esta nas posicoes: ");
	for(int i = 0; i < auxQtd; i++){
		printf("%d ", posicao);
		posicao++;
	}
}
