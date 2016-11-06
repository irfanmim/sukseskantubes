#include "peta.h"

void MakePeta(int LB, int PNJ, PETA *P){
    LebarPeta(*P) = LB;
    PanjangPeta(*P) = PNJ;
}

void ReadPeta(FILE *source,PETA *P,str filetxt){
    source = fopen(filetxt,"r");
    int i = 0;
    while (!feof(source)){
        fgets((*P).peta[i],CharMax,source);
        i++;
    }
    fclose(source);
}

void PrintPeta(PETA P){
    int i,j;
    for(i=LBMin;i<=LebarPeta(P);i++){
        for(j=PNJMin;j<=PanjangPeta(P);j++){
            if ((j == PanjangPeta(P)) && (i == LebarPeta(P)))
                printf("%c",Posisi(P,i,j));
            else if (j == PanjangPeta(P))
                printf("\n");
            else
                printf("%c ",Posisi(P,i,j));
        }
    }
}

void PutarPeta(PETA *P){
    int i,j,k; PETA Pt;
    MakePeta(PanjangPeta(*P),LebarPeta(*P),&Pt);
    for(i=LBMin;i<LebarPeta(*P);i++){
        for(j=PNJMin;j<PanjangPeta(*P);j++){
            k = LebarPeta(*P)-i-1;
            Posisi(Pt,j,k) = Posisi(*P,i,j);
        }
    }
    *P = Pt;
}
