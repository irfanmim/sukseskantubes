#include "boolean.h"
#include "queue.h"
#include <stdio.h>

int main() {
	Queue Q;

	CreateEmpty(&Q,4);

	Add(&Q,'F');
	Add(&Q,'B');
	Add(&Q,'F');
	Add(&Q,'A');

	PrintQueue(Q);

	printf("\n");
	return 0;
}