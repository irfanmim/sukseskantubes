#ifndef tRee_H
#define tRee_h

#include "boolean.h"
#define Nil NULL

typedef int infotype;
typedef struct tNode* address;
typedef struct tNode {
	infotype info;
	address left;
	address right;
} Node;

/* Definisi Pohon Biner : */
/* Pohon Biner kosong : P = Nil */

typedef address binTree;

#define Info(P) (P).info
#define Left(P) (P).left
#define Right(P) (P).right

/*********** KONSTRUKTOR ***********/
void MakeTree(infotype akar, binTree L, binTree R, binTree * P);
/* { I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari A, L, dan R, jika 
alokasi berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi 
gagal } */

/*********** ALOKASI / DEALOKASI ***********/
address Alokasi(infotype X);
/* {Mengirimkan address hasil alokasi sebuah elemen X } 
{ Jika alokasi berhasil, maka address tidak nil, dan 
misalnya menghasilkan P, maka Info(P)=X,Left(P)=Nil, Right(P)=Nil
{Jika alokasi gagal, mengirimkan Nil } */

void Dealokasi (address P);
/* { I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P  */

/*********** PEMERIKSAAN KONDISI TREE ***********/
boolean IsTreeEmpty(binTree P);
/* Mengirimkan true jika P adalah pohon biner yang kosong */

boolean IsOneElmt(binTree P);
/* Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen */

boolean IsUnerLeft(binTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon 
kiri */

boolean IsBiner(binTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner :  mempunyai subpohon 
kiri dan subpohon kanan*/

boolean IsUnerRight(binTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: mempunyai subpohon 
kanan */

/*********** PROSES TREE ***********/
void PreOrder(binTree P);
/* {I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara PreOrder: 
akar, kiri, kanan }
{ Basis : Pohon kosong : tidak ada yang diproses }
{ Rekurens : Proses Akar(P); Proses secara Preorder (Left(P)); Proses secara Preorder (Right(P))  */

void PrintPreOrder(binTree P);
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah dicetak secara PreOrder: akar, kiri, kanan }
{ Basis: Pohon kosong : tidak ada yang diproses }
{ Rekurens : Cetak Akar(P); cetak secara Preord (Left(P)); secara Preorder (Right(P)) } */

void InOrder(binTree P);
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara 
InOrder: kiri,akar,kanan }
{ Basis : Pohon kosong :  tidak ada yang diproses }
{ Rekurens: Proses secara inOrder(Left(P)); Proses Akar(P); Proses secara inorder (Right(P)) */

void PostOrder(binTree P);
/* { I.S. Pohon P terdefinisi }
{ F.S. Semua node pohon P sudah diproses secara PostOrder:kiri, kanan
, akar}
{ Basis: Pohon kosong : tidak ada yang diproses }
{ Rekurens: Proses secara PostOrder(Left(P)); Proses secara PostOrder (Right(P)); Proses Akar(P); } */

int NbElmt(binTree P);
/* Mengirim jumlah elemen dari pohon */

int NbDaun(binTree P);
/* Prekondisi : Pohon biner tidak mungkin kosong. Mengirimkan
 banyaknya daun pohon */

int NbDaun1(binTree P); 
/* Fungsi untuk rekursif NbDaun */

infotype max(infotype e1, infotype e2);
/* Mengirimkan maksimum dari e1 dan e2 */

int Tinggi(binTree P);
/* 	Mengirim 'height' / tinggi pohon 
	Basis : Jika pohon kosong, tinggnya nol.
	Rekurens : 1 + maksimum(tinggi(anak_kiri), tinggi(anak_kanan)) */

/*********** INSERT / DELETE LEAF ***********/
void AddLMLeaf (binTree *P, infotype X);
/* Add leftmost leaf (add daun terkiri)
{ I.S. P boleh kosong}
{ F.S. X menjadi simpul daun terkiri} */

void AddRMLeaf (binTree *P, infotype X);
/* Add rightmost leaf (add daun terkanan)
{ I.S. P boleh kosong}
{ F.S. X menjadi simpul daun terkiri} */

void DelLMLeaf (binTree *P, infotype * X);
/* Delete leftmost leaf (delete daun terkiri)
{ I.S. P tidak kosong}
{ F.S. Daun terkiri P dihapus, nilai daun ditampung di X} */

void DelRMLeaf (binTree *P, infotype *X);
/* Delete rightmost leaf (delete daun terkanan)
{ I.S. P tidak kosong}
{ F.S. Daun terkanan P dihapus, nilai daun ditampung di X} */

/*********** TREE TO LIST / LIST TO TREE ***********/


#endif

