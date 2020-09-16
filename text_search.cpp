#include <iostream>
#include "text_search.h"

using namespace std;

bool bruteforce_verificador(string t, string p, int x){
	// Retorna falso si el patrón p no está en t desde la posicón x

	return true;
}

int* text_search_bruteforce(string t, string p){
	// Mayor cantidad de coincidencias posibles según el tamaño de los strings
	int max_coin = t.length() - p.length() + 1;
	// Se reserva la cantidad de elementos + el contador que va a inicio.SEguroa
	int* c = (int *) malloc(sizeof(int) * (max_coin + 1));
	c[0] = 0;
	for(int i = 0; i< max_coin; i++){
		if(t.at(i) == p.at(0)){
			c[0]++;
			c[c[0]] = i;
		}
	}
	c = (int *) realloc(c, sizeof(int) * (c[0] + 1));
	if(c == NULL){
		printf("Error! en la reubicación de memoria del resultado.\n");
		return NULL;
	}
	return c;
}

int* text_search_metodo1(string t, string p){
	int* c = (int *) malloc(sizeof(int));
	c[0] = 0;

	return c;
}

int* text_search_metodo2(string t, string p){
	int* c = (int *) malloc(sizeof(int));
	c[0] = 0;

	return c;
}