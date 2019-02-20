#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

//GABRIEL FERNELLA

int cadastroDozinferno(), consultaDozinferno(), estoqueDozinferno(), descricaoDozinferno(), relatorioDozInferno();
float calcularTotal(int qtdEstoque, float preco);
int entradaDozinferno(), saidaDozinferno(), alteracaoDozinferno(), alterarDozinferno(), exclusaoDozinferno();
int cod = 0;
bool tru = true;

int codigo[10], quantidade[10], quantidadeMinima[10];
char descricao[10][50], desejaContinuar[2];
float precoUnitario[10], precoTotal[10];

int main () {
	setlocale(LC_ALL, "Portuguese");
	while(tru) {
		char sair[2];
		int op = 0, cod = 1;
		system("cls");

		printf("Programa Magnifico do Titio Fernando\n");
		printf("1 - Cadastro\n");
		printf("2 - Consulta\n");
		printf("3 - Altera��o\n");
		printf("4 - Exclus�o\n");
		printf("5 - Relat�rio\n");
		printf("6 - Fim\n");
		printf("Insira sua Op��o: ");
		fflush(stdin);
		scanf("%d", &op);

		switch(op) {
			case 1:
				system("cls");
				cadastroDozinferno();
				break;
			case 2:
				system("cls");
				consultaDozinferno();
				break;
			case 3:
				system("cls");
				alteracaoDozinferno();
				break;
			case 4:
				system("cls");
				exclusaoDozinferno();
				break;
			case 5:
				system("cls");
				relatorioDozInferno();
				break;
			case 6:
				printf("Deseja mesmo sair? S - Sim, N - N�o: ");
				fflush(stdin);
				gets(sair);
				if(strcmp(sair, "S") == 0 || strcmp(sair, "s") == 0) {
					tru = false;
				}
				break;
			default:
				printf("Op��o Inv�lida!\n");
				system("pause");
				break;
		}
	}
}

void gotoXY(int x, int y){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

float calcularTotal(int qtdEstoque, float preco){
	return preco * qtdEstoque;
}

int cadastroDozinferno() {
	printf("---Op��o 1 - Cadastro de Produtos---\n");
	char resp[2];
	bool correto = false;

	while(tru) {
		codigo[cod] = cod;
		printf("C�digo: %d\n", codigo[cod]+1);

		printf("Insira a Descri��o do Produto: ");
		fflush(stdin);
		gets(descricao[cod]);
		while(strcmp(descricao[cod], "\0") == 0) {
			printf("Descri��o Incorreta!\nInsira a Descri��o do Produto: ");
			fflush(stdin);
			gets(descricao[cod]);
		}

		printf("Insira a Quantidade: ");
		fflush(stdin);
		scanf("%d", &quantidade[cod]);
		while(quantidade[cod] <= 0) {
			printf("Quantidade Inv�lida!\nInsira a Quantidade: ");
			scanf("%d", &quantidade[cod]);
		}

		printf("Insira a Quantidade M�nima: ");
		fflush(stdin);
		scanf("%d", &quantidadeMinima[cod]);
		while(quantidadeMinima[cod] <= 0 || quantidadeMinima[cod] > quantidade[cod]) {
			printf("Quantidade Inv�lida!\nInsira a Quantidade M�nima: ");
			scanf("%d", &quantidadeMinima[cod]);
		}

		printf("Insira o Pre�o Unit�rio: ");
		fflush(stdin);
		scanf("%f", &precoUnitario[cod]);
		while(precoUnitario[cod] <= 0) {
			printf("Pre�o Inv�lido!\nInsira o Pre�o Unit�rio: ");
			scanf("%f", &precoUnitario[cod]);
		}

		float precoMagico = calcularTotal(quantidade[cod],precoUnitario[cod]);
		precoTotal[cod] = precoMagico;
		printf("Pre�o Total: %f\n", precoTotal[cod]);

		printf("\n---CONFIRE OS DADOS!---\n");
		printf("C�digo - %d\nDescri��o - %s\nQuantidade - %d\nQuantidade M�nima - %d\nPre�o Unit�rio - %f\nPre�o Total - %f", codigo[cod]+1,descricao[cod],quantidade[cod],quantidadeMinima[cod],precoUnitario[cod],precoTotal[cod]);
		printf("\nOs Dados est�o Corretos? S/N: ");
		fflush(stdin);
		gets(resp);
		if(strcmp(resp, "S") == 0 || strcmp(resp, "s") == 0) {
			correto = true;
		} else {
			correto = false;
			system("cls");
			printf("---Op��o 1 - Cadastro de Produtos---\n");
		}

		if(correto) {
			printf("Deseja continuar? S - Sim, N - N�o: ");
			fflush(stdin);
			gets(desejaContinuar);
			if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
				tru = false;
			}
			system("cls");
			printf("---Op��o 1 - Cadastro de Produtos---\n");
			cod++;
		}
	}
	tru = true;
	return cod;
}

