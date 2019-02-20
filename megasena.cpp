#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//Gabriel Fernella RM 12181500708
//Gabriel Tadachi RM12181500722
//Gustavo Felipe RM 12181500809

int main()
{
setlocale(LC_ALL,"portuguese");

int quadra=0,quina=0,cena=0;
int cont=0,pontos=0;
char vnumeros[50][35];
char resultado[35];	
char dez1[6][3];

int vezes[6]{0,0,0,0,0,0};

char dez01[3];
char dez02[3];
char dez03[3];
char dez04[3];
char dez05[3];
char dez06[3];
FILE *mega;
mega = fopen("mega.txt","r");


//==============================================
	printf("=========Programa Mega-Sena===========\n");
	printf("Digite os valores que deseja jogar\n");
	printf("Dezena 01\n");
	fflush(stdin);
	gets(dez1[0]);
	printf("Dezena 02\n");
	fflush(stdin);
	gets(dez1[1]);
	printf("Dezena 03\n");
	fflush(stdin);
	gets(dez1[2]);
	printf("Dezena 04\n");
	fflush(stdin);
	gets(dez1[3]);
	printf("Dezena 05\n");
	fflush(stdin);
	gets(dez1[4]);
	printf("Dezena 06\n");
	fflush(stdin);
	gets(dez1[5]);
	

while (!feof(mega))
{
fgets (resultado,35,mega);
printf("%s",resultado);

dez01[0]=resultado[5];
dez01[1]=resultado[6];
dez01[2]='\0';
dez02[0]=resultado[8];
dez02[1]=resultado[9];
dez02[2]='\0';
dez03[0]=resultado[11];
dez03[1]=resultado[12];
dez03[2]='\0';
dez04[0]=resultado[14];
dez04[1]=resultado[15];
dez04[2]='\0';
dez05[0]=resultado[17];
dez05[1]=resultado[18];
dez05[2]='\0';
dez06[0]=resultado[20];
dez06[1]=resultado[21];
dez06[2]='\0';

pontos=0;
for(int i=0;i<6;i++){
	if(strcmp(dez01,dez1[i])==0 || strcmp(dez02,dez1[i])==0 || strcmp(dez03,dez1[i])==0 || strcmp(dez04,dez1[i])==0 || strcmp(dez05,dez1[i])==0 || strcmp(dez06,dez1[i])==0){
		pontos++;
		vezes[i]++;
	}	
}


if(pontos>3){
	if(pontos==4){
		printf("Você acertou a quadra\n");
		strcpy(vnumeros[cont],resultado);
		cont++;
		quadra++;
	}
	else if(pontos==5){
		printf("Você acertou a quina %s\n");
		strcpy(vnumeros[cont],resultado);
		cont++;
		quina++;
	}
	else if(pontos==6){
		printf("Você acertou a sena\n");
		strcpy(vnumeros[cont],resultado);
		cont++;
		cena++;
	}
}
	pontos=0;
}
fclose(mega);

system("cls");
printf("\nJogos Certos: %d\n",cont);
printf("Quadra %d\n",quadra);
printf("Quina %d\n",quina);
printf("Sena %d\n",cena);
printf("Você acertou os seguintes jogos: \n");
for(int i=0;i<cont;i++){
	printf("%s \n",vnumeros[i]);
}
printf("Seu Jogo: \n");
printf ("\n Dezena 01: %s - QTD= %d",dez1[0],vezes[0]);
printf ("\n Dezena 02: %s - QTD= %d",dez1[1],vezes[1]);
printf ("\n Dezena 03: %s - QTD= %d",dez1[2],vezes[2]);
printf ("\n Dezena 04: %s - QTD= %d",dez1[3],vezes[3]);
printf ("\n Dezena 05: %s - QTD= %d",dez1[4],vezes[4]);
printf ("\n Dezena 06: %s - QTD= %d",dez1[5],vezes[5]);


return(0);
}

















