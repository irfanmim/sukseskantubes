#include <stdio.h>
#include <stdlib.h>
#include <time.h>	
#include "boolean.h"
#include "custring.h"
#include "graph.h"
#include "point.h"
#include "peta.h"
#include "player.h"
#include "stackt.h"
#include "soqlist.h"

/* List Fungsi dan Prosedur untuk digunakan pada main program*/
boolean NodeAvaible (Graph G, infotype q, POINT T);
void Converter (unsigned char CC);
void DeretPrima ();
void InsertMaps (unsigned char* CC, PETA P);
void InsertStats (unsigned char* CC, player P, int B);
void MakeTable (unsigned char* CC, int A, int B);
void MakeStack (Stack *st);
void PrintLayar (unsigned char* CC);
void RandomDeque (Deque *D);
void Randomize (PETA *P, int z, player *Enemy);

/* KAMUS GLOBAL */
boolean done[11];
int ui, uj;
long int prima[50];
unsigned char kata[100][100];

int main()
{
	system("clear");

	/* KAMUS */
	adrNode Pr;
	int q, r, rot = 0, s = 0;
	Deque D;
	jenis X;
	Graph G;
	FILE *listed;
	PETA P[11];
	player Utama, Enemy[60];
	unsigned char space;

	/* ALGORITMA */
	CreateDeque(&D);
	char nana[] = "List Peta.txt";
	listed = fopen(nana,"r");
	while (!feof(listed))
	{
		char bin[10], bins[10];
		fgets(bin, 10, listed);
		sscanf(bin, "%s", bins);
		Strcat(bins,".txt");
		ReadPeta(&P[s], bins);
		PushD(&D, P[s]);
		++s;
	}
	fclose(listed);

	/** MENDAFTARKAN SEMUA NODE-NODE YANG ADA PADA PETA **/
	CreateGraph(0, MakePOINT(0,0), &G);	
		
	/** MERANDOM URUTAN PETA **/


	RandomDeque(&D);
	s = 0;
	while (!IsDequeEmpty(D))
	{
		PopD(&D,&X);
		P[s] = X;
		++s;
	}
/*	printf("BUG\n");
		printf("BUG\n");
		printf("BUG\n");
		printf("BUG\n");
*/
	/** INISASI BELUM DI RANDOM **/
	for (r = 0; r < s; ++r)
	{
		done[r] = false;
	}

	/** MENAMBAHKAN EDGE PADA GRAPH **/
	r = 1;
	for (q = 0; q < s && r < s; ++q)
	{
		if (SearchKolom(P[q], LebarPeta(P[q])-1, '-') && r < s)
		{
			if (NodeAvaible(G, q, FindKolom(P[q], LebarPeta(P[q])-1, '-')))
			{
				rot = 0;
				while (!SearchKolom(P[r], 0, '-') && rot < 8)
				{
					PutarPeta(&P[r]);
					++rot;
				}
				if (rot < 8)
				{
					InsertEdge(&G, q, FindKolom(P[q], LebarPeta(P[q])-1, '-'), r, FindKolom(P[r], 0, '-'));
					InsertEdge(&G, r, FindKolom(P[r], 0, '-'), q, FindKolom(P[q], LebarPeta(P[q])-1, '-'));
					printf("TIPE A (%d,%d) -> (%d,%d) \n", Absis(FindKolom(P[q], LebarPeta(P[q])-1, '-')), Ordinat(FindKolom(P[q], LebarPeta(P[q])-1, '-')), Absis(FindKolom(P[r], 0, '-')), Ordinat(FindKolom(P[r], 0, '-')));
					++r;
					rot = 0;
				}
			}
		}
	
		if (SearchKolom(P[q], 0, '-') && r < s)
		{
			if (NodeAvaible(G, q, FindKolom(P[q], 0, '-')))
			{
				rot = 0;
				while (!SearchKolom(P[r], LebarPeta(P[r])-1, '-') && rot < 8)
				{
					PutarPeta(&P[r]);
					++rot;
				}
				if (rot < 8)
				{
					InsertEdge(&G, q, FindKolom(P[q], 0, '-'), r, FindKolom(P[r], LebarPeta(P[r])-1, '-'));
					InsertEdge(&G, r, FindKolom(P[r], LebarPeta(P[r])-1, '-'), q, FindKolom(P[q], 0, '-'));
					printf("TIPE B (%d,%d) -> (%d,%d) \n", Absis(FindKolom(P[q], 0, '-')), Ordinat(FindKolom(P[q], 0, '-')), Absis(FindKolom(P[r], LebarPeta(P[r])-1, '-')), Ordinat(FindKolom(P[r], LebarPeta(P[r])-1, '-')));
					++r;
					rot = 0;
				}
			}
		}
	
		if (SearchBaris(P[q], PanjangPeta(P[q])-1, '-') && r < s)
		{
			if (NodeAvaible(G, q, FindBaris(P[q], PanjangPeta(P[q])-1, '-')))
			{
				rot = 0;
				while (!SearchBaris(P[r], 0, '-') && rot < 8)
				{
					PutarPeta(&P[r]);
					++rot;
				}
				if (rot < 8)
				{
					InsertEdge(&G, q, FindBaris(P[q], PanjangPeta(P[q])-1, '-'), r, FindBaris(P[r], 0, '-'));
					InsertEdge(&G, r, FindBaris(P[r], 0, '-'), q, FindBaris(P[q], PanjangPeta(P[q])-1, '-'));
					printf("TIPE C (%d,%d) -> (%d,%d) \n", Absis(FindBaris(P[q], PanjangPeta(P[q])-1, '-')), Ordinat(FindBaris(P[q], PanjangPeta(P[q])-1, '-')), Absis(FindKolom(P[r], 0, '-')), Ordinat(FindKolom(P[r], 0, '-')));				
					++r;
					rot = 0;
				}
			}			
		}
	
		if (SearchBaris(P[q], 0, '-') && r < s)
		{
			if (NodeAvaible(G, q, FindBaris(P[q], 0, '-')))
			{
				rot = 0;
				while (!SearchBaris(P[r], PanjangPeta(P[r])-1, '-') && rot < 8)
				{
					PutarPeta(&P[r]);
					++rot;
				}
				if (rot < 8)
				{
					InsertEdge(&G, q, FindBaris(P[q], 0, '-'), r, FindBaris(P[r], PanjangPeta(P[r])-1, '-'));
					InsertEdge(&G, r, FindBaris(P[r], PanjangPeta(P[r])-1, '-'), q, FindBaris(P[q], 0, '-'));
					printf("TIPE D (%d,%d) -> (%d,%d) \n", Absis(FindBaris(P[q], 0, '-')), Ordinat(FindBaris(P[q], 0, '-')), Absis(FindBaris(P[r], PanjangPeta(P[r])-1, '-')), Ordinat(FindBaris(P[r], PanjangPeta(P[r])-1, '-')));				
					++r;
					rot = 0;
				}
			}
		}
	}

//	system("clear");
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
	SPt(Utama) = 0;
	InsertStats(kata, Utama, uj);
	InitSkillTree(&(STREE(Utama)));					// Inisialisasi daftar skill pemain
	SearchAndLearn(&(STREE(Utama)), "InitStatus");	// Learn root sebagai dasar pengambilan skill lain
	
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
	done[0] = true;
		
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
			if (!isPath(P[i], Posisi(Utama)) || Y(Utama) >= LebarPeta(P[i]))
			{
				if (Y(Utama) >= LebarPeta(P[i]))
				{
					GerakAtas(&Posisi(Utama));
					j = 0;
					while (j < s)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindKolom(P[j], 0, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindKolom(P[j], 0, '-');
							Letak(P[j], Y(Utama), X(Utama)) = 'P';
							MakeTable(kata, ui, uj);
							InsertStats(kata, Utama, uj);
							Randomize(&P[j], j, Enemy);
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
			if (!isPath(P[i], Posisi(Utama)) || Y(Utama) < 0)
			{
				if (Y(Utama) < 0)
				{
					GerakBawah(&Posisi(Utama));
					j = 0;
					while (j < s)
					{
						if (SearchEdge(G, i, Posisi(Utama), j, FindKolom(P[j], LebarPeta(P[j])-1, '-')) == Nil)
						{
							++j;
						}
						else
						{
							Posisi(Utama) = FindKolom(P[j], LebarPeta(P[j])-1, '-');
							Letak(P[j], Y(Utama), X(Utama)) = 'P';
							MakeTable(kata, ui, uj);
							InsertStats(kata, Utama, uj);
							Randomize(&P[j], j, Enemy);
							i = j;
						}
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
					while (j < s)
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
							Randomize(&P[j], j, Enemy);
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
					while (j < s)
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
							Randomize(&P[j], j, Enemy);
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
		else if(Strcmp(CC, "SKILL")) {
			printf("\nJumlah skill point : %d.\n\n Daftar Skill :\n", SPt(Utama));
			ShowSkill(STREE(Utama)); printf("\n");
			printf("Skill yang dapat dipelajari : \n");
			ShowAvailable(STREE(Utama));
		}	

		// SKILL AKTIF
		else if(Strcmp(CC, "InstantKill")) {
			if (IsLearnt(STREE(Utama), "InstantKill")) {
				if (Letak(P[i], (Y(Utama) + 1), X(Utama)) == 'E') {
					Letak(P[i], (Y(Utama)+1), X(Utama)) = '-';
				}
				else if (Letak(P[i], (Y(Utama) - 1), X(Utama)) == 'E') { 		// Jika musuh ada pada satu kotak di atas, bawah, kiri, atau kanan player,
					Letak(P[i], (Y(Utama) -1 ), X(Utama)) = '-';
				}
				else if (Letak(P[i], Y(Utama), (X(Utama) + 1)) == 'E') {		// maka akan diinstant-kill
					Letak(P[i], Y(Utama), (X(Utama) +1)) = '-';
				}
				else if (Letak(P[i], Y(Utama), (X(Utama) - 1)) == 'E') {
					Letak(P[i], Y(Utama), (X(Utama)-1)) = '-';
				}
				Learnt(SearchTree(&(STREE(Utama)), "InstantKill")) = false;		// InstantKill hanya bisa dipakai satu kali setiap kali telah dipelajari
			}
			else {
				for (int n = 1; n <= 32; n++) {
					printf("\n");
				}
				printf("\nKamu belum mempelajari skill \"InstantKill\"\n\n\n");
			}
		}
		
		if (Letak(P[i], Y(Utama), X(Utama)) == 'M')
		{
			RestoredHP(&Utama);
			InsertStats(kata, Utama, uj);
		}
		
		else if (Letak(P[i], Y(Utama), X(Utama)) == 'E')
		{
			int z = 3*i, temp = z+3;
			boolean found = false, win;
			Stack yuhu;
			CreateEmpty(&yuhu);
			MakeStack(&yuhu);
			while (z < temp && !found)
			{
				found = (X(Utama) == X(Enemy[z]) && Y(Utama) == Y(Enemy[z]));
				++z;
			}
			--z;
//			BattleOn(&Utama, Enemy[z], yuhu, &win);
			system("clear");
			BattleOn(&Utama, Enemy[z], yuhu, &win, uj, ui);
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

boolean NodeAvaible (Graph G, infotype q, POINT T)
{
	adrNode P = SearchNode(G, q, T);
	if (P != Nil)
	{
		return (Trail(P) == Nil);
	}
	else
	{
		return true;
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

void MakeTable (unsigned char* CC, int A, int B)
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

void RandomDeque (Deque *D)
{
	Deque temp1, temp2;
	jenis isi;
	CreateDeque(&temp1);
	CreateDeque(&temp2);
	srand(time(NULL));
	while (!IsDequeEmpty(*D))
	{
		int i, bin = rand()%Top(*D);
		for (i = 0; i < bin-1; ++i)
		{
			PopD(D, &isi);
			PushD(&temp1, isi);
		}
		PopD(D, &isi);
		PushD(&temp2, isi);
		InverseDeque(&temp2);
		while (!IsDequeEmpty(temp1))
		{
			InverseDeque(&temp1);
			PopD(&temp1, &isi);
			PushD(D, isi);
		}
		InverseDeque(D);
	}
	CopyDeque(temp2, D);
}

void Randomize (PETA *P, int z, player *Enemy)
{
	int i, j, l;
	if (!done[z])
	{
		for (l = 0; l <= 2; ++l)
		{
			i = rand()%LebarPeta(*P);
			j = rand()%PanjangPeta(*P);

			while (!SearchBaris(*P, j, '-'))
			{
				++j;
			}

			while (Letak(*P,i,j) != '-')
			{
				srand(i*time(NULL));
				++i;
				i %= LebarPeta(*P);
			}
			Letak(*P,i,j) = 'M';
		}

		for (l = 3*z; l <= 3*z+2; ++l)
		{
			i = rand()%LebarPeta(*P);
			j = rand()%PanjangPeta(*P);

			while (!SearchBaris(*P, j, '-'))
			{
				++j;
				j %= PanjangPeta(*P);
			}

			while (Letak(*P,i,j) != '-')
			{
				srand(i*time(NULL));
				++i;
				i %= LebarPeta(*P);
			}

			Letak(*P,i,j) = 'E';
			InsertMaps(kata, *P);
			X(Enemy[l]) = j;
			Y(Enemy[l]) = i;
			STR(Enemy[l]) = 50*+10*pow(-1,l);
			DEF(Enemy[l]) = 10+10*pow(-1,l+1);
			HP(Enemy[l]) = 20+10*pow(-1,l);
			HPMAX(Enemy[l]) = 20+10*pow(-1,l+1);
			LVL(Enemy[l]) = 1;
			EXP(Enemy[l]) = 0;
			if (l%7==1)
			{
				Strcat(NAME(Enemy[l]),"Agung");
			}
			else if (l%7==2)
			{
				Strcat(NAME(Enemy[l]),"Yos");
			}
			else if (l%7==3)
			{
				Strcat(NAME(Enemy[l]),"Jau cups");
			}
			else if (l%7==4)
			{
				Strcat(NAME(Enemy[l]),"Reiv");
			}
			else if (l%7==5)
			{
				Strcat(NAME(Enemy[l]),"Ziza");
			}
			else if (l%7==6)
			{
				Strcat(NAME(Enemy[l]),"Daria");
			}
		}
		done[z] = true;	
	}
}