int consultaDozinferno() {
	bool tru = true;
	while(tru) {
		int op = 0;
		printf("---Tela Consulta---\n");
		printf("1 - Entrada / Sa�da\n");
		printf("2 - Consulta\n");
		printf("3 - Voltar\n");
		printf("Insira sua Op��o: ");
		
		fflush(stdin);
		scanf("%d", &op);

		switch(op) {
			case 1:
				system("cls");
				estoqueDozinferno();
				break;
			case 2:
				system("cls");
				descricaoDozinferno();
				break;
			case 3:
				system("cls");
				tru = false;
				break;
				break;
			default:
				printf("Op��o Inv�lida!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	tru = true;
	return 0;
}

int estoqueDozinferno() {
	while(tru) {
		int op = 0;
		printf("---Entrada e Sa�da de Estoque---\n");
		printf("1 - Entrada\n");
		printf("2 - Sa�da\n");
		printf("3 - Voltar\n");
		printf("Insira sua Op��o: ");
		
		fflush(stdin);
		scanf("%d", &op);

		switch(op) {
			case 1:
				system("cls");
				entradaDozinferno();
				break;
			case 2:
				system("cls");
				saidaDozinferno();
				break;
			case 3:
				system("cls");
				tru = false;
				break;
			default:
				printf("Op��o Inv�lida!\n");
				system("pause");
				system("cls");
				break;
		}
	}
	tru = true;
	return 0;
}

int entradaDozinferno() {
	int codigoEntrada = 0, qtdEntrada = 0;

	while(tru) {
		printf("---Entrada de Produtos---\n");
		printf("Insira o C�digo do Produto: ");
		fflush(stdin);
		scanf("%d", &codigoEntrada);

		if(!(codigoEntrada > cod) && descricao[codigoEntrada - 1][0] != '\0') {
			codigoEntrada--;
			printf("===PRODUTO %s===\n Quantidade atual � %d\nQuantos '%s' voc� deseja inserir?\n", descricao[codigoEntrada], quantidade[codigoEntrada], descricao[codigoEntrada]);
			fflush(stdin);
			scanf("%d", &qtdEntrada);
			if(!(qtdEntrada < 0)) {
				quantidade[codigoEntrada] += qtdEntrada;

				float precoMagico = calcularTotal(quantidade[codigoEntrada],precoUnitario[codigoEntrada]);
				precoTotal[codigoEntrada] = precoMagico;				

				printf("A quantidade de '%s' �: %d\n", descricao[codigoEntrada], quantidade[codigoEntrada] );

				if(quantidade[codigoEntrada] < quantidadeMinima[codigoEntrada]) {
					printf("ALERTA!!! '%s' est� numa quantidade menor do que a m�nima!!!\nQuantidade M�nima = %d\n", descricao[codigoEntrada], quantidadeMinima[codigoEntrada]);
				}

				printf("Deseja continuar? S - Sim, N - N�o: ");
				fflush(stdin);
				gets(desejaContinuar);
				if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
					tru = false;
				}
				system("cls");
			} else{
				("Quantidade Incorreta! ");
				system("pause");
				system("cls");
			}
		} else if(codigoEntrada == 0){
			system("cls");
			return 0;
		} 
		else {
			printf("C�digo Incorreto! ");
			system("pause");
			system("cls");
		}
	}
	tru = true;
	return 0;
}

int saidaDozinferno() {
	int codigoSaida = 0, qtdSaida = 0;

	while(tru) {
		printf("---Sa�da de Produtos---\n");
		printf("Insira o C�digo do Produto: ");
		fflush(stdin);
		scanf("%d", &codigoSaida);

		if(!(codigoSaida > cod) && descricao[codigoSaida - 1][0] != '\0') {
			codigoSaida--;
			printf("===PRODUTO %s===\nA Quantidade atual � %d\nQuantos '%s' voc� deseja retirar?\n", descricao[codigoSaida], quantidade[codigoSaida], descricao[codigoSaida]);
			fflush(stdin);
			scanf("%d", &qtdSaida);
			if(qtdSaida > 0 && qtdSaida <= quantidade[codigoSaida] ) {
				quantidade[codigoSaida] -= qtdSaida;

				float precoMagico = calcularTotal(quantidade[codigoSaida],precoUnitario[codigoSaida]);
				precoTotal[codigoSaida] = precoMagico;

				printf("A quantidade de '%s' �: %d\n", descricao[codigoSaida], quantidade[codigoSaida] );

				if(quantidade[codigoSaida] < quantidadeMinima[codigoSaida]) {
					printf("\n\nALERTA!!! '%s' est� numa quantidade menor do que a m�nima!!!\nQuantidade M�nima = %d\n\n\n", descricao[codigoSaida], quantidadeMinima[codigoSaida]);
				}

				printf("Deseja continuar? S - Sim, N - N�o: ");
				fflush(stdin);
				gets(desejaContinuar);
				if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
					tru = false;
				}
				system("cls");
			} else {
				printf("Quantidade Incorreta, ou Produto Esgotado! ");
				system("pause");
				system("cls");
			}
		} else if(codigoSaida == 0){
			system("cls");
			return 0;
		}
		else {
			printf("C�digo Incorreto! ");
			system("pause");
			system("cls");
		}
	}
	tru = true;
	return 0;
}

int descricaoDozinferno() {
	char produtoPesquisa[50];
	while(tru) {
		bool achou = false;
		printf("---Pesquisa por Descri��o---\n");
		printf("Insira a Descri��o do Produto que voc� deseja: ");
		fflush(stdin);
		gets(produtoPesquisa);

		for(int i = 0; i < cod; i++) {
			if(strcmp(produtoPesquisa, descricao[i]) == 0 ){
				printf("=== PRODUTO %s ===\n", descricao[i]);
				printf("C�digo - %d\n", codigo[i] + 1);
				printf("Pre�o Unit�rio - %f\n", precoUnitario[i]);
				printf("Quantidade em Estoque - %d\n", quantidade[i]);
				printf("Quantidade M�nima - %d\n", quantidadeMinima[i]);
				printf("Pre�o Total em Estoque - %f\n", precoTotal[i]);
				achou = true;
				break;
			}
		}

		if(!achou) {
			printf("Produto n�o encontrado!\n");
		}

		printf("Deseja continuar? S - Sim, N - N�o: ");
		fflush(stdin);
		gets(desejaContinuar);
		if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
			tru = false;
		}
		system("cls");
	}
	tru = true;
	return 0;
}

