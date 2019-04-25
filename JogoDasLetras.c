#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int getMenor();
int hasInDesordenado(char);
void imprimirArray(char *, int);

char ordenados[13];
char desordenadas[13] = { 'H', 'T', 'M', 'A', 'V', 'B', 'C', 'I', 'E', 'R', 'D', 'N', 'L' };


int main() {
	for(int i = 0; i < 13; i++){
		char menor = getMenor();
		ordenados[i] = menor;
	}

	printf("Letras ordenadas: ");
	imprimirArray(ordenados, 13);

	printf("Letras desordenadas: ");
	imprimirArray(desordenadas, 13);

}


int getMenor(){
	int menor = 9999;
	for(int i = 0; i < 13; i++){
		char letra = desordenadas[i];
		if(letra < menor && !hasInDesordenado(letra)){
			menor = letra;
		}
	}
	return menor;
}

int hasInDesordenado(char c){
	for(int i = 0; i < 13; i++){
		if(ordenados[i] == c){
			return 1;
		}
	}
	return 0;
}

void imprimirArray(char array[], int size){
	for(int i = 0; i < size; i++){
		printf("%c ", array[i]);
	}
	printf("\n");
}
