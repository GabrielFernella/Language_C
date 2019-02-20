#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void troca(float *a, float* b){
	float aux1, aux2;
	aux1 = *a;
	aux2 = *b;
	
	*a = aux2;
	*b = aux1;	
}

main(){
	float n1,n2;
	printf("Escreva uma função chamada troca que troca os valores dos /nparâmetros recebidos. Sua assinatura deve ser:\nvoid troca(float *a, float *b);");
	printf("\nValor n1: ");
	scanf("%f",&n1);
	printf("\nValor n2: \n");
	scanf("%f",&n2);
	
	printf("\n n1 antes: %f",n1);
	printf("\n n2 antes: %f",n2);
	
	troca(&n1,&n2);
	
	printf("\n n1 depois: %f",n1);
	printf("\n n2 depois: %f",n2);
	
}
