#include <iostream>
#include <map> 
#include "text_search.h"

using namespace std;

bool bruteforce_verificador(string &t, string &p, int x){
	// Retorna falso si el patrón p no está en t desde la posicón x
	for(int i = 0; i < (int) p.length(); i++){
		if(t[x+i] != p[i])	return false;
	}
	return true;
}

int* text_search_bruteforce(string &t, string &p){
	// Mayor cantidad de coincidencias posibles según el tamaño de los strings
	int max_coin = t.length() - p.length() + 1;
	// Se reserva la cantidad de elementos + el contador que va a inicio.SEguroa
	if(t.length() < p.length()){
		printf("Error! el tamaño del texto es menor que el tamaño del patrón\n");
		return NULL;
	}
	int* c = (int *) malloc(sizeof(int) * (max_coin + 1));
	c[0] = 0;
	for(int i = 0; i< max_coin; i++){
		if(bruteforce_verificador(t, p, i)){
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

/* Implementación Boyer Moore */
int* text_search_metodo1(string &t, string &p){
	// Mayor cantidad de coincidencias posibles según el tamaño de los strings
	int max_coin = t.length() - p.length() + 1;
	// Se reserva la cantidad de elementos + el contador que va a inicio.SEguroa
	int* c = (int *) malloc(sizeof(int) * (max_coin + 1));
	c[0] = 0;
	
	/* Procesamiento funcion de ultima ocurrencia */
	map<char, int> lastOcurrence;
	for(int i = 0; i < (int) t.length(); i++){
		lastOcurrence[t[i]] = -1;
	}
	for(int i = 0; i < (int) p.length(); i++){
		lastOcurrence[p[i]] = i;
	}
	
	int i = p.length() - 1;
	int j = p.length() - 1;
	/* Revisión del patrón en el texto */
	while(i < (int) t.length()){
		/* El patron coincide con la revisión actual */
		if(t[i] == p[j]){
			/* El patrón coincide completamente. Hay un matching */
			if(j == 0){
				c[0]++;
				c[c[0]] = i;
				i += p.length();
				j = p.length() - 1;
			/* El patrón coincide parcialmente. La revisión debe continuar */
			}else{
				i--;
				j--;
			}
		/* El patrón no coincide. Se debe realizar el salto del patrón. */
		}else{
			i = i + p.length() - min(j, 1 + lastOcurrence[t[i]]);
			j = p.length() - 1;
		}
	}
	
	c = (int *) realloc(c, sizeof(int) * (c[0] + 1));
	if(c == NULL){
		printf("Error! en la reubicación de memoria del resultado.\n");
		return NULL;
	}
	return c;
}

/* Implementación Rabin-Karp */
int* text_search_metodo2(string &t, string &p){
	int n = t.length();
	int m = p.length();
	int q = 101;	// Número primo 
	int d = 256;	// Tamaño del alfabeto ASCII
	int h = 1;
	for(int i=1; i<m; i++){
		h = (h*d) % q;
	}

	int ph = p.at(0);
	int th = t.at(0);
	for(int i = 1; i < m; i++){
		ph = (d*ph + p.at(i))%q;
		th = (d*th + t.at(i))%q;
	}
	int* c = (int *) malloc(sizeof(int));
	c[0] = 0;
	int aux;
	for(int i = 0; i <= n-m; i++){
		// El hash del patrón y de la ventana son iguales
		if(ph == th){
			aux = 0;
			// Comprobar si la ventana contiene lo mismo
			// que el patrón (por posibles colisiones del hash)
			while(aux < m && p.at(aux) == t.at(i+aux)){
				aux++;
			}
			if(aux == m){
				c[0]++;
				c[c[0]] = i;
			}
		}
		if(i<n-m){
			//  Se quita el elemento de mayor orden de la
			// ventana anterior, el resultado se multiplica 
			// por 10 y se suma elemento de menor orden de
			// la ventana actual.
			th = (d*((th - t.at(i)*h)%q) + t.at(i+m)) % q;
			// En caso que la resta de valores negativos
			if(th < 0){
				th += q;
			}
		}
	}
	c = (int *) realloc(c, sizeof(int) * (c[0] + 1));
	if(c == NULL){
		printf("Error! en la reubicación de memoria del resultado.\n");
		return NULL;
	}
	return c;
}