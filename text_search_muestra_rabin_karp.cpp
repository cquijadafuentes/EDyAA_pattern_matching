#include <iostream>

using namespace std;

int* rabin_karp(string t, string p){
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
	
	printf("h = %d\n", h);
	printf("Patrón: \n");
	for(int i = 0; i < m; i++){
		printf("%c", p.at(i));
	}
	printf("\nph: %d\n", ph);
	printf("Texto:\n");
	for(int i = 0; i <= n-m; i++){
		for(int i = 0; i < n; i++){
			printf("%c     ", t.at(i));
		}
		printf("\n");
		for(int j=0; j<i; j++){
			printf("      ");
		}
		for(int j=1; j<m; j++){
			printf("______");
		}
		printf("_%d\n", th);	
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

int main(int argc, char *argv[]){
	string t;
	string p;
	cout << "Ingrese el texto: ";
	getline(cin, t);
	cout << "Ingrese el patrón: ";
	getline(cin, p);
	printf("---------------------------------------------------\n");
	int* c = rabin_karp(t,p);
	printf("Método: Rabin Karp\n");
	if(c == NULL){
		printf("Error! falla la búsqueda\n");
	}
	for(int i = 0; i < (int)t.length(); i++){
		printf("%c\t", t.at(i));
	}
	printf("\n");
	for(int i = 0; i < (int)t.length(); i++){
		printf("%d\t", (i));
	}
	printf("\n");
	printf("Coincidencias: %d\n>  ", c[0]);
	for(int i=1; i <= c[0]; i++){
		printf("%d  ", c[i]);
	}
	printf("\n");
	printf("---------------------------------------------------\n");
	
	return 0;
}