#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//==================NSA em C====================

typedef struct{
	char nome[50],materia[30];
	float m1=0,m2=0,media=0,extra=0;
	char status[20];
	int passaram=0,reprovaram=0;
}nsa;
nsa aluno[3];

typedef struct{
	float mb=8,b=6,r=4.5,i=3;
	
}Valornota;
Valornota nota;

void alunocadastrado(),valornotas(),alunosaprovados(),relatorio(),alunosreprovado(),exame();
int i=1;
int main() {
		int op=0;
		bool tru= true;
		setlocale(LC_ALL,"portuguese");
		
	while(tru){
		system("cls");
		printf("\nNSA esperto do Fernella\n");
		printf("=======================\n\n");
		printf("Digite sua opção: \n");
		printf("1 - Cadastre o aluno e insira suas respectivas notas\n");
		printf("2 - Atribua a variavel de notas de sua preferência\n");	
		printf("3 - Quantos alunos Passaram? \n");	
		printf("4 - Quantos alunos Reprovaram? \n");
		printf("5 - Exame\n");
		printf("6 - Relatório de alunos\n");
		printf("7 - Sair do sistema\n");
		scanf("%d",&op);	
		
		switch(op){
			case 1:
				system("cls");
				alunocadastrado();
				break;
			case 2:
				system("cls");
				valornotas();
				break;
			case 3:
				system("cls");
				alunosaprovados();
				break;
			case 4:
				system("cls");
				alunosreprovado();
				break;
			case 5:
				system("cls");
				exame();
				break;
			case 6:
				system("cls");
				relatorio();
				break;
			case 7:
				tru = false;
				break;
		}
	}
	
	return 0;
}

void alunocadastrado(){
	
	printf("Nome do individuo: \n");
	fflush(stdin);
	gets(aluno[i].nome);
	printf("Matéria: \n");
	fflush(stdin);
	gets(aluno[i].materia);
	printf("Nota M1: \n");
	scanf("%f",&aluno[i].m1);
	printf("Nota M2: \n");
	scanf("%f",&aluno[i].m2);
	
	aluno[i].media = (aluno[i].m1 + aluno[i].m2)/2;
	if(aluno[i].media>=nota.mb){
		printf("Ele Passou com MB, Parabéns pelo trabalho professor.\n");
		strcpy(aluno[i].status, "Aprovado");
		aluno[i].passaram++;
	}
	else if(aluno[i].media>=nota.b){
		printf("Ele Passou com B, Está indo bem.\n");
		strcpy(aluno[i].status, "Aprovado");
		aluno[i].passaram++;
	}
	else if(aluno[i].media>=nota.r){
		printf("Ele Passou com R, mas precisa melhorar.\n");
		strcpy(aluno[i].status, "Aprovado");
		aluno[i].passaram++;
	}
	else if(aluno[i].media>=nota.i){
		printf("Ele Reprovou com I, parece que não foi dessa vez.\n");
		strcpy(aluno[i].status, "Reprovado");
		aluno[i].reprovaram++;
	}
	printf("Status do aluno %s\n", aluno[i].status);
	printf("Media do aluno %f\n", aluno[i].media);
	
	i++;
	system("pause");
}

void valornotas(){
	
	printf("Altere o valor máximo das notas\n\n");
	printf("Por padrão os valores são:  \n mb=8,\nb=6,\nr=4.5,\ni=3  \n\n");
	
	printf("MB = \n");
	scanf("%f",nota.mb);
	printf("B = \n");
	scanf("%f",nota.b);
	printf("R = \n");
	scanf("%f",nota.r);
	printf("I = \n");
	scanf("%f",nota.i);
}

void alunosaprovados(){
	printf("Alunos Aprovados: \n");
	for(int j=1;j<=i;j++){
	if(strcmp(aluno[j].status, "Aprovado" )==0){
	printf(" Aluno %d : %s \t %s \n",j,aluno[j].nome,aluno[j].status);
	printf("-----------------------------------------------------------------------------\n");
		}
	}
	system("pause");
	
}
void alunosreprovado(){
	printf("Alunos Reprovados: \n");
	for(int j=1;j<=i;j++){
	if(strcmp(aluno[j].status, "Reprovado" )==0){
	printf(" Aluno %d : %s \t %s \n",j,aluno[j].nome,aluno[j].status);
	printf("-----------------------------------------------------------------------------\n");
		}
	}
	system("pause");
	
}

void relatorio(){
	printf("Alunos Aprovados: \n");
	for(int j=1;j<=i;j++){

	printf(" Aluno %d : %s \t %s \n",j,aluno[j].nome,aluno[j].status);
	printf("-----------------------------------------------------------------------------\n");
		
	}
	system("pause");
	
}
void exame(){
	printf("Aluno de exame: \n");
	for(int j=0;j<=i;j++){
	if(strcmp(aluno[j].status, "Reprovado" )==0){
	
	printf(" Aluno %d : %s \t %s \n",j,aluno[j].nome,aluno[j].status);
	printf("Nota Exame: \n");
	scanf("%f",&aluno[j].extra);
	
	aluno[j].media = (aluno[j].m1 + aluno[j].m2+aluno[j].extra)/3;
	
	if(aluno[j].media>=nota.mb){
		printf("Ele Passou com MB, Parabéns pelo trabalho professor.\n");
		strcpy(aluno[j].status, "Aprovado");
		aluno[j].passaram++;
	}
	else if(aluno[j].media>=nota.b){
		printf("Ele Passou com B, Está indo bem.\n");
		strcpy(aluno[j].status, "Aprovado");
		aluno[j].passaram++;
	}
	else if(aluno[j].media>=nota.r){
		printf("Ele Passou com R, mas precisa melhorar.\n");
		strcpy(aluno[j].status, "Aprovado");
		aluno[j].passaram++;
	}
	else if(aluno[j].media>=nota.i){
		printf("Ele Reprovou com I, parece que não foi dessa vez.\n");
		strcpy(aluno[j].status, "Reprovado");
		aluno[j].reprovaram++;
	}
		}
	}
	
	system("pause");
	
}































