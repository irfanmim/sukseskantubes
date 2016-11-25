#include "boolean.h"
#include "soqlist.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void buatsoq( char *T , Stack *S, int *nb);

int main() {
	Stack S;
	Queue Qtemp;
	int l,nb;

	buatsoq("file.txt", &S, &nb);

	//Print Stack of Queue

	for (l=0; l<nb;l++) {
		Pop(&S,&Qtemp);
		PrintQueue(Qtemp);
	}


	printf("\n%d\n",nb);
	return 0;
}

void buatsoq( char *T, Stack *S, int *nb) {

	FILE* pita;
	Queue Q, Qtemp;
	Queue final[2][50];
	int i,j;
	char isifile[1][300];
	char temp[1][100];
	int a,b,l,s,k;
	int r;
	char ct;


	CreateEmptyQueue(&Q);
	pita = fopen(T,"r");

	//Isi file dipindah ke array isifile 
	i = 0;
	while ( !feof(pita) ) {
		fscanf(pita, "%c", &isifile[0][i]);
		i++;	
	}

	fclose(pita);

	//Nyoba print isifile
/*	j = 0;
	while ( j < i-1) {
		printf("%c", isifile[0][j] );
		j++;
	}
*/

	//Masukkin array ke Queue
	a=0;
	j=0;
	srand(time(NULL));
	while ( isifile[0][j] != '\0' ) {
		if ( isifile[0][j] != '\n' ) {
			Add( &Q, isifile[0][j] );
			a++;
		}
		else {
			for ( b=0; b<a;b++) {
				Del(&Q, &ct);
				temp[0][b] = ct;
			}

			//Random Array
			for (l = 0; l<a; l++) {
				r = rand() % a;
				ct = temp[0][l];
				temp[0][l] = temp[0][r];
				temp[0][r] = ct;
			}

			for ( b=0; b<a;b++) {
				Add(&Q, temp[0][b]);
			}
			
			final[0][s] = Q;
			
			s++;
			CreateEmptyQueue(&Q);
			a = 0;
		}
		j++;
	}

	
	//Random Array
	//srand(time(NULL));
	
	for (l = 0; l<s; l++) {
		r = rand() % s;
		//printf("%d\n", r);
		Qtemp = final[0][l];
		final[0][l] = final[0][r];
		final[0][r] = Qtemp;
	}

	//Print Array Queue
	k = 0;
/*	while ( k != s) {
		//PrintQueue(final[0][k]);
		k++;	
	}
*/

	//Masukin Queue ke Stack
	CreateEmpty(S);

	for (l=0; l<s;l++) {
		Push(S,final[0][l]);
	}

	*nb = s; 



}