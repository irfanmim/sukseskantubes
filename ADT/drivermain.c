#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

typedef struct
{
	int X;
	int Y;
} point;

typedef struct
{
	point posisi;
	long HP;
	long DEF;
	long ATK;
} player;

#define X(P) (P).posisi.X
#define Y(P) (P).posisi.Y
#define HP(P) (P).HP
#define DEF(P) (P).DEF
#define ATK(P) (P).ATK

int main()
{
	player Utama, Enemy[3];
	FILE *jehian;
	char kata[20][20];
	jehian = fopen("peta.txt","r");
	int i = 0;
	do
	{
		fgets(kata[i], 20, jehian);
		++i;
	} while (!feof(jehian));
	fclose(jehian);
	int junk = i;
	srand(time(NULL)*time(NULL));
	i = rand();
	srand(i);
	int j = rand() % 12;
	i = i % 8;
	while (kata[i][j] != '-')
	{
		srand(time(NULL));
		i = rand();
		++i;
		srand(i);
		j = rand() % 12;
		++j;
		j = j % 12;
		i = i % 8;
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
	j = rand() % 12;
	i = i % 8;
	while (kata[i][j] != '-')
	{
		srand(time(NULL));
		i = rand();
		++i;
		srand(i);
		j = rand() % 12;
		++j;
		j = j % 12;
		i = i % 8;
	}
	kata[i][j] = 'M';
	int k;
	
	for (k = 0; k <= 2; ++k)
	{
		srand(time(NULL));
		i = rand();
		srand(i);
		j = rand() % 12;
		i = i % 8;
		while (kata[i][j] != '-')
		{
			srand(time(NULL));
			i = rand();
			++i;
			srand(i);
			j = rand() % 12;
			++j;
			j = j % 12;
			i = i % 8;
		}
		kata[i][j] = 'E';

		X(Enemy[k]) = j;
		Y(Enemy[k]) = i;
		ATK(Enemy[k]) = 50;
		DEF(Enemy[k]) = 10;
		HP(Enemy[k]) = 20;

	}
	
	for (k = 0; k <= 8; ++k)
	{
		printf("%s", kata[k]);
	}
	k = 3;
	char CC[2];
	while (k != 0)
	{
		gets(CC);
		kata[Y(Utama)][X(Utama)] = '-';
		if (strcmp(CC, "GD") == 0 && kata[Y(Utama)+1][X(Utama)] != '#')
		{
			++Y(Utama);
		}
		else if (strcmp(CC, "GU") == 0 && kata[Y(Utama)-1][X(Utama)] != '#')
		{
			--Y(Utama);
		}
		else if (strcmp(CC, "GL") == 0 && kata[Y(Utama)][X(Utama)-1] != '#')
		{
			--X(Utama);
		}
		else if (strcmp(CC, "GR") == 0 && kata[Y(Utama)][X(Utama)+1] != '#')
		{
			++X(Utama);
		}
		if (kata[Y(Utama)][X(Utama)] == 'M')
		{
			HP(Utama) += 10;
		}
		kata[Y(Utama)][X(Utama)] = 'P';
		system("cls");
		for (k = 0; k < junk-1; ++k)
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
