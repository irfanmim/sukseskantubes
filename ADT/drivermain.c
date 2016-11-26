#include <stdio.h>
#include <stdlib.h>
#include <time.h>	
#include "boolean.h"
#include "custring.h"
#include "graph.h"
#include "point.h"
#include "peta.h"
#include "player.h"
#include "soqlist.h"

/* List Fungsi dan Prosedur untuk digunakan pada main program*/
void Converter (unsigned char CC);
void InsertMaps (unsigned char* CC, PETA P);
void InsertStats (unsigned char* CC, player P, int B);
void MakeTable (unsigned char* CC, int A, int B);
void MakeStack (Stack *st);
void PrintLayar (unsigned char* CC);
void DeretPrima ();

/* KAMUS GLOBAL */
int ui, uj;
unsigned char kata[100][100];
long int prima[50001];

int main()
{
	system("clear");

	/* KAMUS */
	adrNode Pr;
	int q, s = 0;
	Graph G;
	PETA P[10];
	player Utama, Enemy[3];
	unsigned char space;

	char nana[] = "List Peta.txt";
	FILE *listed;
	listed = fopen(nana,"r");
	while (!feof(listed))
	{
		char bin[10], bins[10];
		fgets(bin, 10, listed);
		sscanf(bin, "%s", bins);
		Strcat(bins,".txt");
		ReadPeta(&P[s], bins);
		++s;
	}
	
	CreateGraph(0, MakePOINT(0,0), &G);
	
	for (q = 0; q < s; ++q)
	{
		if (SearchKolom(P[q], LebarPeta(P[q])-1, '-'))
		{
			InsertNode(&G, q, FindKolom(P[q], LebarPeta(P[q])-1, '-'), &Pr);
		}
		if (SearchKolom(P[q], 0, '-'))
		{
			InsertNode(&G, q, FindKolom(P[q],0,'-'), &Pr);
		}
		if (SearchBaris(P[q], PanjangPeta(P[q])-1, '-'))
		{
			InsertNode(&G, q, FindBaris(P[q], PanjangPeta(P[q])-1, '-'), &Pr);
		}
		if (SearchBaris(P[q], 0, '-'))
		{
			InsertNode(&G, q, FindBaris(P[q], 0, '-'), &Pr);
		}
	}
	
	InsertEdge(&G, 0, FindBaris(P[0], PanjangPeta(P[0])-1, '-'), 1, FindBaris(P[1], 0, '-'));
	InsertEdge(&G, 1, FindBaris(P[1], 0, '-'), 0, FindBaris(P[0], PanjangPeta(P[0])-1, '-'));
	if (SearchEdge(G, 0, FindBaris(P[0], PanjangPeta(P[0])-1, '-'), 1, FindBaris(P[1], 0, '-')))
	{
		printf("Done\n");
		printf("%d %d ",Absis(FindBaris(P[0], PanjangPeta(P[0])-1, '-')), Ordinat(FindBaris(P[0], PanjangPeta(P[0])-1, '-')));
		printf("%d %d",Absis(FindBaris(P[1], 0, '-')), Ordinat(FindBaris(P[1], 0, '-')));
	}
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


	MakeTable(kata, ui, uj);
	
	printf("Masukkan nama kamu: "); scanf("%c",&space); gets(NAME(Utama));

	system("clear");

	int i = 0;
	int j;

	/* RANDOM AWAL UNTUK LOKASI PLAYER */
	i = rand()%LebarPeta(P[0]);
	j = rand()%PanjangPeta(P[0]);

	while (!SearchKolom(P[0], i, '-'))
	{
		++i;
	}

	while (Letak(P[0],i,j) != '-')
	{
		srand(j*time(NULL));
		j = rand();
		j %= PanjangPeta(P[0]);
	}

	Letak(P[0],i,j) = 'P';
	X(Utama) = j;
	Y(Utama) = i;
	HP(Utama) = 100;
	HPMAX(Utama) = 100;
	STR(Utama) = 999;
	DEF(Utama) = 999;
	LVL(Utama) = 100;	
	InsertStats(kata, Utama, uj);


	/* RANDOM UNTUK LOKASI MEDICINE */
	int l;
	for (l = 0; l <= 2; ++l)
	{
		i = rand()%LebarPeta(P[0]);
		j = rand()%PanjangPeta(P[0]);

		while (!SearchBaris(P[0], j, '-'))
		{
			++j;
		}

		while (Letak(P[0],i,j) != '-')
		{
			srand(i*time(NULL));
			++i;
			i %= LebarPeta(P[0]);
		}
		Letak(P[0],i,j) = 'M';
	}

	/* RANDOM UNTUK LOKASI ENEMY */
	for (l = 0; l <= 2; ++l)
	{
		i = rand()%LebarPeta(P[0]);
		j = rand()%PanjangPeta(P[0]);

		while (!SearchBaris(P[0], j, '-'))
		{
			++j;
			j %= PanjangPeta(P[0]);
		}

		while (Letak(P[0],i,j) != '-')
		{
			srand(i*time(NULL));
			++i;
			i %= LebarPeta(P[0]);
		}

		Letak(P[0],i,j) = 'E';
		InsertMaps(kata, P[0]);
		X(Enemy[l]) = j;
		Y(Enemy[l]) = i;
		STR(Enemy[l]) = 50+10*l*pow(-1,l);
		DEF(Enemy[l]) = 10+10*l*pow(-1,l+1);
		HP(Enemy[l]) = 20+10*l*pow(-1,l);
		HPMAX(Enemy[l]) = 20+10*l*pow(-1,l+1);
		LVL(Enemy[l]) = 1;
		EXP(Enemy[l]) = 0;
		if (l==1)
		{
			Strcat(NAME(Enemy[l]),"Agung");
		}
		else if (l==2)
		{
			Strcat(NAME(Enemy[l]),"Yos");
		}
		else
		{
			Strcat(NAME(Enemy[l]),"Jau cups");
		}
	}	
	
	PrintLayar(kata);
	int k = 3;
	POINT initial;
	unsigned char CC[2];
	i = 0;
	while (k != 0)
	{
		gets(CC);
		Ordinat(initial) = X(Utama);
		Absis(initial) = Y(Utama);

		Letak(P[i],Y(Utama),X(Utama)) = '-';
		
		if (Strcmp(CC, "GD"))
		{
			GerakBawah(&Posisi(Utama));
			if (!isPath(P[i], Posisi(Utama)))
			{
				if (Letak(P[i],Y(Utama),X(Utama)) == '\0')
				{
					j = 0;
					while (j < 5)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindKolom(P[j], 0, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindKolom(P[j], 0, '-');
							i = j;
						}
					}
				}
				else
				{
					GerakAtas(&Posisi(Utama));
				}
			}
		}
		else if (Strcmp(CC, "GU"))
		{
			GerakAtas(&Posisi(Utama));
			if (!isPath(P[i], Posisi(Utama)))
			{
				if (Letak(P[i],Y(Utama),X(Utama)) == '\0')
				{
					j = 0;
					while (j < 5)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindKolom(P[j], LebarPeta(P[j])-1, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindKolom(P[j], LebarPeta(P[j])-1, '-');
							i = j;
						}
					}
					if (j >= 6)
					{
						GerakBawah(&Posisi(Utama));
					}
				}
				else
				{
					GerakBawah(&Posisi(Utama));
				}
			}

		}

		else if (Strcmp(CC, "GL"))
		{
			GerakKiri(&Posisi(Utama));
			if (!isPath(P[i], Posisi(Utama)) || X(Utama) < 0)
			{
				if (X(Utama) < 0)
				{
					GerakKanan(&Posisi(Utama));
					j = 0;
					while (j < 5)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindBaris(P[j], PanjangPeta(P[j])-1, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindBaris(P[j], PanjangPeta(P[j])-1, '-');
							Letak(P[j],Y(Utama), X(Utama)) = 'P';
							MakeTable(kata, ui, uj);
							InsertStats(kata, Utama, uj);
							i = j;
						}
					}
				}
				else
				{
					GerakKanan(&Posisi(Utama));
				}
			}
		}

		else if (Strcmp(CC, "GR"))
		{
			GerakKanan(&Posisi(Utama));
			if (!isPath(P[i], Posisi(Utama)) || X(Utama) >= PanjangPeta(P[i]))
			{
				if (X(Utama) >= PanjangPeta(P[i]))
				{
					GerakKiri(&Posisi(Utama));
					j = 0;
					while (j < 5)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindBaris(P[j], 0, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindBaris(P[j], 0, '-');
							Letak(P[j], Y(Utama), X(Utama)) = 'P';
							MakeTable(kata, ui, uj);
							InsertStats(kata, Utama, uj);
							i = j;
						}
					}
				}
				else
				{
					GerakKiri(&Posisi(Utama));
				}
			}
		}


		if (Letak(P[i], Y(Utama), X(Utama)) == 'M')
		{
			RestoredHP(&Utama);
			InsertStats(kata, Utama, uj);
		}
		
		else if (Letak(P[i], Y(Utama), X(Utama)) == 'E')
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
			BattleOn(&Utama, Enemy[z], yuhu, &win);
			InsertStats(kata, Utama, uj);
			if (win)
			{
				Letak(P[i], Y(Utama), X(Utama)) = 'P';
			}
			else
			{
				if (isDeath(Utama))
				{
					break;
				}

				else
				{
					X(Utama) = Ordinat(initial);
					Y(Utama) = Absis(initial);
				}
			}
		}
		
		else
		{
			Letak(P[i], Y(Utama), X(Utama)) = 'P';			
		}
		
		Letak(P[i],Y(Utama),X(Utama)) = 'P';
		system("clear");
		InsertMaps(kata, P[i]);
		PrintLayar(kata);
	
	}
	system("clear");
	return 0;
}

