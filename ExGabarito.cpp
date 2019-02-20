#include <stdio.h>
#include <string.h>
int main (){
	char gabarito[11];	
	char aluno[10][20];
	char curso[10][5];
	char resp[11];
	int nota = 0;
	int notas[10];
	
	printf("Insira o Gabarito: ");
	gets(gabarito);
	
	for(int i = 0; i < 3; i++){
		
		printf("Insira o Nome: ");
		gets(aluno[i]);
		printf("Insira o nome do Curso:");
		gets(curso[i]);	
		printf("Insira o Gabarito do Aluno: ");
		gets(resp);
		
		for(int socorro = 0; 
		socorro < 10; socorro++){
			if(resp[socorro] == gabarito[socorro]){
				nota++;
			}
		}
		notas[i] = nota;
		printf("\n");
		nota = 0;
	}
	
	for(int i = 0; i < 3; i++){
		if(notas[i] >= 5){
			printf("\nAluno: %s, Curso: %s, Nota: %d, APROVADO", aluno[i], curso[i], notas[i]);
		}
		else{
			printf("\nAluno: %s, Curso: %s, Nota: %d, REPROVADO", aluno[i], curso[i], notas[i]);
		}
	} 
}
