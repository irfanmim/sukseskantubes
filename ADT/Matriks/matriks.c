// Nama/NIM		: Faiz Ghifari Haznitrama/13515010
// Tanggal		: Kamis, 15 September 2016
// Nama file	: matriks.c
// Topik		: ADT Matriks Statis-Eksplisit
// Deskripsi	: Membuat ADT Matriks-Statis berbentuk eksplisit

#include "matriks.h"
#include <stdio.h>

/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
    if (((i < 1) || (i > 100)) || ((j < 1) || (j > 100)))
        return false;
    else
        return true;
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
    return (NBrsEff(M) + GetFirstIdxBrs(M)- 1);
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
    return (NKolEff(M) + GetFirstIdxKol(M) - 1);
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    if (((i < GetFirstIdxBrs(M)) || (i > GetLastIdxBrs(M))) || ((j < GetFirstIdxKol(M)) || (j > GetLastIdxKol(M))))
        return false;
    else
        return true;
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return Elmt(M,i,i);
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    *MHsl = MIn;
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    int i,j;
    MakeMATRIKS(NB,NK,M);
    for(i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            scanf("%c",&Elmt(*M,i,j));
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M){
    int i,j;
    for(i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
        for(j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
            if ((j == GetLastIdxKol(M)) && (i == GetLastIdxBrs(M)))
                printf("%c",Elmt(M,i,j));
            else if (j == GetLastIdxKol(M))
                printf("%c\n",Elmt(M,i,j));
            else
                printf("%c",Elmt(M,i,j));
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
    if (!EQSize(M1,M2)){
        return false;
    } else {
        int i,j; boolean found = true;
        i = GetFirstIdxBrs(M1);
        while (i <= GetLastIdxBrs(M1) && found){
            j = GetFirstIdxKol(M1);
            while (j <= GetLastIdxKol(M1) && found){
                if (Elmt(M1,i,j) != Elmt(M2,i,j))
                    found = false;
                j++;
            }
        i++;
        }
        return found;
    }
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2){
    return (!EQ(M1,M2));
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
    return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M1) == NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
    return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
    return (NBrsEff(M) == NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
    if (!IsBujurSangkar(M))
        return false;
    else {
        MATRIKS MTp;
        CopyMATRIKS(M,&MTp);
        Transpose(&MTp);
        return (EQ(M,MTp));
    }
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */


void Transpose (MATRIKS * M){
    int i,j,temp; MATRIKS MTp;
    MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&MTp);
    for(i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            Elmt(MTp,j,i) = Elmt(*M,i,j);
        }
    }
    *M = MTp;
}

int CountXBrs (MATRIKS M, indeks i, ElType X){
	int j, count; count = 0;
	for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++){
		if (Elmt(M,i,j) == X)
		count++;
	}
	return count;
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int CountXKol (MATRIKS M, indeks j, ElType X){
	int i, count; count = 0;
	for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++){
		if (Elmt(M,i,j) == X)
		count++;
	}
	return count;
}
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */

void PutarMatriks(MATRIKS *M){
    int i,j,k; MATRIKS Mp;
    MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&Mp);
    for(i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++){
        for(j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);j++){
            k = GetLastIdxKol(*M)-i+1;
            Elmt(Mp,j,k) = Elmt(*M,i,j);
        }
    }
    *M = Mp;
}
