#include <iostream>
#include "text_search.h"

using namespace std;

void print_coincidencias(int* c){
	printf("Coincidencias: %d\n>  ", c[0]);
	for(int i=1; i <= c[0]; i++){
		printf("%d  ", c[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	string t;
	string p;
	cout << "Ingrese el texto: ";
	getline(cin, t);
	cout << "Ingrese el patrón: ";
	getline(cin, p);
	printf("---------------------------------------------------\n");
	int* fb = text_search_bruteforce(t,p);
	printf("Fuerza Bruta:\n");
	if(fb == NULL){
		printf("Error! falla la búsqueda\n");
	}
	print_coincidencias(fb);
	printf("---------------------------------------------------\n");
	int* m1 = text_search_metodo1(t,p);
	printf("Método 1:\n");
	if(m1 == NULL){
		printf("Error! falla la búsqueda\n");
	}
	print_coincidencias(m1);
	printf("---------------------------------------------------\n");
	int* m2 = text_search_metodo2(t,p);
	printf("Método 2:\n");
	if(m2 == NULL){
		printf("Error! falla la búsqueda\n");
	}
	print_coincidencias(m2);
	printf("---------------------------------------------------\n");
	
	return 0;
}