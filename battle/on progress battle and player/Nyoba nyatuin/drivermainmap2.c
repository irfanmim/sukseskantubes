#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "point.h"
#include "player.h"

int main()
{
	player Utama, Enemy[3];
	FILE *jehian;
	jehian = fopen("status.txt","r");
	char kata[1000][1000], mapu[1000][1000];
	int i = 0, tanda = 0, found = 0;
	while (!feof(jehian))
	{
		fgets(kata[i], 1000, jehian);
		if (kata[i][2] == ' ' && !found)
		{
			tanda = i;
			found = 1;
		}
		++i;
	}
	int CCeff = i-1;
	fclose(jehian);
	jehian = fopen("B.txt","r");
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
		system("cls");
		for (k = 0; k < CCeff; ++k)
		{
			printf("%s", kata[k]);
		}
		printf("%ld\n", HP(Utama));	
	
	}
	system("cls");
	kata[i][j] = 'M';
	for (k = 0; k < 8; ++k)
	{
		printf("%s", kata[k]);
	}	
	return 0;
}
