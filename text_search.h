#include <string>


#define SIGMA 100
#define FIRSTCHAR 32
// Sigma corresponde al tamaño del alfabeto
// Se considera el alfabeto desde el 32 al 131
// Donde 32 corresponde al espacio.

// Todas las búsquedas retornarán un arreglo de enteros
// El primer elemento del arreglo indica la cantidad de
// coincidencias del patrón p en el texto t
// y luego, por cada coincidencia se indica la posición
// de t en la cual se encuentra el patrón p.

// ******************** SEARCHING ******************** //

using namespace std;

int* text_search_bruteforce(string &t, string &p);
int* text_search_metodo1(string &t, string &p);
int* text_search_metodo2(string &t, string &p);

// ************************************************* //