void MakeTable(unsigned char* CC, int A, int B)
{
	int i, j;
	for (i = 0; i < 1 && i < A; ++i)
	{
		CC[i*B] = (unsigned char) 201;
		for (j = 1; j < B-1; ++j)
		{
			CC[i*B+j] = (unsigned char) 205;
		}
		CC[i*B+j] = (unsigned char) 187;
	}

	for (; i < 2 && i < A; ++i)
	{
		CC[i*B] = (unsigned char) 186;
		for (j = 1; j < B-1; ++j)
		{
			CC[i*B+j] = ' ';
		}
		CC[i*B+j] = (unsigned char) 186;
	}

	for (; i < 3 && i < A; ++i)
	{
		CC[i*B] = (unsigned char) 204;
		for (j = 1; j < B-1; ++j)
		{
			CC[i*B+j] = (unsigned char) 205;
		}
		CC[i*B+j] = (unsigned char) 185;
	}
	for (; i < A-1; ++i)
	{
		CC[i*B] = (unsigned char) 186;
		for (j = 1; j < B-1; ++j)
		{
			CC[i*B+j] = ' ';
		}
		CC[i*B+j] = (unsigned char) 186;
	}
	for (i = A-1; i < A; ++i)
	{
		CC[i*B] = (unsigned char) 200;
		for (j = 1; j < B-1; ++j)
		{
			CC[i*B+j] = (unsigned char) 205;
		}
		CC[i*B+j] = (unsigned char) 188;
	}
}

