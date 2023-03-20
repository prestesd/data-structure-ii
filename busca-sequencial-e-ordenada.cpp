/*Dado que a busca binaria aqui implementada realiza até 20 acessos para acessar os elementos,
  a sequencial terá melhor desempenho em número de acessos até este limite.
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE1 20
#define SIZE 995332

int* allocateMemory(FILE *file){
	long fileSize;
	//Crash sem alocacao dinamica
	rewind(file);
	fseek(file, 0, SEEK_END);
	fileSize = ftell(file);
	rewind(file);
	int *array = (int*)malloc((size_t)fileSize);	
	if (array == NULL){
		printf("\n nao deu para alocar memoria");
		system("pause");
	}
	return array;
}

void charge(FILE *file, int *array){
	int i = 0;
	int value=0, result=0;
	rewind(file);

	while(!feof(file)){ 
		fscanf(file, "%d\n", &array[i]);
		i++;
    }	
}

void sequential(FILE *file, int *array){
	int value;
	int i = 0;
	printf("\n\t=BUSCA SEQUENCIAL=\n");
	printf("\n Digite um valor para a busca\n");
	scanf("%d", &value);
	fflush(stdin);
	charge(file, array);
	
	while (value != array[i] && array[i] <= value && i < SIZE){
		i++;
	}
	if (array[i] == value){
		printf("\n Encontrei o elemento com %d acessos", i);
	}else
	  printf("\n Este elemento nao consta no array");
}

void binary(FILE *file, int *array){
	int value, middle = 0, left = -1, right = SIZE;
	int i = 0;
	printf("\n\t=BUSCA BINARIA=\n");
	printf("\n Digite um valor para a busca\n");
	scanf("%d", &value);
	fflush(stdin);
	charge(file, array);
	
	while(left < right-1){
		int middle = (left + right)/2;
		if(array[middle] < value){
			left = middle;
		}else
		  right = middle;
		  i++;
	}
	if (array[right] == value){
		printf("\n Encontrei o elemento com %d acessos", i);
	}
	else
	   printf("\n Esse valor nao consta no array");
}

int main(){
	FILE *file;
	char line[SIZE];
	int option;
	int *array;
	int fileSize;
	
	if((file = fopen("dados.txt", "r" )) == NULL){
		printf("Impossivel ler arquivo");
	}
	else{		
 		array = allocateMemory(file);
		do{
			printf("\n 1 - Busca sequencial \n");
			printf("\n 2 - Busca binaria\n");
			printf("\n 0 - sair\n");
			
			scanf("%d", &option);
			
			switch(option){
				case 1 : sequential(file, array);
						 break;
				case 2:
						binary(file, array);
						break;
				default:
					    printf("\nok, bye \n");
					    break;
			}
		}while(option !=0);
	  }	
	  free(array);
	  fclose(file);
	system("pause");
}
