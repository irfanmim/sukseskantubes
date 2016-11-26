// Nama		 	: Martin Lutta Putra
// NIM 			: 13515121
// Tanggal 		: 12 November 2016
// Topik		: List Rekursif
// Deskripsi 	: ADT Pra-Praktikum 

#include "boolean.h"
#include "listrek.h"
#include <stdlib.h>
#include <stdio.h>
/* *** Manajemen Memori *** */
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	// Kamus
	address P;
	
	// Algoritma
	P = (ElmtList *) malloc (sizeof(ElmtList));
	if (P != NULL) {
		Info(P) = X;
		Next(P) = Nil;
	}
	else {
		P = Nil;
	}
	
	return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}
	
	
/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi List */
int IsEmpty(List L)
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
{
	if (L == Nil) {
		return 1;
	}
	else {
		return 0;
	}
}
int IsOneElmt(List L)
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
{
	if (IsEmpty(L)) {
		return 0;
	}
	else {
		if (Next(L) == Nil) {
			return 1;
		}
		else {
			return 0;
		}

	}
}
/* *** Selektor *** */
infotype FirstElmt (List L)
/* Mengirimkan elemen pertama sebuah list L yang tidak kosong */
{
	return (Info(L));
}

List Tail(List L)
/* Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong */
{
	return(Next(L));
}
/* *** Konstruktor *** */
List Konso(infotype e, List L)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
{
	// Kamus
	address P;
	
	// Algoritma
	P = Alokasi(e);
	if (P == Nil) {
		return L;
	}
	else {
		Next(P) = L;
		return P;
	}
	
}
List KonsB(List L, infotype e)
/* Mengirimkan list L dengan tambahan e sebagai elemen pertamanya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 
{
	
	// Kamus
	address P;
	
	// Algoritma
	P = Alokasi(e);
	if (P != Nil) {
		if (IsEmpty(L)) {
			return(P);
		}
		else {
			Next(L) = KonsB(Tail(L), e);
			return L;
		}
	}
	else {
		return L;
	}
	
}
/* *** Operasi Lain *** */
List Copy (List L)
/* Mengirimkan salinan list L (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan L */
{
	if (IsEmpty(L)) { //basis
		return L;
	}
	else { //rekurens
		return(Konso(FirstElmt(L), Copy(Tail(L))));
	}
}

