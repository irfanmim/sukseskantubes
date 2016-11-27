#include "peta.h"

int main()
{
    PETA P;
    int Lebar = 0;
    int Panjang = 0;
    MakePeta(Lebar,Panjang,&P);
    str filetxt = "A.txt";
    ReadPeta(&P, filetxt);
    //GeneratePeta(&P,Lebar,Panjang);
    PrintPeta(P);
    printf("\n");
    //BreakdownPeta(P,45,45);
    return 0;
}
