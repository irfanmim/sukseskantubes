#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "point.h"
#include "peta.h"
#include "player.h"
#include "boolean.h"

/* List Fungsi dan Prosedur untuk digunakan pada main program*/
void Converter(unsigned char CC);
void InsertStats (unsigned char* CC, player P, int B);
void MakeTable(unsigned char* kata, int A, int B);

int main()
{
	/* KAMUS */
	boolean validasi;
	int q, r, ui, uj;
	PETA P;
	player Utama, Enemy[3];
	unsigned char mapu[1000][1000], space;

	/* ALGORITMA */
	printf("Masukkan ukuruan layar:\n");
	printf("Ukuran Lebar minimal adalah 40 dan Panjang minimal 70\n");

	do
	{
		printf("Lebar layar : "); scanf("%d", &ui);
		if (ui < 40)
		{
			printf("Ukuran Lebar minimal adalah 40!!\n");
		}
	} while (ui < 40);

	do
	{
		printf("Panjang layar : "); scanf("%d", &uj);
		if (uj < 70)
		{
			printf("Ukuran Panjang minimal adalah 70!!\n");
		}
	} while (uj < 70);

	unsigned char kata[ui][uj];
	MakeTable(kata, ui, uj);
	
	printf("Masukkan nama kamu: "); scanf("%c",&space); gets(NAME(Utama));

	for (q = 0; q < ui; ++q)
	{
		for (r = 0; r < uj; ++r)
		{
			Converter(kata[q][r]);
		}
		printf("\n");
	}

	int i, tanda = 0, found = 0;
	int CCeff = ui;
	tanda = 2;
	i = 0;

	GeneratePeta(&P, 29, 29);
	PrintPeta(P); printf("\n");
	int mapueff = 29;
	int tengahp = (tanda+CCeff-mapueff)/2, tengahl = (uj-29+1)/2;
	int j;
	for (i = tengahp; i < tengahp+mapueff+1; ++i)
	{
		for (j = tengahl; j < tengahl+30; ++j)
		{
			kata[i][j] = Letak(P, i-tengahp, j-tengahl);
		}		
	}

	for (q = 0; q < ui; ++q)
	{
		for (r = 0; r < uj; ++r)
		{
			Converter(kata[q][r]);
		}
		printf("\n");
	}
	
	X(Utama) = j;
	Y(Utama) = i;
	HP(Utama) = 1;
	HPMAX(Utama) = 9999;
	STR(Utama) = 999;
	DEF(Utama) = 999;
	LVL(Utama) = 100;
	InsertStats(kata, Utama, uj);

	for (q = 0; q < ui; ++q)
	{
		for (r = 0; r < uj; ++r)
		{
			Converter(kata[q][r]);
		}
		printf("\n");
	}
	
	srand(time(NULL));
	i = rand();
	srand(i);
	j = rand() % 29 + tengahl;
	i = i % mapueff + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % 29 + tengahl;
	}
	kata[i][j] = 'P';
	X(Utama) = j;
	Y(Utama) = i;
	
	srand(time(NULL));
	i = rand();
	srand(i);
	j = rand() % 29 + tengahl;
	i = i % mapueff + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % 29 + tengahl;
	}
	kata[i][j] = 'M';
	int k;
	
	for (k = 0; k <= 2; ++k)
	{
		srand(time(NULL));
		i = rand();
		srand(i);
		j = rand() % 29 + tengahl;
		i = i % mapueff + tengahp;
		while (kata[i][j] != '-')
		{
			srand(j);
			++j;
			j = j % 29 + tengahl;
		}
		kata[i][j] = 'E';

		X(Enemy[k]) = j;
		Y(Enemy[k]) = i;
		STR(Enemy[k]) = 50;
		DEF(Enemy[k]) = 10;
		HP(Enemy[k]) = 20;

	}
	
	for (q = 0; q < ui; ++q)
	{
		for (r = 0; r < uj; ++r)
		{
			Converter(kata[q][r]);
		}
		printf("\n");
	}

	k = 3;
	unsigned char CC[2];
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
			InsertStats(kata, Utama, uj);
		}
		kata[Y(Utama)][X(Utama)] = 'P';
		system("clear");
	
		for (q = 0; q < ui; ++q)
		{
			for (r = 0; r < uj; ++r)
			{
				Converter(kata[q][r]);
			}
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

void MakeTable(unsigned char* AA, int A, int B)
{
	int i, j;
	for (i = 0; i < 1 && i < A; ++i)
	{
		AA[i*B] = (unsigned char) 201;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = (unsigned char) 205;
		}
		AA[i*B+j] = (unsigned char) 187;
	}

	for (; i < 2 && i < A; ++i)
	{
		AA[i*B] = (unsigned char) 186;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = ' ';
		}
		AA[i*B+j] = (unsigned char) 186;
	}

	for (; i < 3 && i < A; ++i)
	{
		AA[i*B] = (unsigned char) 204;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = (unsigned char) 205;
		}
		AA[i*B+j] = (unsigned char) 185;
	}
	for (; i < A-1; ++i)
	{
		AA[i*B] = (unsigned char) 186;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = ' ';
		}
		AA[i*B+j] = (unsigned char) 186;
	}
	for (i = A-1; i < A; ++i)
	{
		AA[i*B] = (unsigned char) 200;
		for (j = 1; j < B-1; ++j)
		{
			AA[i*B+j] = (unsigned char) 205;
		}
		AA[i*B+j] = (unsigned char) 188;
	}
}

