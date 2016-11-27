/* Nama 		: Martin Lutta Putra */
/* NIM 			: 13515121 */
/* Tanggal 		: 13 November 2016 */
/* Deskripsi	: ADT TUBES YEYEYE */

#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

/*********** KONSTRUKTOR ***********/
void MakeTree(infotype akar, binTree L, binTree R, binTree * P)
/* { I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari A, L, dan R, jika 
alokasi berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi 
gagal } */
{
	*P = Alokasi(akar);
	if (*P != Nil) {
		Left(**P) = L;
		Right(**P) = R;
	}
}
/*********** ALOKASI / DEALOKASI ***********/
address Alokasi(infotype X)
/* {Mengirimkan address hasil alokasi sebuah elemen X } 
{ Jika alokasi berhasil, maka address tidak nil, dan 
misalnya menghasilkan P, maka Info(P)=X,Left(P)=Nil, Right(P)=Nil
{Jika alokasi gagal, mengirimkan Nil } */
{
	// Kamus
	address P;
	
	// Algoritma
	P = (Node*) malloc (sizeof(Node));
	if (P != Nil) {
		Info(*P) = X;
		Left(*P) = Nil;
		Right(*P) = Nil;
	}
	
	return P;
}

void Dealokasi (address P)
/* { I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P  */
{
	free(P);
}
/*********** PEMERIKSAAN KONDISI TREE ***********/
boolean IsTreeEmpty(binTree P)
/* Mengirimkan true jika P adalah pohon biner yang kosong */
{
	return (P == Nil);
}

boolean IsOneElmt(binTree P)
/* Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		return ((Left(*P) == Nil) && (Right(*P) == Nil));
	}
}
boolean IsUnerLeft(binTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon 
kiri */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		return ((Left(*P) != Nil) && (Right(*P) == Nil));
	}
}

boolean IsBiner(binTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner :  mempunyai subpohon 
kiri dan subpohon kanan*/
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		return ((Left(*P) != Nil) && (Right(*P) != Nil));
	}
}
boolean IsUnerRight(binTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: mempunyai subpohon 
kanan */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		return ((Left(*P) == Nil) && (Right(*P) != Nil));
	}
}
/*********** PROSES TREE ***********/
//void PreOrder(binTree P)
/* {I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara PreOrder: 
akar, kiri, kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : Proses Akar(P); Proses secara Preorder (Left(P)); Proses secara Preorder (Right(P))  */
		
void PrintPreOrder(binTree P)
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri, kanan }
{ Basis: Pohon kosong : tidak ada yang diproses }
{ Rekurens : Cetak Akar(P); cetak secara Preord (Left(P)); secara Preorder (Right(P)) } */
{
	if (IsTreeEmpty(P)) {
		;
	}
	else {
		printf("%d\n", Info(*P));
		PrintPreOrder(Left(*P));
		PrintPreOrder(Right(*P));
	}
}
//void InOrder(binTree P);
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara 
InOrder: kiri,akar,kanan }
{ Basis : Pohon kosong :  tidak ada yang diproses }
{ Rekurens: Proses secara inOrder(Left(P)); Proses Akar(P); Proses secara inorder (Right(P)) */

//void PostOrder(binTree P);
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara PostOrder:kiri, kanan
, akar}
{ Basis: Pohon kosong : tidak ada yang diproses }
{ Rekurens: Proses secara PostOrder(Left(P)); Proses secara PostOrder (Right(P)); Proses Akar(P); } */

int NbElmt(binTree P)
/* Mengirim jumlah elemen dari pohon */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return (1 + (NbElmt(Left(*P))) + (NbElmt(Left(*P))));
	}
}

int NbDaun(binTree P)
/* Prekondisi : Pohon biner tidak mungkin kosong. Mengirimkan
 banyaknya daun pohon */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		return(NbDaun1(P));
	}
}
int NbDaun1(binTree P) 
/* Fungsi untuk rekursif NbDaun */
{
	if (IsOneElmt(P)) {
		return 1;
	}
	else {
		if (IsUnerLeft(P)) {
			return (NbDaun1(Left(*P)));
		}
		else if (IsUnerRight(P)) {
			return (NbDaun1(Right(*P)));
		}
		else { // IsBiner P
			return ((NbDaun1(Left(*P))) + (NbDaun1(Right(*P))));
		}
	}
}

infotype max(infotype e1, infotype e2)
/* Mengirimkan maksimum dari e1 dan e2 */
{
	if (e1 > e2) {
		return e1;
	}
	else {
		return e2;
	}
}
int Tinggi(binTree P)
/* 	Mengirim 'height' / tinggi pohon 
	Basis : Jika pohon kosong, tinggnya nol.
	Rekurens : 1 + maksimum(tinggi(anak_kiri), tinggi(anak_kanan)) */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		1 + max(Tinggi(Left(*P)), Tinggi(Right(*P)));
	}
}
		
/*********** INSERT / DELETE LEAF ***********/
void AddLMLeaf (binTree *P, infotype X)
/* Add leftmost leaf (add daun terkiri)
{ I.S. P tidak kosong}
{ F.S. Daun terkiri P dihapus, nilai daun ditampung di X} */
{	
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = Alokasi(X);
	}
	else {
		AddLMLeaf(&Left(**P), X);
	}
}
				  
void AddRMLeaf (binTree *P, infotype X)
/* Add rightmost leaf (add daun terkanan)
{ I.S. P boleh kosong}
{ F.S. X menjadi info P} */
{
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = Alokasi(X);
	}
	else {
		AddRMLeaf(&Right(**P), X);
	}
}
void DelLMLeaf (binTree *P, infotype * X)
/* Delete leftmost leaf (delete daun terkiri)
{ I.S. P tidak kosong}
{ F.S. Daun terkiri P dihapus, nilai daun ditampung di X} */
{
	// Kamus
	address temp;
	
	// Algoritma
	if (IsOneElmt(*P)) {
		*X = Info(**P);
		temp = *P;
		*P = Nil;
		Dealokasi(temp);
	}
	else {
		if (IsUnerRight(*P)) {
			DelLMLeaf(&Right(**P), X);
		}
		else {
			DelLMLeaf(&Left(**P), X);
		}
	}
}
void DelRMLeaf (binTree *P, infotype *X)
/* Delete rightmost leaf (delete daun terkanan)
{ I.S. P tidak kosong}
{ F.S. Daun terkanan P dihapus, nilai daun ditampung di X} */
{
	// Kamus
	address temp;
	
	// Algoritma
	if (IsOneElmt(*P)) {
		*X = Info(**P);
		temp = *P;
		*P = Nil;
		Dealokasi(temp);
	}
	else {
		if (IsUnerLeft(*P)) {
			DelRMLeaf(&Left(**P), X);
		}
		else {
			DelRMLeaf(&Right(**P), X);
		}
	}
}
/*********** TREE TO LIST / LIST TO TREE ***********/
	