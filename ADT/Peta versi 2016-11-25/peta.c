#include <stdlib.h>
#include <time.h>
#include "peta.h"
#include "point.h"
#include "custring.h"

void MakePeta(int LB, int PNJ, PETA *P)
{
    LebarPeta(*P) = LB;
    PanjangPeta(*P) = PNJ;
}

void ReadPeta(PETA *P, str filetxt)
{
    FILE *source;
    source = fopen(filetxt,"r");
    int i = 0;
    do
    {
        fgets((*P).peta[i], CharMax, source);
        ++i;
    } while (!feof(source));
    MakePeta(i, strlen((*P).peta[0]), P);
    fclose(source);
}

void PrintPeta(PETA P)
{
    int i, j;
    for (i = 0; i < LebarPeta(P)-1; i++)
    {
        for (j = 0; j < PanjangPeta(P)-1; j++)
        {
            if ((j == PanjangPeta(P) - 2) && (i == LebarPeta(P) - 2))
            {
                printf("%c",Letak(P,i,j));
			}
            
            else if (j == PanjangPeta(P) - 2)
            {
                printf("%c",Letak(P,i,j));
				printf("\n");
			}
            
            else
            {
				printf("%c ",Letak(P,i,j));
			}
        }
    }
}

void PutarPeta(PETA *P)
{
    int i, j, k;
    PETA Pt;
    MakePeta(PanjangPeta(*P), LebarPeta(*P), &Pt);
    for (i = LBMin; i < LebarPeta(*P); i++)
    {
        for (j = PNJMin; j < PanjangPeta(*P); j++)
        {
            k = LebarPeta(*P)-i-1;
            Letak(Pt,j,k) = Letak(*P,i,j);
        }
    }
    *P = Pt;
}

void CopyPETA (PETA P, PETA *P1)
{
    *P1 = P;
}

void GeneratePeta(PETA *P, int LB, int PNJ)
{
    MakePeta(LB,PNJ,P);
    time_t t;
    srand((unsigned) time(&t));
    int i,j,random;
    for (i = LBMin; i <= LebarPeta(*P); i++)
    {
        for (j = PNJMin; j <= PanjangPeta(*P); j++)
        {
            random = rand() % 3;
            if ((random == 0) || j == PNJMin || j == PanjangPeta(*P) || i == LBMin || i == LebarPeta(*P)) 
                Letak(*P,i,j) = '#';
            else
                Letak(*P,i,j) = '-';
        }
    }
    
    POINT atas,bawah,kiri,kanan;
    char up,down,left,right;

    for (i = LBMin; i <= LebarPeta(*P); i++)
    {
        for (j = PNJMin; j <= PanjangPeta(*P); j++)
        {
            if (i == LBMin)
                Ordinat(atas) = LebarPeta(*P);
            else
                Ordinat(atas) = i-1;
            Absis(atas) = j;
            up = Letak(*P,Ordinat(atas),Absis(atas));

            if (i == LebarPeta(*P))
                Ordinat(bawah) = LBMin;
            else
                Ordinat(bawah) = i+1;
            Absis(bawah) = j;
            down = Letak(*P,Ordinat(bawah),Absis(bawah));

            if (j == PNJMin)
                Absis(kiri) = PanjangPeta(*P);
            else
                Absis(kiri) = j-1;
            Ordinat(kiri) = i;
            left = Letak(*P,Ordinat(kiri),Absis(kiri));

            if (j == PanjangPeta(*P))
                Absis(kanan) = PNJMin;
            else
                Absis(kanan) = j+1;
            Ordinat(kanan) = i;
            right = Letak(*P,Ordinat(kanan),Absis(kanan));

            if (Letak(*P,i,j) == '-')
            {
                if ((up == '#') && (down == '#') && (left == '#') && (right == '#'))
                    Letak(*P,i,j) = '#';
            }
        }
    }
}

void BreakdownPeta(PETA P,indeks Y, indeks X)
{
    int gridL, gridP,i,j;
    gridL = Y / 10 * 10;
    gridP = X / 10 * 10;
    for (i = gridL; i <= (gridL+9); i++)
    {
        for (j = gridP; j <= (gridP+9); j++)
        {
            if ((j == (gridP+9)) && (i == (gridL+9)))
            {
                printf("%c",Letak(P,i,j));
            }
            else if (j == (gridP+9))
            {
                printf("%c",Letak(P,i,j));
                printf("\n");
            }
            else
            {
                printf("%c ",Letak(P,i,j));
            }
        }
    }
}

boolean IsUkuranSama (PETA P1, PETA P2)
{
    return ((LebarPeta(P1) == LebarPeta(P2)) && (PanjangPeta(P1) == PanjangPeta(P2)));
}

boolean IsPetaSama (PETA P1, PETA P2)
{
    if (!IsUkuranSama(P1,P2))
    {
        return false;
    }
    else
    {
        int i, j;
        boolean found = true;
        i = LebarPeta(P1);
        while (i <= LebarPeta(P1) && found)
        {
            j = PanjangPeta(P1);
            while (j <= PanjangPeta(P1) && found)
            {
                if (Letak(P1,i,j) != Letak(P2,i,j))
                {
					found = false;
				}
                ++j;
            }
        ++i;
        }
        return found;
    }
}

boolean isDinding (PETA P, POINT T)
{
	return (Letak(P,Ordinat(T),Absis(T)) == '#');
}

boolean isEnemy (PETA P, POINT T)
{
	return (Letak(P,Ordinat(T),Absis(T)) == 'E');
}

boolean isMedicine (PETA P, POINT T)
{
	return (Letak(P,Ordinat(T),Absis(T)) == 'M');
}

boolean SearchKolom (PETA P, int j, char CC)
{
    boolean found = false;
    int i = 0;
    while (!found && i < LebarPeta(P))
    {
        if (Letak(P,i,j) == CC)
        {
            found = true;
        }
        else
        {
            ++i;
        }
    }
    return found;
}

boolean SearchBaris (PETA P, int i, char CC)
{
    boolean found = false;
    int j = 0;
    while (!found && j < LebarPeta(P))
    {
        if (Letak(P,i,j) == CC)
        {
            found = true;
        }
        else
        {
            ++j;
        }
    }
    return found;
}