int alteracaoDozinferno(){
	while(tru) {
		int opcao = 0, alterar = 0;
		printf("---Altera��o de Registros---\n");
		for(int i = 0; i < cod; i++){
			if(strcmp(descricao[i], "\0") != 0){
				printf("%d - %s\n", i + 1, descricao[i]);
			}			
		}
		printf("0 - Retornar\n");
		
		while(true){
			printf("Insira sua Op��o: ");
			fflush(stdin);
			scanf("%d", &opcao);
			
			if(opcao <= cod && descricao[opcao - 1][0] != '\0' != 0){
				break;
			}
			else if(opcao == 0){
				return 0;
			}
			else{
				printf("Op��o Inv�lida!\n");
			}
		}
		system("cls");
		printf("===%s===\n", descricao[opcao - 1]);
		printf("1 - [%s] - Descri��o\n", descricao[opcao - 1]);
		printf("2 - [%d] - Quantidade Estoque\n", quantidade[opcao - 1]);
		printf("3 - [%d] - Quantidade M�nima\n", quantidadeMinima[opcao - 1]);
		printf("4 - [%f] - Pre�o Unit�rio\n", precoUnitario[opcao - 1]);
		printf("- [%f] - Pre�o Total\n", precoTotal[opcao - 1]);
		printf("0 - Retornar\n", precoTotal[opcao - 1]);
		
		char descNova[50];
		char decisao[2];
		int qtdNova = 0, minNova = 0;
		float precoNovo = 0;
		
		printf("Insira o N�mero para editar o campo correspondente: ");
		fflush(stdin);
		scanf("%d", &alterar);	
			
		switch(alterar){
			case 1:
				while(true){
					printf("Insira a Descri��o que voc� deseja: ");
					fflush(stdin);
					gets(descNova);
					printf("A Descri��o [%s] est� correta? Ela substituir� a Descri��o Atual [%s]! S/N ", descNova, descricao[opcao - 1]);
					fflush(stdin);
					gets(decisao);
					if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
						strcpy(descricao[opcao - 1], descNova);
						break;
					}
				}				
			break;
			
			case 2:
				while(true){
					printf("Insira a Quantidade que voc� deseja: ");
					fflush(stdin);
					scanf("%d", &qtdNova);
					printf("A Quantidade de %d est� correta? Ela substituir� a Quantidade Atual [%d]! S/N ", qtdNova, quantidade[opcao - 1]);
					fflush(stdin);
					gets(decisao);
					if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
						quantidade[opcao - 1] = qtdNova;
						precoTotal[opcao - 1] = calcularTotal(quantidade[opcao - 1],precoUnitario[opcao - 1]);
						break;
					}
				}				
			break;
			
			case 3:
				while(true){
					printf("Insira a Quantidade M�nima que voc� deseja: ");
					fflush(stdin);
					scanf("%d", &minNova);
					printf("A Quantidade M�nima de %d est� correta? Ela substituir� a Quantidade M�nima Atual [%d]! S/N ", minNova, quantidadeMinima[opcao - 1]);
					fflush(stdin);
					gets(decisao);
					if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
						quantidadeMinima[opcao - 1] = minNova;
						
						if(quantidade[opcao - 1] < quantidadeMinima[opcao - 1]) {
							printf("ALERTA!!! '%s' est� numa quantidade menor do que a m�nima!!!\nQuantidade M�nima = %d\n", descricao[opcao - 1], quantidadeMinima[opcao - 1]);
						}
						break;
					}
				}
			break;
			
			case 4:
				while(true){
					printf("Insira o Pre�o que voc� deseja: ");
					fflush(stdin);
					scanf("%f", &precoNovo);
					printf("O Pre�o [%f] est� correto? Ele substituir�o Pre�o Atual [%f]! S/N ", precoNovo, precoUnitario[opcao - 1]);
					fflush(stdin);
					gets(decisao);
					if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
						precoUnitario[opcao - 1] = precoNovo;
						precoTotal[opcao - 1] = calcularTotal(quantidade[opcao - 1],precoUnitario[opcao - 1]);
						break;
					}
				}				
			break;
			
			case 0:
				return 0;
			break;
			
			default:
				printf("Op��o Inv�lida!\n");
			break;
		}	
		
		printf("Deseja continuar? S - Sim, N - N�o: ");
		fflush(stdin);
		gets(desejaContinuar);
		if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
			tru = false;
		}
		system("cls");
	}
	tru = true;
	return 0;
}