void InsertMaps (unsigned char* CC, PETA P)
{
	int i, tanda = 0;
	int CCeff = ui;
	tanda = 2;
	i = 0;
	int tengahp = (tanda+CCeff-LebarPeta(P)+2)/2, tengahl = (uj-PanjangPeta(P)+4)/2;
	int j;
	
	for (i = tengahp; i < tengahp+LebarPeta(P); ++i)
	{
		for (j = tengahl; j < tengahl+PanjangPeta(P); ++j)
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
    while(z <= 10)
    {
    	CreateEmptyQueue(&temp);
		for (i = 1; i <= 4; i++)
		{
			srand(time(NULL)*z*i);
			srand((rand()*13)+401*i);
			srand(rand()*101*z-i*z*z);
			srand(rand()*i*11);
    		r = rand() % 8;

			if(r == 0 || r == 4 || r == 5)
			{
				Add(&temp,'A');	
			}
			else if(r == 3 || r == 1 || r == 7)
			{
				Add(&temp,'F');
			}
			else if(r == 2 || r == 6)
			{
				Add(&temp,'B');
			}
		}
		Push(st,temp);
		z++;
    }
}

void PrintLayar (unsigned char* CC)
{
	int i, j;
	for (i = 0; i < ui; ++i)
	{
		for (j = 0; j < uj; ++j)
		{
			Converter(CC[uj*i+j]);
		}
		printf("\n");
	}
}

void DeretPrima ()
{
	long i, N = 50001;
	boolean a[50001];
	prima[0] = 1;
	for (i = 2; i <= N; ++i)
	{
		a[i] = true;
	}
	long k = 1, j;
	for (i = 2; i <= N; ++i)
	{
		if (a[i] == true)
		{
			prima[k] = i;
			for (j = 2; j < floor(N/i) + 1; ++j)
			{
				a[i*j] = false;
			}
			++k;
		}
	}
}