void MCopy (List Lin, List *Lout)
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
{
	// Kamus
	List LTemp;
	
	// Algoritma
	if (IsEmpty(Lin)) {
		*Lout = Nil;
	}
	else {
		MCopy(Tail(Lin), &LTemp);
		*Lout = Konso(FirstElmt(Lin), LTemp);
	}
}
List Concat (List L1, List L2)
/* Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
{
	if (IsEmpty(L1)) {
		return (Copy(L2));
	}
	else {
		return (Konso(FirstElmt(L1), Concat(Tail(L1), L2)));
	}
}			
void MConcat (List L1, List L2, List *LHsl)
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2 */
{
	// Kamus
	List LTemp;
	
	// Algoritma
	if (IsEmpty(L1)) {
		*LHsl = Copy(L2);
	}
	else {
		MConcat(Tail(L1), L2, &LTemp);
		*LHsl = Konso(FirstElmt(L1), LTemp);
	}
}
void PrintList (List L)
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen list dicetak. */
{
	if (IsEmpty(L)) {
		;}
	else {
		printf("%d\n", FirstElmt(L));
		PrintList(Next(L));
	}
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list L, Nol jika L kosong */
{
	if (IsEmpty(L)) {
		return 0;
	}
	else {
		return (1 + NbElmtList(Tail(L)));
	}
}		
boolean Search (List L, infotype X)
/* Mengirim true jika X adalah anggota list, false jika tidak */
{
	if (IsEmpty(L)) {
		return false;
	}
	else {
		if (Info(L) == X) {
			return true;
		}
		else {
			return (Search(Tail(L), X));
		}
	}
}

/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
infotype MaxList (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{
	infotype max;
	
	// Algoritma
	if (IsOneElmt(L)) {
		max = FirstElmt(L);
	}
	else {
		if (FirstElmt(L) > MaxList(Tail(L))) {
			max = FirstElmt(L);
		}
		else {
			max = MaxList(Tail(L));
		}
	}
}
			

infotype MinList (List L)
/* Mengirimkan nilai info(P) yang minimum */
{
	infotype min;
	
	// Algoritma
	if (IsOneElmt(L)) {
		min = FirstElmt(L);
	}
	else {
		if (FirstElmt(L) < MinList(Tail(L))) {
			min = FirstElmt(L);
		}
		else {
			min = MinList(Tail(L));
		}
	}
}
infotype SumList (List L)
/* Mengirimkan total jumlah elemen List L */
{
	if (IsOneElmt(L)) {
		return FirstElmt(L);
	}
	else {
		return (FirstElmt(L) + SumList(Tail(L)));
	}
}
float AverageList (List L)
/* Mengirimkan nilai rata-rata elemen list L */
{
	return((float)(SumList(L) / NbElmtList(L)));
}

/*** Operasi-Operasi Lain ***/
List InverseList (List L)
/* Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
	// Kamus
	if (IsOneElmt(L)) {
		return (L);
	}
	else {
		return (KonsB(InverseList(Tail(L)), FirstElmt(L)));
	}
}
	
void SplitPosNeg (List L, List *L1, List *L2)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */ 
/* L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
semua elemen L yang negatif; semua dengan urutan yang sama seperti di L */
/* L tidak berubah: Semua elemen L1 dan L2 harus dialokasi */
/* Jika L kosong, maka L1 dan L2 kosong */
{
	// Kamus
	List temp1, temp2;
	
	// Algoritma
	temp1 = Nil;
	temp2 = Nil;
	
	if (IsEmpty(L)) {
		*L1 = Nil;
		*L2 = Nil;
	}
	else {
		SplitPosNeg(Tail(L), &temp1, &temp2);
		if (FirstElmt(L) >= 0) {
			temp1 = Konso(FirstElmt(L), temp1);
		}
		else {
			temp2 = Konso(FirstElmt(L), temp2);
		}
	}
	*L1 = Copy(temp1);
	*L2 = Copy(temp2);
}
			

void SplitOnX (List L, infotype X, List *L1, List *L2)
/* I.S. L dan X terdefinisi, L1 dan L2 sembarang. */
/* F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
L1, dengan urutan kemunculan yang sama. */
{
	// Kamus
	List temp1, temp2;
	// Algoritma
	
	temp1 = Nil;
	temp2 = Nil;
	if (IsEmpty(L)) {
		*L1 = Nil;
		*L2 = Nil;
	}
	else {
		SplitOnX(Tail(L), X, &temp1, &temp2);
		if (FirstElmt(L) < X) {
			//printf("pass1\n");
			temp1 = Konso(FirstElmt(L), temp1);
		}
		else {
			//printf("pass2\n");
			temp2 = Konso(FirstElmt(L), temp2);
			//PrintList(temp2);
		}
	}
	*L1 = Copy(temp1);
	*L2 = Copy(temp2);
	//printf("done\n");
}
int ListCompare (List L1, List L2)
/* Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2 */
/* Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L: */
/* L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i] */
/* L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari L1 dan L2, L1[i]<L2[i] atau: Jika pada semua elemen pada
urutan i yang sama, L1[i]=L2[i], namun |L1|<|L2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* L1>L2: kebalikan dari L1<L2 */
{
	//
	if (IsEmpty(L1) || IsEmpty(L2)) {
		if (IsEmpty(L1) && IsEmpty(L2)){
			return 0;
		}
		else {
			if (IsEmpty(L1)) {
				return -1;
			}
			else {
				return 1;
			}
		}
	}
	else {
		if (FirstElmt(L1) == FirstElmt(L2)) {
			ListCompare(Tail(L1), Tail(L2));
		}
		else if (FirstElmt(L1) < FirstElmt(L2)) {
			return -1;
		}
		else {
			return 1;
		}
	}
}
boolean IsAllExist (List L1, List L2)
/* Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false. */
{
	if (IsEmpty(L1)) {
		return false;
	}
	else if (IsOneElmt(L1)) {
		return (Search(L2, FirstElmt(L1)));
	}	
	else {
		if (Search(L2, FirstElmt(L1))) {
			return(IsAllExist(Tail(L1), L2));
		}
		else {
			return false;
		}
	}
}
	
