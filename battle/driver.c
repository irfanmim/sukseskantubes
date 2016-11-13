#include "boolean.h"
#include "queue.h"
#include <stdio.h>

int main() {
	Queue Q,Battle;
	char input,temp;
	int i;

	CreateEmpty(&Q,4);
	CreateEmpty(&Battle,4);

	Add(&Q,'F');
	Add(&Q,'B');
	Add(&Q,'F');
	Add(&Q,'A');

	PrintQueueRandom(Q);

	printf("\n");

	i = 0;
	printf("Masukkan Aksi : ");
	scanf("%c", &input);
	while ( i != 4 ) {
		
		if ( input != 'D' ) {
			i++;
			Add(&Battle,input);
		}
		else {
			Del(&Battle,&temp);
			i--;
		}
		PrintQueue(Battle);
		printf("\n");

		printf("Masukkan Aksi : ");
		scanf(" %c", &input);
	}

	PrintQueue(Battle);
	printf("\n");

	printf("\n");
	return 0;
}