int exclusaoDozinferno(){
	char decisao[2];
	while(tru) {
		int opcao = 0;
		printf("---Exclus�o de Registros---\n");
		for(int i = 0; i < cod; i++){
			if(strcmp(descricao[i], "\0") != 0){
				printf("%d - %s\n", i + 1, descricao[i]);
			}			
		}
		printf("0 - Retornar\n");
		
		while(true){
			printf("Insira o C�digo que voc� deseja: ");
			fflush(stdin);
			scanf("%d", &opcao);
					
			if(opcao <= cod && descricao[opcao - 1][0] != '\0'){
				break;
			}
			else if(opcao == 0){
				return 0;
			}
			else{
				printf("Op��o Inv�lida!\n");
			}
		}
		
		system("cls");
		printf("===%s===\n", descricao[opcao - 1]);
		printf("[%s] - Descri��o\n", descricao[opcao - 1]);
		printf("[%d] - Quantidade Estoque\n", quantidade[opcao - 1]);
		printf("[%d] - Quantidade M�nima\n", quantidadeMinima[opcao - 1]);
		printf("[%f] - Pre�o Unit�rio\n", precoUnitario[opcao - 1]);
		printf("[%f] - Pre�o Total\n", precoTotal[opcao - 1]);
		printf("Voc� deseja MESMO exclu�r? S/N ");
		fflush(stdin);
		gets(decisao);
		if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
			descricao[opcao - 1][0] = '\0';
			quantidade[opcao - 1] = 0;
			quantidadeMinima[opcao - 1] = 0;
			precoTotal[opcao - 1] = 0;
			precoUnitario[opcao - 1] = 0;
			printf("Produto Exclu�do com Sucesso!\n");
		}
		
		printf("Deseja continuar? S - Sim, N - N�o: ");
		fflush(stdin);
		gets(desejaContinuar);
		if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
			tru = false;
		}
		system("cls");
	}
	tru = true;
	return 0;
}

