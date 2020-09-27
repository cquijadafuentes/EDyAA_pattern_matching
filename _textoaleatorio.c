#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
	int n = (int) atoi(argv[1]);
	srand (time(NULL));
	for(int i = 0; i<n; i++){
		printf("%c", 'a'+(rand()%26));
	}
	return 0;
}