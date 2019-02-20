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
		printf("3 - Alteração\n");
		printf("4 - Exclusão\n");
		printf("5 - Relatório\n");
		printf("6 - Fim\n");
		printf("Insira sua Opção: ");
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
				printf("Deseja mesmo sair? S - Sim, N - Não: ");
				fflush(stdin);
				gets(sair);
				if(strcmp(sair, "S") == 0 || strcmp(sair, "s") == 0) {
					tru = false;
				}
				break;
			default:
				printf("Opção Inválida!\n");
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
	printf("---Opção 1 - Cadastro de Produtos---\n");
	char resp[2];
	bool correto = false;

	while(tru) {
		codigo[cod] = cod;
		printf("Código: %d\n", codigo[cod]+1);

		printf("Insira a Descrição do Produto: ");
		fflush(stdin);
		gets(descricao[cod]);
		while(strcmp(descricao[cod], "\0") == 0) {
			printf("Descrição Incorreta!\nInsira a Descrição do Produto: ");
			fflush(stdin);
			gets(descricao[cod]);
		}

		printf("Insira a Quantidade: ");
		fflush(stdin);
		scanf("%d", &quantidade[cod]);
		while(quantidade[cod] <= 0) {
			printf("Quantidade Inválida!\nInsira a Quantidade: ");
			scanf("%d", &quantidade[cod]);
		}

		printf("Insira a Quantidade Mínima: ");
		fflush(stdin);
		scanf("%d", &quantidadeMinima[cod]);
		while(quantidadeMinima[cod] <= 0 || quantidadeMinima[cod] > quantidade[cod]) {
			printf("Quantidade Inválida!\nInsira a Quantidade Mínima: ");
			scanf("%d", &quantidadeMinima[cod]);
		}

		printf("Insira o Preço Unitário: ");
		fflush(stdin);
		scanf("%f", &precoUnitario[cod]);
		while(precoUnitario[cod] <= 0) {
			printf("Preço Inválido!\nInsira o Preço Unitário: ");
			scanf("%f", &precoUnitario[cod]);
		}

		float precoMagico = calcularTotal(quantidade[cod],precoUnitario[cod]);
		precoTotal[cod] = precoMagico;
		printf("Preço Total: %f\n", precoTotal[cod]);

		printf("\n---CONFIRE OS DADOS!---\n");
		printf("Código - %d\nDescrição - %s\nQuantidade - %d\nQuantidade Mínima - %d\nPreço Unitário - %f\nPreço Total - %f", codigo[cod]+1,descricao[cod],quantidade[cod],quantidadeMinima[cod],precoUnitario[cod],precoTotal[cod]);
		printf("\nOs Dados estão Corretos? S/N: ");
		fflush(stdin);
		gets(resp);
		if(strcmp(resp, "S") == 0 || strcmp(resp, "s") == 0) {
			correto = true;
		} else {
			correto = false;
			system("cls");
			printf("---Opção 1 - Cadastro de Produtos---\n");
		}

		if(correto) {
			printf("Deseja continuar? S - Sim, N - Não: ");
			fflush(stdin);
			gets(desejaContinuar);
			if(strcmp(desejaContinuar, "N") == 0 || strcmp(desejaContinuar, "n") == 0) {
				tru = false;
			}
			system("cls");
			printf("---Opção 1 - Cadastro de Produtos---\n");
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
		printf("1 - Entrada / Saída\n");
		printf("2 - Consulta\n");
		printf("3 - Voltar\n");
		printf("Insira sua Opção: ");
		
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
				printf("Opção Inválida!\n");
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
		printf("---Entrada e Saída de Estoque---\n");
		printf("1 - Entrada\n");
		printf("2 - Saída\n");
		printf("3 - Voltar\n");
		printf("Insira sua Opção: ");
		
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
				printf("Opção Inválida!\n");
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
		printf("Insira o Código do Produto: ");
		fflush(stdin);
		scanf("%d", &codigoEntrada);

		if(!(codigoEntrada > cod) && descricao[codigoEntrada - 1][0] != '\0') {
			codigoEntrada--;
			printf("===PRODUTO %s===\n Quantidade atual é %d\nQuantos '%s' você deseja inserir?\n", descricao[codigoEntrada], quantidade[codigoEntrada], descricao[codigoEntrada]);
			fflush(stdin);
			scanf("%d", &qtdEntrada);
			if(!(qtdEntrada < 0)) {
				quantidade[codigoEntrada] += qtdEntrada;

				float precoMagico = calcularTotal(quantidade[codigoEntrada],precoUnitario[codigoEntrada]);
				precoTotal[codigoEntrada] = precoMagico;				

				printf("A quantidade de '%s' é: %d\n", descricao[codigoEntrada], quantidade[codigoEntrada] );

				if(quantidade[codigoEntrada] < quantidadeMinima[codigoEntrada]) {
					printf("ALERTA!!! '%s' está numa quantidade menor do que a mínima!!!\nQuantidade Mínima = %d\n", descricao[codigoEntrada], quantidadeMinima[codigoEntrada]);
				}

				printf("Deseja continuar? S - Sim, N - Não: ");
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
			printf("Código Incorreto! ");
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
		printf("---Saída de Produtos---\n");
		printf("Insira o Código do Produto: ");
		fflush(stdin);
		scanf("%d", &codigoSaida);

		if(!(codigoSaida > cod) && descricao[codigoSaida - 1][0] != '\0') {
			codigoSaida--;
			printf("===PRODUTO %s===\nA Quantidade atual é %d\nQuantos '%s' você deseja retirar?\n", descricao[codigoSaida], quantidade[codigoSaida], descricao[codigoSaida]);
			fflush(stdin);
			scanf("%d", &qtdSaida);
			if(qtdSaida > 0 && qtdSaida <= quantidade[codigoSaida] ) {
				quantidade[codigoSaida] -= qtdSaida;

				float precoMagico = calcularTotal(quantidade[codigoSaida],precoUnitario[codigoSaida]);
				precoTotal[codigoSaida] = precoMagico;

				printf("A quantidade de '%s' é: %d\n", descricao[codigoSaida], quantidade[codigoSaida] );

				if(quantidade[codigoSaida] < quantidadeMinima[codigoSaida]) {
					printf("\n\nALERTA!!! '%s' está numa quantidade menor do que a mínima!!!\nQuantidade Mínima = %d\n\n\n", descricao[codigoSaida], quantidadeMinima[codigoSaida]);
				}

				printf("Deseja continuar? S - Sim, N - Não: ");
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
			printf("Código Incorreto! ");
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
		printf("---Pesquisa por Descrição---\n");
		printf("Insira a Descrição do Produto que você deseja: ");
		fflush(stdin);
		gets(produtoPesquisa);

		for(int i = 0; i < cod; i++) {
			if(strcmp(produtoPesquisa, descricao[i]) == 0 ){
				printf("=== PRODUTO %s ===\n", descricao[i]);
				printf("Código - %d\n", codigo[i] + 1);
				printf("Preço Unitário - %f\n", precoUnitario[i]);
				printf("Quantidade em Estoque - %d\n", quantidade[i]);
				printf("Quantidade Mínima - %d\n", quantidadeMinima[i]);
				printf("Preço Total em Estoque - %f\n", precoTotal[i]);
				achou = true;
				break;
			}
		}

		if(!achou) {
			printf("Produto não encontrado!\n");
		}

		printf("Deseja continuar? S - Sim, N - Não: ");
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
		printf("---Alteração de Registros---\n");
		for(int i = 0; i < cod; i++){
			if(strcmp(descricao[i], "\0") != 0){
				printf("%d - %s\n", i + 1, descricao[i]);
			}			
		}
		printf("0 - Retornar\n");
		
		while(true){
			printf("Insira sua Opção: ");
			fflush(stdin);
			scanf("%d", &opcao);
			
			if(opcao <= cod && descricao[opcao - 1][0] != '\0' != 0){
				break;
			}
			else if(opcao == 0){
				return 0;
			}
			else{
				printf("Opção Inválida!\n");
			}
		}
		system("cls");
		printf("===%s===\n", descricao[opcao - 1]);
		printf("1 - [%s] - Descrição\n", descricao[opcao - 1]);
		printf("2 - [%d] - Quantidade Estoque\n", quantidade[opcao - 1]);
		printf("3 - [%d] - Quantidade Mínima\n", quantidadeMinima[opcao - 1]);
		printf("4 - [%f] - Preço Unitário\n", precoUnitario[opcao - 1]);
		printf("- [%f] - Preço Total\n", precoTotal[opcao - 1]);
		printf("0 - Retornar\n", precoTotal[opcao - 1]);
		
		char descNova[50];
		char decisao[2];
		int qtdNova = 0, minNova = 0;
		float precoNovo = 0;
		
		printf("Insira o Número para editar o campo correspondente: ");
		fflush(stdin);
		scanf("%d", &alterar);	
			
		switch(alterar){
			case 1:
				while(true){
					printf("Insira a Descrição que você deseja: ");
					fflush(stdin);
					gets(descNova);
					printf("A Descrição [%s] está correta? Ela substituirá a Descrição Atual [%s]! S/N ", descNova, descricao[opcao - 1]);
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
					printf("Insira a Quantidade que você deseja: ");
					fflush(stdin);
					scanf("%d", &qtdNova);
					printf("A Quantidade de %d está correta? Ela substituirá a Quantidade Atual [%d]! S/N ", qtdNova, quantidade[opcao - 1]);
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
					printf("Insira a Quantidade Mínima que você deseja: ");
					fflush(stdin);
					scanf("%d", &minNova);
					printf("A Quantidade Mínima de %d está correta? Ela substituirá a Quantidade Mínima Atual [%d]! S/N ", minNova, quantidadeMinima[opcao - 1]);
					fflush(stdin);
					gets(decisao);
					if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
						quantidadeMinima[opcao - 1] = minNova;
						
						if(quantidade[opcao - 1] < quantidadeMinima[opcao - 1]) {
							printf("ALERTA!!! '%s' está numa quantidade menor do que a mínima!!!\nQuantidade Mínima = %d\n", descricao[opcao - 1], quantidadeMinima[opcao - 1]);
						}
						break;
					}
				}
			break;
			
			case 4:
				while(true){
					printf("Insira o Preço que você deseja: ");
					fflush(stdin);
					scanf("%f", &precoNovo);
					printf("O Preço [%f] está correto? Ele substituiráo Preço Atual [%f]! S/N ", precoNovo, precoUnitario[opcao - 1]);
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
				printf("Opção Inválida!\n");
			break;
		}	
		
		printf("Deseja continuar? S - Sim, N - Não: ");
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
		printf("---Exclusão de Registros---\n");
		for(int i = 0; i < cod; i++){
			if(strcmp(descricao[i], "\0") != 0){
				printf("%d - %s\n", i + 1, descricao[i]);
			}			
		}
		printf("0 - Retornar\n");
		
		while(true){
			printf("Insira o Código que você deseja: ");
			fflush(stdin);
			scanf("%d", &opcao);
					
			if(opcao <= cod && descricao[opcao - 1][0] != '\0'){
				break;
			}
			else if(opcao == 0){
				return 0;
			}
			else{
				printf("Opção Inválida!\n");
			}
		}
		
		system("cls");
		printf("===%s===\n", descricao[opcao - 1]);
		printf("[%s] - Descrição\n", descricao[opcao - 1]);
		printf("[%d] - Quantidade Estoque\n", quantidade[opcao - 1]);
		printf("[%d] - Quantidade Mínima\n", quantidadeMinima[opcao - 1]);
		printf("[%f] - Preço Unitário\n", precoUnitario[opcao - 1]);
		printf("[%f] - Preço Total\n", precoTotal[opcao - 1]);
		printf("Você deseja MESMO excluír? S/N ");
		fflush(stdin);
		gets(decisao);
		if(strcmp(decisao, "S") == 0 || strcmp(decisao, "s") == 0) {
			descricao[opcao - 1][0] = '\0';
			quantidade[opcao - 1] = 0;
			quantidadeMinima[opcao - 1] = 0;
			precoTotal[opcao - 1] = 0;
			precoUnitario[opcao - 1] = 0;
			printf("Produto Excluído com Sucesso!\n");
		}
		
		printf("Deseja continuar? S - Sim, N - Não: ");
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
		printf("---Relatórios---\n");
		printf("1 - Relatório de Produtos abaixo da Quantidade Mínima\n");
		printf("2 - Relatório de Produtos\n");
		printf("0 - Retornar ao Menu\n");
		printf("Insira sua opcão: ");
		scanf("%d", &op);	
		
		float precoBalanco = 0;
		int quantidadeBalanco = 0;
			
		switch(op){
			case 1:
				system("cls");
				printf("Descrição - Quantidade Estoque - Quantidade Mínima\n");
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
				printf("Descrição - Preço - Quantidade Estoque - Quantidade Mínima - Preço Total\n");
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
				printf("\n\nPreço Total: %f - Quantidade Total: %d", precoBalanco, quantidadeBalanco);
			break;
			
			case 0:
				return 0;
			break;
			
			default:
				printf("Opção Inválida!\n");
			break;
		}	
		
		printf("\n\nDeseja continuar? S - Sim, N - Não: ");
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

