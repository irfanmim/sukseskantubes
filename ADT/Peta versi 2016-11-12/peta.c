#include "peta.h"
#include "point.h"

void MakePeta(int LB, int PNJ, PETA *P){
    LebarPeta(*P) = LB;
    PanjangPeta(*P) = PNJ;
}

void ReadPeta(FILE *source, PETA *P, str filetxt)
{
    source = fopen(filetxt,"r");
    int i = 0;
    while (!feof(source))
    {
        fgets((*P).peta[i], CharMax, source);
        ++i;
    }
    fclose(source);
}

void PrintPeta(PETA P)
{
    int i, j;
    for (i = LBMin; i <= LebarPeta(P); i++)
    {
        for (j = PNJMin; j <= PanjangPeta(P); j++)
        {
            if ((j == PanjangPeta(P)) && (i == LebarPeta(P)))
            {
                printf("%c",Posisi(P,i,j));
			}
            else if (j == PanjangPeta(P))
            {
				printf("\n");
			}
            else
			{
				printf("%c ",Posisi(P,i,j));
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
            Posisi(Pt,j,k) = Posisi(*P,i,j);
        }
    }
    *P = Pt;
}

void CopyPETA (PETA P, PETA *P1)
{
    *P1 = P;
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
                if (Posisi(P1,i,j) != Posisi(P2,i,j))
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
	return (Posisi(P,Ordinat(T),Absis(T)) == '#');
}

boolean isEnemy (PETA P, POINT T)
{
	return (Posisi(P,Ordinat(T),Absis(T)) == 'E');
}

boolean isMedicine (PETA P, POINT T)
{
	return (Posisi(P,Ordinat(T),Absis(T)) == 'M');
}
