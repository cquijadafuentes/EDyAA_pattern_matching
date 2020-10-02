// Toma tiempo y número de colisiones para rabin-karp al modificarlo
// para que acepte parámetro q en las operaciones

#include <time.h>
#include <iostream>
#include <fstream>
#include "text_search.h"

// La salida es:
// tamaño_texto tamaño_patron q_value t_rabinkarp cant_colisionesRK

const int bruteforce = 1;
const int metodo1 = 2;
const int metodo2 = 3;

using namespace std;

int* RabinKarp(string &t, string &p, int q);

int main(int argc, char *argv[]){
	if(argc < 4){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <text_file> <patterns_file> <q_value>\n", argv[0]);
		printf("Donde:\n");
		printf("text_file contiene el texto.\n");
		printf("patterns_file contiene los patrones a buscar.\n");
		printf("q es un valor para evitar colisiones en el algoritmo RabinKarp.\n");
		printf("La salida es:\n");
		printf("\ttamaño_texto tamaño_patron t_rabinkarp cant_colisionesRK\n");
		return -1;
	}
	ifstream file1(argv[1]);
	string texto;
	getline(file1, texto);
	ifstream file2(argv[2]);
	string patron;
	int q_value = (int) atoi(argv[3]);
	int cPatrones = 0;
	int largoPatrones = 0;
	double colisionesRK = 0.0;
	clock_t start = clock();
	while(getline(file2, patron)){
		cPatrones++;
		largoPatrones += patron.length();
		int* res = RabinKarp(texto, patron, q_value);
		colisionesRK += res[res[0]+1];
		free(res);
	}
	double t_rabinkarp = (double)(clock() - start) / CLOCKS_PER_SEC;

	largoPatrones /= cPatrones;
	// Transformar valores de segundos a microsegundos y calcular promedio
	t_rabinkarp *= 1000000/cPatrones;
	colisionesRK = colisionesRK / cPatrones;
	printf("%ld\t%d\t%d\t%.2f\t%.2f\n", texto.length(), largoPatrones, q_value, t_rabinkarp, colisionesRK);
	return 0;
}

/* Implementación Rabin-Karp */
int* RabinKarp(string &t, string &p, int q){
	int n = t.length();
	int m = p.length();
	int d = SIGMA;	// Tamaño del alfabeto
	char fc = FIRSTCHAR + 1;
	int h = 1;
	for(int i=1; i<m; i++){
		h = (h*d) % q;
	}
	int colisiones = 0;
	int ph = p.at(0) - fc;
	int th = t.at(0) - fc;
	for(int i = 1; i < m; i++){
		ph = (d*ph + p.at(i) - fc)%q;
		th = (d*th + t.at(i) - fc)%q;
	}
	int* c = (int *) malloc(sizeof(int)*(n-m-1));
	if(c == NULL){
		printf("Error! en la reserva de memoria de método Rabin-Karp.\n");
		return NULL;
	}
	c[0] = 0;
	int aux;
	for(int i = 0; i <= n-m; i++){
		// El hash del patrón y de la ventana son iguales
		if(ph == th){
			colisiones++;
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
			th = (d*((th - (t.at(i) - fc)*h)%q) + (t.at(i+m) - fc)) % q;
			// En caso que la resta de valores negativos
			if(th < 0){
				th += q;
			}
		}
	}
	// +2 para guardar dos enteros adicionales
	// En la primera posición la cantidad de coincidencias
	// al final del arreglo la cantidad de colisiones que debieron ser verificadas
	c = (int *) realloc(c, sizeof(int) * (c[0] + 2));
	// La cantidad de veces que se verificò un hash - cantidad de patrones reales
	c[c[0]+1] = colisiones - c[0];
	if(c == NULL){
		printf("Error! en la reubicación de memoria del resultado.\n");
		return NULL;
	}
	return c;
}