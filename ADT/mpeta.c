#include "peta.h"

int main()
{
    FILE *namafile;
    PETA P;
    int Lebar = 50;
    int Panjang = 50;
    //MakePeta(Lebar,Panjang,&P);
    //str filetxt = "pitakar.txt";
    //ReadPeta(namafile,&P,filetxt);
    GeneratePeta(&P,Lebar,Panjang);
    PrintPeta(P);
    return 0;
}
