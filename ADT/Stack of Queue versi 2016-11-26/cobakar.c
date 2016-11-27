#include "boolean.h"
#include "soqlist.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	FILE * pita;
	char array[1][100];
	int i,j,k,s,l,r;	
	Queue final[2][20];
	Queue Q, Qtemp;
	Stack S;

	pita = fopen("file.txt","r");


	i = 0;
	while (!feof(pita)) {
		fscanf(pita, "%c", &array[1][i]);
		i++;	
	}

	fclose(pita);


	CreateEmptyQueue(&Q);

	s=0;
	j=0;
	while ( j != i) {
		if ( array[1][j] != '\n' ) {
			Add( &Q, array[1][j] );
		}
		else {
			final[1][s] = Q;
			s++;
			CreateEmptyQueue(&Q);
		}
		j++;
	}

//Random Array
	srand(time(NULL));
	
	for (l = 0; l<=s-1; l++) {
		r = rand() % 10;
		//printf("%d\n", r);
		Qtemp = final[1][l];
		final[1][l] = final[1][r];
		final[1][r] = Qtemp;
	}

//Masukin Queue ke Stack
	CreateEmpty(&S);

	for (l=0; l<=s-1;l++) {
		Push(&S,final[1][l]);
	}

//Print File Eksternal
/*	
	k =0;
	while ( k != i ) {
		printf("%c",array[1][k]);
		k++;
	}

	printf("\n\n");
*/

//Print Array Queue
	k = 0;
	while ( k != s) {
		PrintQueue(final[1][k]);
		k++;	
	}
	
//Cek NbELmt
	printf("%d\n", NbElmt(final[1][0]));

//Print Stack of Queue
	for (l=0; l<=s-1;l++) {
		Pop(&S,&Qtemp);
		PrintQueue(Qtemp);
	}	

	return 0;
}