int relatorioDozInferno(){
	int op = 0;
	while (tru){
		printf("---Relat�rios---\n");
		printf("1 - Relat�rio de Produtos abaixo da Quantidade M�nima\n");
		printf("2 - Relat�rio de Produtos\n");
		printf("0 - Retornar ao Menu\n");
		printf("Insira sua opc�o: ");
		scanf("%d", &op);	
		
		float precoBalanco = 0;
		int quantidadeBalanco = 0;
			
		switch(op){
			case 1:
				system("cls");
				printf("Descri��o - Quantidade Estoque - Quantidade M�nima\n");
				for(int i = 0, caso = 0; i < cod; i++){
					if(quantidade[i] < quantidadeMinima[i]){
						gotoXY(0, caso + 2); printf("%s", descricao[i]);
						gotoXY(10, caso + 2); printf(" - %d", quantidade[i]);
						gotoXY(31, caso + 2); printf(" - %d", quantidadeMinima[i]);
						
						printf("\n");
						caso++;
					}
				}
			break;
			
			case 2:
				system("cls");
				printf("Descri��o - Pre�o - Quantidade Estoque - Quantidade M�nima - Pre�o Total\n");
				for(int i = 0; i < cod; i++){
					gotoXY(0, i + 2); printf("%s", descricao[i]);
					gotoXY(10, i + 2); printf(" - %f", precoUnitario[i]);
					gotoXY(18, i + 2); printf(" - %d", quantidade[i]);
					gotoXY(39, i + 2); printf(" - %d", quantidadeMinima[i]);
					gotoXY(59, i + 2); printf(" - %f", precoTotal[i]);
					printf("\n");
					
					precoBalanco += precoTotal[i];
					quantidadeBalanco += quantidade[i];
				}
				printf("\n\nPre�o Total: %f - Quantidade Total: %d", precoBalanco, quantidadeBalanco);
			break;
			
			case 0:
				return 0;
			break;
			
			default:
				printf("Op��o Inv�lida!\n");
			break;
		}	
		
		printf("\n\nDeseja continuar? S - Sim, N - N�o: ");
		fflush(stdin);
		gets(desejaContinuar);
		if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
			tru = false;
		}
		system("cls");
	}
	tru = true;
	return 0;
}