void InsertStats (unsigned char* CC, player P, int B)
{
	int j, k;
	int i = 2;
	int temp = 0;

	for (j = i*B-3; j >= i*B-2-4; --j)
	{
		if (DEF(P) > 0)
		{
			temp = DEF(P)%10;
			CC[j] = (unsigned char) (temp + 48);
			DEF(P) /= 10;
		}
	}
	CC[j] = '=';
	CC[j-2] = 'F';
	CC[j-3] = 'E';
	CC[j-4] = 'D';
	CC[j-6] = (char) 186;
	CC[j-6-B] = (char) 203;
	CC[j-6+B] = (char) 202;
	j = j-8;
	k = j-3;
	for (; j >= k; --j)
	{
		if (STR(P) > 0)
		{
			temp = STR(P)%10;
			CC[j] = (unsigned char) (temp + 48);
			STR(P) /= 10;
		}
	}
	CC[j] = '=';
	CC[j-2] = 'R';
	CC[j-3] = 'T';
	CC[j-4] = 'S';
	CC[j-6] = (char) 186;
	CC[j-6-B] = (char) 203;
	CC[j-6+B] = (char) 202;
	j = j-8;
	k = j-3;
	for (; j >= k; --j)
	{
		if (HPMAX(P) > 0)
		{
			temp = HPMAX(P)%10;
			CC[j] = (unsigned char) (temp + 48);
			HPMAX(P) /= 10;
		}
	}
	CC[j] = '/';
	--j;
	k = j-4;
	for (; j >= k; --j)
	{
		if (HP(P) > 0)
		{
			temp = HP(P)%10;
			CC[j] = (unsigned char) (temp + 48);
			HP(P) /= 10;
		}
	}
	CC[j] = '=';
	CC[j-2] = 'P';
	CC[j-3] = 'H';
	CC[j-5] = (char) 186;
	CC[j-5-B] = (char) 203;
	CC[j-5+B] = (char) 202;
	j = j-7;
	k = j-3;
	for (; j >= k; --j)
	{
		if (LVL(P) > 0)
		{
			temp = LVL(P)%10;
			CC[j] = (unsigned char) (temp + 48);
			LVL(P) /= 10;
		}
	}
	CC[j] = '=';
	CC[j-2] = 'L';
	CC[j-3] = 'V';
	CC[j-4] = 'L';
	CC[j-6] = (char) 186;
	CC[j-6-B] = (char) 203;
	CC[j-6+B] = (char) 202;
	k = j-8;
	CC[B+2] = 'N';
	CC[B+3] = 'A';
	CC[B+4] = 'M';
	CC[B+5] = 'E';
	CC[B+7] = '=';
	j = B+9;
	temp = strlen(NAME(P));
	for (; j < (temp+B+9) && j < k; ++j)
	{
		CC[j] = NAME(P)[j-B-9];
	}
}

void Converter (unsigned char CC)
{
	if ((int) CC == 185)
	{
		printf("\u2563");
	}
	else if ((int) CC == 186)
	{
		printf("\u2551");
	}
	else if ((int) CC == 187)
	{
		printf("\u2557");
	}
	else if ((int) CC == 188)
	{
		printf("\u255D");
	}
	else if ((int) CC == 200)
	{
		printf("\u255A");
	}
	else if ((int) CC == 201)
	{
		printf("\u2554");
	}
	else if ((int) CC == 202)
	{
		printf("\u2569");
	}
	else if ((int) CC == 203)
	{
		printf("\u2566");
	}
	else if ((int) CC == 204)
	{
		printf("\u2560");
	}
	else if ((int) CC == 205)
	{
		printf("\u2550");
	}
	else
	{
		printf("%c", CC);
	}
}