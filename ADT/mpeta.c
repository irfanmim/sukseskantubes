#include "peta.h"

int main()
{
    FILE *namafile;
    PETA P;
    int Lebar = 49;
    int Panjang = 49;
    //MakePeta(Lebar,Panjang,&P);
    //str filetxt = "pitakar.txt";
    //ReadPeta(namafile,&P,filetxt);
    GeneratePeta(&P,Lebar,Panjang);
    PrintPeta(P);
    printf("\n");
    BreakdownPeta(P,45,45);
    return 0;
}
