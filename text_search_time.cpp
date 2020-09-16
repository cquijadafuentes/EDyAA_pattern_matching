// Toma el tiempo que tardan las búsquedas de patrones
// Requiere dos archivos de texto, uno con el texto
// y otro con los patrones en cada linea del archivo

#include <time.h>
#include <iostream>
#include <fstream>
#include "text_search.h"

const int bruteforce = 1;
const int metodo1 = 2;
const int metodo2 = 3;

using namespace std;

double tiempos_busquedas(int b, string t, string p){
	// Mide el tiempo en segundos que tarda la función de búsqueda b en 
	// buscar el elemento x en el arreglo de la estructura ma
	if(b == bruteforce){
		clock_t start = clock();
		text_search_bruteforce(t,p);
		return (double)(clock() - start) / CLOCKS_PER_SEC;
	}else if(b == metodo1){		
		clock_t start = clock();
		text_search_metodo1(t,p);
		return (double)(clock() - start) / CLOCKS_PER_SEC;
	}else if(b == metodo2){
		clock_t start = clock();
		text_search_metodo2(t,p);
		return (double)(clock() - start) / CLOCKS_PER_SEC;
	}
	return 0.0;
}

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <text_file> <patterns_file>\n", argv[0]);
		printf("Donde:\n");
		printf("text_file contiene el texto.\n");
		printf("patterns_file contiene los patrones a buscar.\n");
		printf("\tLa primera linea es un entero con la cantidad de patrones.\n");
		return -1;
	}
	ifstream file1(argv[1]);
	string texto;
	getline(file1, texto);
	ifstream file2(argv[2]);
	string patron;
	int cPatrones = 0;
	int largoPatrones = 0;
	double t_bruteforce = 0.0;
	double t_metodo1 = 0.0;
	double t_metodo2 = 0.0;
	while(getline(file2, patron)){
		cPatrones++;
		largoPatrones += patron.length();
		t_bruteforce += tiempos_busquedas(bruteforce, texto, patron);
		t_metodo1 += tiempos_busquedas(metodo1, texto, patron);
		t_metodo2 += tiempos_busquedas(metodo2, texto, patron);
	}
	largoPatrones /= cPatrones;
	// Transformar valores de segundos a microsegundos y calcular promedio
	t_bruteforce *= 1000000/cPatrones;
	t_metodo1 *= 1000000/cPatrones;
	t_metodo2 *= 1000000/cPatrones;
	
	printf("%ld\t%d\t%f\t%f\t%f\n", texto.length(), largoPatrones, t_bruteforce, t_metodo1, t_metodo2);
	return 0;
}