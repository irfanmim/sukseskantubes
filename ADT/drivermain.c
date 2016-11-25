#include <stdio.h>
#include <stdlib.h>
#include <time.h>	
#include "boolean.h"
#include "custring.h"
#include "point.h"
#include "peta.h"
#include "player.h"
#include "soqlist.h"

/* List Fungsi dan Prosedur untuk digunakan pada main program*/
void Converter (unsigned char CC);
void InsertMaps (unsigned char* CC, PETA P, int ui, int uj);
void InsertStats (unsigned char* CC, player P, int B);
void MakeTable (unsigned char* kata, int A, int B);
void MakeStack (Stack *st);

int main()
{
	system("clear");

	/* KAMUS */
	boolean validasi;
	int q, r, ui, uj;
	PETA P;
	player Utama, Enemy[3];
	unsigned char mapu[1000][1000], space;

	char yoho[] = "A.txt";
	ReadPeta(&P, yoho);
	PrintPeta(P);

	/* ALGORITMA */
	printf("Masukkan ukuruan layar:\n");
	printf("Ukuran Lebar minimal adalah 20 dan Panjang minimal 75\n");

	do
	{
		printf("Lebar layar : "); scanf("%d", &ui);
		if (ui < 20)
		{
			printf("Ukuran Lebar minimal adalah 20!!\n");
		}
	} while (ui < 20);

	do
	{
		printf("Panjang layar : "); scanf("%d", &uj);
		if (uj < 75)
		{
			printf("Ukuran Panjang minimal adalah 75!!\n");
		}
	} while (uj < 75);


	unsigned char kata[ui][uj];
	MakeTable(kata, ui, uj);
	
	printf("Masukkan nama kamu: "); scanf("%c",&space); gets(NAME(Utama));

	int i, tanda = 0, found = 0;
	int CCeff = ui;
	tanda = 2;
	i = 0;
	int tengahp = (tanda+CCeff-LebarPeta(P)+2)/2, tengahl = (uj-PanjangPeta(P)+4)/2;
	int j;
	
	InsertMaps (kata, P, ui, uj);

	X(Utama) = j;
	Y(Utama) = i;
	HP(Utama) = 1;
	HPMAX(Utama) = 10;
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
	j = rand() % PanjangPeta(P) + tengahl;
	i = i % LebarPeta(P) + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % PanjangPeta(P) + tengahl;
	}
	kata[i][j] = 'P';
	X(Utama) = j;
	Y(Utama) = i;

	srand(time(NULL));
	i = rand();
	srand(i);
	j = rand() % PanjangPeta(P) + tengahl;
	i = i % LebarPeta(P) + tengahp;
	while (kata[i][j] != '-')
	{
		srand(j);
		++j;
		j = j % PanjangPeta(P) + tengahl;
	}
	kata[i][j] = 'M';
	int k;
	
	for (k = 0; k <= 2; ++k)
	{
		srand(time(NULL));
		i = rand();
		srand(i);
		j = rand() % PanjangPeta(P) + tengahl;
		i = i % LebarPeta(P) + tengahp;
		while (kata[i][j] != '-')
		{
			srand(j);
			++j;
			j = j % PanjangPeta(P) + tengahl;
		}
		kata[i][j] = 'E';

		X(Enemy[k]) = j;
		Y(Enemy[k]) = i;
		STR(Enemy[k]) = 50;
		DEF(Enemy[k]) = 10;
		HP(Enemy[k]) = 20;
		HPMAX(Enemy[k]) = 20;
		LVL(Enemy[k]) = 1;
		EXP(Enemy[k]) = 0;
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
		if (Strcmp(CC, "GD") && (kata[Y(Utama)+1][X(Utama)] == '-' || kata[Y(Utama)+1][X(Utama)] == 'M' || kata[Y(Utama)+1][X(Utama)] == 'E'))
		{
			GerakBawah(&Posisi(Utama));
		}
		else if (Strcmp(CC, "GU") && (kata[Y(Utama)-1][X(Utama)] == '-' || kata[Y(Utama)-1][X(Utama)] == 'M' || kata[Y(Utama)-1][X(Utama)] == 'E'))
		{
			GerakAtas(&Posisi(Utama));
		}
		else if (Strcmp(CC, "GL") && (kata[Y(Utama)][X(Utama)-1] == '-' || kata[Y(Utama)][X(Utama)-1] == 'M' || kata[Y(Utama)][X(Utama)-1] == 'E'))
		{
			GerakKiri(&Posisi(Utama));
		}
		else if (Strcmp(CC, "GR") && (kata[Y(Utama)][X(Utama)+1] == '-' || kata[Y(Utama)][X(Utama)+1] == 'M' || kata[Y(Utama)][X(Utama)+1] == 'E'))
		{
			GerakKanan(&Posisi(Utama));
		}
		if (kata[Y(Utama)][X(Utama)] == 'M')
		{
			RestoredHP(&Utama);
			InsertStats(kata, Utama, uj);
			kata[Y(Utama)][X(Utama)] = 'P';
		}
		else if (kata[Y(Utama)][X(Utama)] == 'E')
		{
			int z = 0;
			boolean found = false, win;
			Stack yuhu;
			CreateEmpty(&yuhu);
			MakeStack(&yuhu);
			while (z < k && !found)
			{
				found = (X(Utama) == X(Enemy[z]) && Y(Utama) == Y(Enemy[z]));
				++z;
			}
			--z;
			BattleOn(&Utama, Enemy[1], yuhu, &win);
			printf("%d", HP(Utama));
			InsertStats(kata, Utama, uj);
			if (win)
			{
				kata[Y(Utama)][X(Utama)] = 'P';
			}
		}
		else
		{
			kata[Y(Utama)][X(Utama)] = 'P';			
		}
		system("clear");
	
		for (q = 0; q < ui; ++q)
		{
			for (r = 0; r < uj; ++r)
			{
				Converter(kata[q][r]);
			}
			printf("\n");
		}	
	}
	system("clear");
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

void InsertMaps (unsigned char* CC, PETA P, int ui, int uj)
{
	int i, tanda = 0, found = 0;
	int CCeff = ui;
	tanda = 2;
	i = 0;
	int tengahp = (tanda+CCeff-LebarPeta(P)+2)/2, tengahl = (uj-PanjangPeta(P)+4)/2;
	int j;
	
	for (i = tengahp; i < tengahp+LebarPeta(P)-1; ++i)
	{
		for (j = tengahl; j < tengahl+PanjangPeta(P)-2; ++j)
		{
			CC[i*uj+j] = Letak(P, i-tengahp, j-tengahl);
		}		
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
		else
		{
			CC[j] = ' ';
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
		else
		{
			CC[j] = ' ';
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
		else
		{
			CC[j] = ' ';
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
		else
		{
			CC[j] = ' ';
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
		else
		{
			CC[j] = ' ';
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


void MakeStack(Stack *st)
{
	int i,r,z;
	Queue temp;

    z = 1;
    while(z <= 10){
    	CreateEmptyQueue(&temp);
		for (int i = 1; i <= 4; i++)
		{
			srand(time(NULL)*z*i);
			srand((rand()*13)+401*i);
			srand(rand()*101*z-i*z*z);
			srand(rand()*i*11);
    		r = rand() % 8;

			if(r == 0 || r == 4 || r == 5){
				Add(&temp,'A');	
			}else if(r == 3 || r == 1 || r == 7){
				Add(&temp,'F');
			}else if(r == 2 || r == 6){
				Add(&temp,'B');
			}
		}
		Push(st,temp);
		z++;
    }
}