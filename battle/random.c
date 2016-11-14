#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	srand(time(NULL));
	int r = rand();
	int i = rand() % 4;

	while ( i == r ){
		i = rand() % 4;
	}

	printf("%d %d\n", i, r );

	return 0;
}