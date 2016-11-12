// NIM : 13515139
// Nama : Jehian Norman Saviero
// File : matriks.c
// Topik : Praktikum 04

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <math.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS *M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}


/* *** Selektor "DUNIA MATRIKS" *** */

boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	return ((BrsMin <= i) && (i <= BrsMax) && (KolMin <= j) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */

indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	return (BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	return (KolMin);
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	return (NBrsEff(M));
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	return (NKolEff(M));
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	return ((GetFirstIdxBrs(M) <= i) && (i <= GetLastIdxBrs(M)) && (GetFirstIdxKol(M) <= j) && (j <= GetLastIdxKol(M)));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS *MHsl)
/* Melakukan assignment MHsl  MIn */
{
	 int i,j;
	 MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
	 for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
	 	for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
	 		Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
	 	}
	 }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	int i,j;
	MakeMATRIKS(NB,NK,M);
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
			scanf("%c",&Elmt(*M,i,j));
		}
	}
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	int i,j;
	for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
		for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
			printf("%c ",Elmt(M,i,j));
		}
		printf("%c\n",Elmt(M,i,GetLastIdxKol(M)));
	}	
	i = GetLastIdxBrs(M);
	for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
		printf("%c ",Elmt(M,i,j));
	}
	printf("%c",Elmt(M,i,GetLastIdxKol(M)));
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
	boolean found = true;
	int i, j;
	if (NBElmt(M1)==NBElmt(M2))
	{
		i = GetFirstIdxBrs(M1);
		while (i <= GetLastIdxBrs(M1) && found)
		{
			j = GetLastIdxKol(M1);
			while (j <= GetLastIdxKol(M1) && found)
			{
				if (Elmt(M1,i,j) != Elmt(M2,i,j))
				{
					found = false;
				}
				else
				{
					++j;
				}
			}
			++i;
		}
		return found;
	}
	else
	{
		return (!found);
	}
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
	return (!EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
	return ((NBrsEff(M1) == NBrsEff(M2)) && (NKolEff(M2) == NKolEff(M1)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
	return (NBrsEff(M)*NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
	return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
	boolean found = true;
	int i, j;
	if (IsBujurSangkar(M))
	{
		i = GetFirstIdxBrs(M);
		while (i <= GetLastIdxBrs(M) && found )
		{
			j = GetFirstIdxKol(M);
			while (j <= GetLastIdxKol(M) && found)
			{
				if (Elmt(M,i,j)!=Elmt(M,j,i))
				{
					found = false;
				}
				++j;
			}
			++i;
		}
		return found;
	}
	else
	{
		return (!found);
	}	
}

void Transpose (MATRIKS *M)
/* I.S. M terdefinisi dan IsBujurSangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
	MATRIKS MM;
	int i,j;
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			Elmt(MM,i,j) = Elmt(*M,j,i);
		}
	}
	for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
	{
		for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
		{
			Elmt(*M,i,j) = Elmt(MM,i,j);
		}
	}	
}
