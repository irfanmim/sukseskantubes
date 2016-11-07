#include <stdio.h>
#include <string.h>
#include "boolean.h"

void printlogo();
// I.S : Sembarang
// F.S : Menghasilkan logo bright souls sebagai output 

int main() {
	
	// Kamus
	int input;
	boolean quit;
	
	// Algoritma
	printlogo();
	printf("\n\n");
	printf("1.	New Game\n");
	printf("2.	Continue\n");
	printf("3.	Quit Game\n\n");
	printf("Masukkan input . . .\n"); 
	
	quit = false;
	while (!quit) {
		scanf("%d", &input); printf("\n");
		switch (input) {
			case 1 :;
					break;
			case 2 :;
					break;
			case 3 : quit = true;
					break;
			default : printf("Input salah\n");
		}
	}
	
	return 0;
}
	
void printlogo() 
// I.S : Sembarang
// F.S : Menghasilkan logo bright souls sebagai output 
{
	FILE * logo;

	char M[300][300];
	int i, j, count; 	
	char cc;
	
	logo = fopen("logo.txt", "r");
	count = 0; i = 0; j = 0;
	while (cc != EOF) {
		cc = fgetc(logo);
		if ((cc != EOF) && ((int)(cc) != 10)) {
			M[i][j] = cc;
			j++;
		}
		else { // cc == EOF or cc == nl
			if ((int)(cc) == 10) {
				i++;
				count++;
				j = 0;
			}
		}
	}
	for (i = 0; i < count; i++) {
		printf("%s\n", M[i]);
	}
	
	fclose(logo);
	
}
	