#include "peta.h"

int main()
{
    FILE *namafile;
    PETA P;
    int Lebar = 10;
    int Panjang = 10;
    MakePeta(Lebar,Panjang,&P);
    str filetxt = "pitakar.txt";
    ReadPeta(namafile,&P,filetxt);
    PrintPeta(P);
    PutarPeta(&P);
    printf("\n");
    PrintPeta(P);
    return 0;
}
