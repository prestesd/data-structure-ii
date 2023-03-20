#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pessoa{
	char nome[30];
	char sobrenome[30];
	int  idade;
	char cpf[11];
};

void inserir(Pessoa *p){
	printf("\n Insira o nome da pessoa: \n");
	scanf("%s", p->nome);
	printf("\n Insira o sobrenome da pessoa:\n");
	scanf("%s", p->sobrenome);
	printf("\n Insira a idade da pessoa:\n");
	scanf("%d", &p->idade);
	printf("\n Insira o cpf da pessoa:\n");
	scanf("%s", p->cpf);
}
int main(){
	Pessoa *p;
	inserir(p);
	printf("\nInfos:");
	printf("%s", p->nome);
	printf("%s", p->sobrenome);
	printf("%d", p->idade);
	printf("%s",p->cpf);
	return 0;
}
