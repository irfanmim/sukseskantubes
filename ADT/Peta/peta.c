#include "peta.h"

void MakePeta(int LB, int PNJ, PETA *P){
    LebarPeta(*P) = LB;
    PanjangPeta(*P) = PNJ;
}

void ReadPeta(FILE *source,PETA *P,str filetxt){
    source = fopen(filetxt,"r");
    int c = fgetc(source);
    int i = 0;
    while (c != EOF){
        fgets((*P).peta[i],CharMax,source);
        i++;
        c = fgetc(source);
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
                printf("%c\n",Posisi(P,i,j));
            else
                printf("%c ",Posisi(P,i,j));
        }
    }
}

void PutarPeta(PETA *P){
    int i,j,k; PETA Pt;
    MakePeta(LebarPeta(*P),PanjangPeta(*P),&Pt);
    for(i=LBMin;i<=LebarPeta(*P);i++){
        for(j=PNJMin;j<=PanjangPeta(*P);j++){
            k = PanjangPeta(*P)-i+1;
            Posisi(Pt,j,k) = Posisi(*P,i,j);
        }
    }
    *P = Pt;
}
