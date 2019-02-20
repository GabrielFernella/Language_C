#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

void troca(int a,int base, char b[]){
	itoa(a,b,base);
}


main (){

int a; char b[99];
int base;
printf("Digite um numero em decimal:");
scanf("%d",&a);
itoa(a,b,3);
printf("O numero %d em binario e: %s",a,b);
printf("insira a base: ");
scanf("%d",&base);
troca(a,base,b);
printf("O numero %d em binario e: %s",a,b);

getch();

}


