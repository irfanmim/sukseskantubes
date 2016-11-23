// Nama 			: Martin Lutta
// NIM 				: 13515121
// Deskripsi 		: Pra-Praktikum 12
// Topik			: Binary Tree

#include "skilltree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

SkillTree Tree (infotype Akar, SkillTree L, SkillTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika AlokNode berhasil */
/* Menghasilkan pohon kosong (Nil) jika AlokNode gagal */
{
	// Kamus
	addrNode P;
	
	// Algoritma
	P = AlokNode(Akar);
	if (P != Nil) {
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}

void MakeTree (infotype Akar, SkillTree L, SkillTree R, SkillTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika AlokNode berhasil. P = Nil jika AlokNode gagal. */
{
	*P = Tree(Akar, L, R);
}
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil AlokNode sebuah elemen */
/* Jika AlokNode berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika AlokNode gagal, mengirimkan Nil */
{
	// Kamus
	addrNode P;
	
	// Algoritma
	P = (Node*) malloc (sizeof(Node));
	if (P != Nil) {
		Akar(P) = X;
		Left(P) = Nil;
		Right(P) = Nil;
	}
	
	return P;
}
void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
	free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (SkillTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	return (P == Nil);
}

boolean IsTreeOneElmt (SkillTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		return ((Left(P) == Nil) && (Right(P) == Nil));
	}
}
boolean IsUnerLeft (SkillTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
	if (IsTreeOneElmt(P)) {
		return false;
	}
	else {
		return ((Left(P) != Nil) && (Right(P) == Nil));
	}
}

boolean IsUnerRight (SkillTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
	if (IsTreeOneElmt(P)) {
		return false;
	}
	else {
		return ((Left(P) == Nil) && (Right(P) != Nil));
	}
}
boolean IsBiner (SkillTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
	if (IsTreeOneElmt(P)) {
		return false;
	}
	else {
		return ((Left(P) != Nil) && (Right(P) != Nil));
	}
}
/* *** Traversal *** */
void PrintPreorder (SkillTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
	if (IsTreeEmpty(P)) {
		printf("()");
	}
	else {
		printf("(%d", Akar(P)); 
		PrintPreorder(Left(P)); 
		PrintPreorder(Right(P));
		printf(")");
	}
}
void PrintInorder (SkillTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
	if (IsTreeEmpty(P)) {
		printf("()");
	}
	else {
		printf("(");
		PrintInorder(Left(P)); 
		printf("%d", Akar(P));
		PrintInorder(Right(P));
		printf(")");
	}
}
void PrintPostorder (SkillTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
	if (IsTreeEmpty(P)) {
		printf("()");
	}
	else {
		printf("(");
		PrintPostorder(Left(P)); 
		PrintPostorder(Right(P));
		printf("%d)", Akar(P));
	}
}
void PrintTree (SkillTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
	// Kamus
	int i, j;
	
	// Algoritma
	if (IsTreeEmpty(P)) {
		;
	}
	else {
		printf("%d\n",Akar(P));
		if (!IsTreeEmpty(Left(P))) {
			for (i = 1; i <= h; i++) {
				printf(" ");
			}
			PrintTree(Left(P), (i-1+h));
		}
		if (!IsTreeEmpty(Right(P))) {
			for (j = 1; j <= h; j++) {
				printf(" ");
			}
			PrintTree(Right(P), (j-1+h));
		}
	}
}
/* *** Searching *** */
boolean SearchTree (SkillTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P)) {
		return false;
	}
	else {
		if (Akar(P) == X) {
			return true;
		}
		else { 
			return (SearchTree(Left(P), X) || SearchTree(Right(P), X));
		}
	}
}
/* *** Fungsi-Fungsi Lain *** */
int NbDaun (SkillTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
	if (IsTreeOneElmt(P)) {
		return 1;
	}
	else {
		if (IsUnerLeft(P)) {
			return (NbDaun(Left(P)));
		}
		else if (IsUnerRight(P)) {
			return (NbDaun(Right(P)));
		}
		else { // IsBiner P
			return ((NbDaun(Left(P))) + (NbDaun(Right(P))));
		}
	}
}
boolean IsSkewLeft (SkillTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
	if (IsTreeEmpty(P)) {
		return true;
	}
	else {
		if (IsUnerRight(P) || IsBiner(P)) {
			return false;
		}
		else {
			return IsSkewLeft(Left(P));
		}
	}
}
boolean IsSkewRight (SkillTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
	if (IsTreeEmpty(P)) {
		return true;
	}
	else {
		if (IsUnerLeft(P) || IsBiner(P)) {
			return false;
		}
		else {
			return IsSkewRight(Right(P));
		}
	}
}
int Level (SkillTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
{
	if (Akar(P) == X) {
		return 1;
	}
	else {
		if (SearchTree(Left(P), X)) {
			return (1 + Level(Left(P), X));
		}
		else {
			return (1 + Level(Right(P), X));
		}
	}
}
int Tinggi (SkillTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
	if (IsTreeEmpty(P)) {
		return 0;
	}
	else {
		if (Tinggi(Left(P)) > Tinggi(Right(P))) {
			return (1 + Tinggi(Left(P)));
		}
		else {
			return (1 + Tinggi(Right(P)));
		}
	}
}
	
/* *** Operasi lain *** */
void AddDaunTerkiri (SkillTree *P, infotype X, char * nama)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{	
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = AlokNode(X);
		strcpy(Name(*P), nama);
	}
	else {
		AddDaunTerkiri(&Left(*P), X, nama);
	}
}
void AddDaunTerkanan (SkillTree *P, infotype X, char * nama)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkanan */
{	
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = AlokNode(X);
		strcpy(Name(*P), nama);
	}
	else {
		AddDaunTerkanan(&Right(*P), X, nama);
	}
}

void AddDaun (SkillTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
	// Kamus
	SkillTree temp;
	
	// Algoritma
	temp = AlokNode(Y);
	if (temp != Nil) {
		if (IsTreeOneElmt(*P)) {
			if (Kiri) {
				Left(*P) = temp;
			}
			else {
				Right(*P) = temp;
			}
		}
		else {
			if (SearchTree(Left(*P), X)) {
				AddDaun(&(Left(*P)), X, Y, Kiri);
			}
			else {
				AddDaun(&(Right(*P)), X, Y, Kiri);
			}
		}
	}
}
void DelDaunTerkiri (SkillTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
{
	// Kamus
	addrNode temp;
	
	// Algoritma
	if (IsTreeOneElmt(*P)) {
		*X = Akar(*P);
		temp = *P;
		*P = Nil;
		DealokNode(temp);
	}
	else {
		if (IsUnerRight(*P)) {
			DelDaunTerkiri(&(Right(*P)), X);
		}
		else {
			DelDaunTerkiri(&(Left(*P)), X);
		}
	}
}
void DelDaun (SkillTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
	// Kamus Lokal
	SkillTree temp;
	
	// Algoritma
	if (IsTreeOneElmt(*P)) {
		temp = *P;
		*P = Nil;
		DealokNode(temp);
	}
	else {
		if (SearchTree(Left(*P), X)) {
			DelDaun(&(Left(*P)), X);
		}
		if (SearchTree(Right(*P), X)) {
			DelDaun(&(Right(*P)), X);
		}
	}
}
