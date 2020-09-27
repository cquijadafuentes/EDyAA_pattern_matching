#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "text_search.h"

// Genera <cant_files> archivos de texto y patrones en base al texto en <text_fle>
// Para el caso del patrón genera: 
//		<cant_files> de patrones que seguro están en cualquiera de textos generados
//		<cant_files> de patrones que seguro no están en alguno de los textos utilizando <extra_char>
//		<cant_files> de patrones (mitad del primer caso, mitad del segundo caso)
//
// Para los patrones que no están en el texto se incluy al final <extra_char>

using namespace std;

int main(int argc, char *argv[]){
	if(argc < 8){
		printf("Error! Faltan argumentos.\n");
		printf("Usage: %s <text_file> <pref_output> <cant_files> <max_text> <max_patt> <extra_char>\n", argv[0]);
		printf("Donde:\n");
		printf("\ttext_file: nombre del fichero con el texto fuente (El archivo no debe contener saltos de linea).\n");
		printf("\tpref_output: prefijo para los archivos de salida.\n");
		printf("\tcant_files: cantidad de archivos a generar (de texto y de patrones).\n");
		printf("\tmax_text: cantidad de caracteres para el texto de salida más largo.\n");
		printf("\tmax_patt: cantidad de caracteres para el patron más largo.\n");
		printf("\tcant_patt: cantidad de patrones a generar en cada archivo\n");
		printf("\textra_char: caracter que no existe en <text_file> para segurar patrones sin aparición.\n");
		return -1;
	}
	// Cargar valores de entrada
	string text_file = argv[1];
	string pref_output = argv[2];
	int cant_files = (int) atoi(argv[3]);
	int max_text = (int) atoi(argv[4]);
	int max_patt = (int) atoi(argv[5]);
	int cant_patt = (int) atoi(argv[6]);
	char extra_char = argv[7][0];

	// Mostrar variables para verificar lectura:
	cout << text_file << endl;
	cout << pref_output << endl;
	cout << cant_files << endl;
	cout << max_text << endl;
	cout << max_patt << endl;
	cout << cant_patt << endl;
	cout << extra_char << endl;

	ifstream file1(argv[1]);
	string texto;
	if(! getline(file1, texto)){
		printf("Error! en la lectura del archivo <text_file>\n");
		return -1;
	}
	printf("Tamaño del texto: %d\n", (int)texto.length());
	if((int)texto.length() < max_text){
		printf("Error! <text_file> no cotinene el largo para <max_text>\n");
		return -1;
	}

	srand(time(NULL));
	int bloque_text = max_text / cant_files;
	int bloque_patt = max_patt /cant_files;

	if(max_patt > bloque_text){
		printf("Error! max_patt debe ser menor a <max_text>/<cant_files> (%d)\n", bloque_text);
	}

	// Generando archivos de salida
	for(int i=1; i <= cant_files; i++){
		int size_text = i*bloque_text;
		//  Generando archivos de texto
		ofstream out_t(pref_output+"_tx_"+to_string(size_text)+".txt");
		out_t << texto.substr(0, size_text) << endl;
		out_t.close();
		//	Generando archivos de patrones
		int size_patt = i*bloque_patt;
		ofstream out_py(pref_output+"_pt_yes_"+to_string(size_patt)+".txt");		
		ofstream out_pn(pref_output+"_pt_no_"+to_string(size_patt)+".txt");
		ofstream out_pyn(pref_output+"_pt_yn_"+to_string(size_patt)+".txt");

		for(int j=0; j<cant_patt; j++){
			string ptyes = texto.substr((rand() % (bloque_text - 1 - size_patt)), size_patt);
			out_py << ptyes << endl;
			if(j%2 == 0){
				out_pyn << ptyes << endl;
			}
		}
		
		for(int j=0; j<cant_patt; j++){
			for(int k=0; k<size_patt-1; k++){
				out_pn << texto.at(rand()%texto.size());
				if(j%2 == 0){
					out_pyn << texto.at(rand()%texto.size());
				}
			}
			out_pn << extra_char << endl;
			if(j%2 == 0){
				out_pyn << extra_char << endl;
			}
		}
	}
	
	return 0;
}