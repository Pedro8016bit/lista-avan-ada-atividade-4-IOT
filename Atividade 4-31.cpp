#include <stdio.h>

int main(){
	
	int i, aux, flag;
	int lista[10];
	
		for (i = 0; i <= 9; i++){
		printf("digite para por em ordem %d", i+1);
		scanf("%d", &lista[i]);
	}
	flag = 1;
	while(flag){
		flag = 0;
		for(i=0; i <= 8; i++){
			if (lista[i] > lista[i + 1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				flag = 1; 
			}
		}
	}
	for (i = 0; i <= 9; i++){
		printf(" \n Item %d : %d", i+1, lista[i] );
	}
}

