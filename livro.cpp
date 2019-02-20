#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>

/*EXE Biblioteca */

typedef struct{
	int dia,mes,ano;
	char pessoa[60];
	}data;

typedef struct{
	int codigo;
	char autor[80],title[80];
	char status[15];
	data ret,dev,loaluga,lodevolve;
	}livro;
 livro livros[3];
void aluga(),devolve();
int i =0;

void cadastro(),aluga(),devolve(),relatorio();
int main() {
	

	
	bool tru=true;
	setlocale(LC_ALL, "Portuguese");
	while(tru){
	system("cls");
	int op=0;
	
	printf("Locadora Maluca\n");
	printf("----------------\n\n");
	printf("1 - Cadastrar\n");
	printf("2 - Alugar\n");
	printf("3 - Devolução\n");
	printf("4 - Relatório\n");
	printf("5 - Sair\n");
	
	printf("Digite sua opção: \n\n");
	scanf("%d",&op);
	
	switch(op){
		case 1:
			cadastro();
			break;
		case 2:
			aluga();
			break;	
		case 3:
			devolve();
			break;
		case 4:
			relatorio();
			break;
		case 5:
			tru = false;
			break;
	}
}
	return 0;
}
void cadastro(){
	int cont=0;
	printf("Codigo: \n");
	scanf("%d",&cont);
	livros[cont].codigo = cont;
	printf("Titulo: \n");
	fflush(stdin);
	gets(livros[cont].title);
	printf("Autor: \n");
	fflush(stdin);
	gets(livros[cont].autor);
	
	strcpy(livros[cont].status, "Devolvido");
	livros[cont].ret.dia = 00;
	livros[cont].ret.mes = 00;
	livros[cont].ret.ano = 00;
	
	livros[cont].dev.dia = 00;
	livros[cont].dev.mes = 00;
	livros[cont].dev.ano = 00;
	
	strcpy(livros[cont].loaluga.pessoa, "Nenhum");
	strcpy(livros[cont].lodevolve.pessoa, "Nenhum");
	system("pause");
	
	
}
void aluga(){
	int cont=0;
	printf("Codigo: \n");
	scanf("%d",&cont);
	

	
	if(strcmp(livros[cont].status, "Devolvido") ==0){
		strcpy(livros[cont].status, "Emprestado");
		printf("Nome Locatário : \n");
		fflush(stdin);
		gets(livros[cont].loaluga.pessoa);
		printf("Insira a data de retirada do livro\n");
		scanf("%d",&livros[cont].ret.dia);
		printf("/");
		scanf("%d",&livros[cont].ret.mes);
		printf("/");
		scanf("%d",&livros[cont].ret.ano);
		printf("Produto %s \n\n", livros[i].status);	
		}
	else{
		printf("Produto %s \n\n", livros[i].status);
	}
	system("pause");
}
void devolve(){
	int cont=0;
	printf("Codigo: \n");
	scanf("%d",&cont);
	
	if(strcmp(livros[cont].status, "Emprestado") ==0){
		strcpy(livros[cont].status, "Devolvido");
		printf("Nome Locatário : \n");
		fflush(stdin);
		gets(livros[cont].lodevolve.pessoa);
		printf("Data de devolução\n");
		scanf("%d",&livros[cont].dev.dia);
		printf("/");
		scanf("%d",&livros[cont].dev.mes);
		printf("/");
		scanf("%d",&livros[cont].dev.ano);
		printf("Produto %s \n\n", livros[i].status);
		}
	else{
		printf("Produto %s \n\n", livros[i].status);
	}
	system("pause");	
}
void relatorio(){
	int busca;
			printf("Digite o codigo do livro para buscar o relatório: ");
			scanf("%d",&busca);
			printf("\n\nRelatório \n");
			printf("Codigo Numero: %d \n",livros[busca].codigo);
			printf("Titulo: %s \n",livros[busca].title);
			printf("Autor: %s \n",livros[busca].autor);
			printf("Status: %s \n",livros[busca].status);
			printf("Ultimo Locatário a alugar: %s \n",livros[busca].loaluga.pessoa);
			printf("data da ultima retirada: %d/%d/%d \n",livros[busca].ret.dia,livros[busca].ret.mes,livros[busca].ret.ano);
			printf("Ultimo Locatário a devolver: %s \n",livros[busca].lodevolve.pessoa);
			printf("data da ultima devolução: %d/%d/%d \n",livros[busca].dev.dia,livros[busca].dev.mes,livros[busca].dev.ano);
			
			system("pause");
	
}
