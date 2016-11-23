#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "point.h"
#include "peta.h"
#include "player.h"
#include "boolean.h"

void Converter(int CC);
void maketable(int* kata, int A, int B);

int main()
{
	player Utama, Enemy[3];
	int ui, uj;
	printf("Masukkan ukuruan peta: ");
	scanf("%d %d", &ui, &uj);
	int kata[ui][uj];
	char mapu[1000][1000];
	maketable(kata, ui, uj);
	int q, r;
	for (q = 0; q < ui; ++q)
	{
		for (r = 0; r < uj; ++r)
		{
			Converter(kata[q][r]);
		}
		printf("\n");
	}
	FILE *jehian;
	int i, tanda = 0, found = 0;
	int CCeff = ui;
	tanda = 2;
	jehian = fopen("A.txt","r");
	i = 0;
	while (!feof(jehian))
	{
		fgets(mapu[i], 1000, jehian);
		++i;
	}
	int mapueff = i-1;
	int tengahp = (tanda+CCeff-mapueff)/2, tengahl = (strlen(kata[CCeff-1])-strlen(mapu[0])+1)/2;
	int j;
	for (i = tengahp; i < tengahp+mapueff; ++i)
	{
		for (j = tengahl; j < tengahl+strlen(mapu[i-tengahp])-1; ++j)
		{
			kata[i][j] = mapu[i-tengahp][j-tengahl];
		}		
	}
	
	srand(time(NULL));
	i = rand();
	srand(i);
	j = rand() % strlen(mapu[0]) + tengahl;
	i = i % mapueff + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % strlen(mapu[0]) + tengahl;
	}
	kata[i][j] = 'P';
	X(Utama) = j;
	Y(Utama) = i;
	HP(Utama) = 100;
	ATK(Utama) = 1000;
	DEF(Utama) = 2000;
	
	srand(time(NULL));
	i = rand();
	srand(i);
	j = rand() % strlen(mapu[0]) + tengahl;
	i = i % mapueff + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % strlen(mapu[0]) + tengahl;
	}
	kata[i][j] = 'M';
	int k;
	
	for (k = 0; k <= 2; ++k)
	{
		srand(time(NULL));
		i = rand();
		srand(i);
		j = rand() % strlen(mapu[0]) + tengahl;
		i = i % mapueff + tengahp;
		while (kata[i][j] != '-')
		{
			srand(j);
			++j;
			j = j % strlen(mapu[0]) + tengahl;
		}
		kata[i][j] = 'E';

		X(Enemy[k]) = j;
		Y(Enemy[k]) = i;
		ATK(Enemy[k]) = 50;
		DEF(Enemy[k]) = 10;
		HP(Enemy[k]) = 20;

	}
	
	for (k = 0; k < CCeff; ++k)
	{
		printf("%s", kata[k]);
	}
	k = 3;
	char CC[2];
	while (k != 0)
	{
		gets(CC);
		kata[Y(Utama)][X(Utama)] = '-';
		if (strcmp(CC, "GD") == 0 && (kata[Y(Utama)+1][X(Utama)] == '-' || kata[Y(Utama)+1][X(Utama)] == 'M' || kata[Y(Utama)+1][X(Utama)] == 'E'))
		{
			GerakBawah(&Posisi(Utama));
		}
		else if (strcmp(CC, "GU") == 0 && (kata[Y(Utama)-1][X(Utama)] == '-' || kata[Y(Utama)-1][X(Utama)] == 'M' || kata[Y(Utama)-1][X(Utama)] == 'E'))
		{
			GerakAtas(&Posisi(Utama));
		}
		else if (strcmp(CC, "GL") == 0 && (kata[Y(Utama)][X(Utama)-1] == '-' || kata[Y(Utama)][X(Utama)-1] == 'M' || kata[Y(Utama)][X(Utama)-1] == 'E'))
		{
			GerakKiri(&Posisi(Utama));
		}
		else if (strcmp(CC, "GR") == 0 && (kata[Y(Utama)][X(Utama)+1] == '-' || kata[Y(Utama)][X(Utama)+1] == 'M' || kata[Y(Utama)][X(Utama)+1] == 'E'))
		{
			GerakKanan(&Posisi(Utama));
		}
		if (kata[Y(Utama)][X(Utama)] == 'M')
		{
			RestoredHP(&Utama);
		}
		kata[Y(Utama)][X(Utama)] = 'P';
		system("clear");
		for (k = 0; k < CCeff; ++k)
		{
			printf("%s", kata[k]);
			printf("\n");
		}
		printf("%ld\n", HP(Utama));	
	
	}
	system("clear");
	kata[i][j] = 'M';
	for (k = 0; k < 8; ++k)
	{
		printf("%s", kata[k]);
	}	
	return 0;
}

/*
void maketable(int A, int B)
{
	FILE *f;
	f = fopen("map.txt", "w");
	int i, j;
	for (i = 0; i < 1 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 201);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 187);
	}
	for (; i < 2 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 186);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, " ");
		}
		fprintf(f, "%c\n", (char) 186);
	}
	for (; i < 3 && i < A; ++i)
	{
		fprintf(f, "%c", (char) 204);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 185);
	}
	for (; i < A-1; ++i)
	{
		fprintf(f, "%c", (char) 186);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, " ");
		}
		fprintf(f, "%c\n", (char) 186);
	}
	for (i = A-1; i < A; ++i)
	{
		fprintf(f, "%c", (char) 200);
		for (j = 1; j < B-1; ++j)
		{
			fprintf(f, "%c", (char) 205);
		}
		fprintf(f, "%c\n", (char) 188);
	}
	fclose(f);
}
*/

void maketable(int* AA, int A, int B)
{
	int i, j;
	for (i = 0; i < 1 && i < A; ++i)
	{
		AA[i*B] = 201;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = 205;
		}
		AA[i*B+j] = 187;
	}

	for (; i < 2 && i < A; ++i)
	{
		AA[i*B] = 186;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = ' ';
		}
		AA[i*B+j] = 186;
	}

	for (; i < 3 && i < A; ++i)
	{
		AA[i*B] = 204;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = 205;
		}
		AA[i*B+j] = 185;
	}
	for (; i < A-1; ++i)
	{
		AA[i*B] = 186;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = ' ';
		}
		AA[i*B+j] = 186;
	}
	for (i = A-1; i < A; ++i)
	{
		AA[i*B] = 200;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = 205;
		}
		AA[i*B+j] = 188;
	}
}

void Converter (int CC)
{
	if (CC == 185)
	{
		printf("\u2563");
	}
	else if (CC == 186)
	{
		printf("\u2551");
	}
	else if (CC == 187)
	{
		printf("\u2557");
	}
	else if (CC == 188)
	{
		printf("\u255D");
	}
	else if (CC == 200)
	{
		printf("\u255A");
	}
	else if (CC == 201)
	{
		printf("\u2554");
	}
	else if (CC == 204)
	{
		printf("\u2560");
	}
	else if (CC == 205)
	{
		printf("\u2550");
	}
	else
	{
		printf("%c", (char) CC);
	}
}