// Nama 			: Martin Lutta
// NIM 				: 13515121
// Deskripsi 		: Pra-Praktikum 12
// Topik			: Binary Tree

#include "skilltree.h"
#include <stdlib.h>
#include <stdio.h>
#include "custring.h"
#include "mesinkata.h"

SkillTree Tree (Infotype Akar, SkillTree L, SkillTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokNode berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokNode gagal */
{
	// Kamus
	AddrNode P;
	
	// Algoritma
	P = alokNode(Akar);
	if (P != Nil) {
		Left(P) = L;
		Right(P) = R;
	}
	return P;
}

void MakeTree (Infotype Akar, SkillTree L, SkillTree R, SkillTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokNode berhasil. P = Nil jika alokNode gagal. */
{
	*P = Tree(Akar, L, R);
}

/* Manajemen Memory */
AddrNode alokNode (Infotype X)
/* Mengirimkan AddrNode hasil alokNode sebuah elemen */
/* Jika alokNode berhasil, maka AddrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokNode gagal, mengirimkan Nil */
{
	// Kamus
	AddrNode P;
	
	// Algoritma
	P = (Node*) malloc (sizeof(Node));
	if (P != Nil) {
		Akar(P) = X;
		Left(P) = Nil;
		Right(P) = Nil;
		Learnt(P) = false;
	}
	
	return P;
}

void DealokNode (AddrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian AddrNode P */
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
	
/* *** Operasi lain *** */
void AddDaunTerkiri (SkillTree *P, Infotype X, char nama[])
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{	
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = alokNode(X);
		if (*P != Nil) {
			Strcpy(Name(P), nama);
		}	
	}
	else {
		AddDaunTerkiri(&Left(*P), X, nama);
	}
}
void AddDaunTerkanan (SkillTree *P, Infotype X, char nama[])
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkanan */
{	
	// Algoritma
	if (IsTreeEmpty(*P)) {
		*P = alokNode(X);
		if (*P != Nil) {
			Strcpy(Name(P), nama);
		}
	}
	else {
		AddDaunTerkanan(&Right(*P), X, nama);
	}
}


void ShowAvailable(SkillTree S) 
{
	// Kamus Lokal
	
	// Algoritma
	if (IsBiner(S)) {			// Kasus khusus lvl 1
		if (!Learnt(Left(S))) {
			printf("%s\n", Name(Left(S)));
		}
		if (!Learnt(Right(S))) {
			printf("%s\n", Name(Right(S)));
		}
		ShowAvailable(Left(S));
		ShowAvailable(Right(S));
	}
	else if (IsUnerLeft(S)) {
		if (Learnt(S) && (!Learnt(Left(S)))) {
			printf("%s\n", Name(Left(S)));
		}
		ShowAvailable(Left(S));
	}
	else if (IsUnerRight(S)) { 
		if (Learnt(S) && (!Learnt(Right(S)))) {
			printf("%s\n", Name(Right(S)));
		}
		ShowAvailable(Right(S));
	}
	
}

void InitSkillTree(SkillTree *S)
// I.S : file daftarskill.txt ada di folder yang sama dengan skilltree.c
// F.S : Daftar skill player diinisialisasi, learnt = false kecuali root
{
	// Kamus
	
	FILE *daftarskill;
	daftarskill = fopen("daftarskill.txt", "r");
	char line[50];
	char temp[50];
	int i;
	
	// Algoritma
	i = 0;
	fgets(line, 50, daftarskill);
	sscanf(line, "%s", temp);
	AddDaunTerkiri(S, i, temp);
	i++;
	
	char ATK[] = "ATTACK\n";
	char DEF[] = "DEFENSE\n";
	char E[] = "END.\n";
	char I[] = "InitStatus\n";
	while (!feof(daftarskill)) {
		// ATTACK SKILL TREE
		while(!Strcmp(line, ATK)) {
			fgets(line, 50, daftarskill);
		}
		while(!Strcmp(line, DEF)) {
			sscanf(line, "%s", temp);
			if (!Strcmp(temp, "ATTACK")) {
				AddDaunTerkiri(S, i, temp);
				i++;
			}
			fgets(line, 50, daftarskill);
		}
		// DEFENSE SKILL TREE
		while(!feof(daftarskill)) {
			sscanf(line, "%s", temp);
			if (!Strcmp(temp, "DEFENSE")) {
				AddDaunTerkanan(S, i, temp);
				i++;
			}
			fgets(line, 50, daftarskill);
		}
	}	
	fclose(daftarskill);
	
}
void ShowSkill(SkillTree S)
// I.S : Skill Tree P1 terdefinisi
// F.S : Menampilkan seluruh daftar skill yang sudah dan belum dipelajari. Skill yang sudah dipelajari diberi keterangan (learned).
{
	if (IsTreeEmpty(S)) {
		;
	}
	else {
		if (Learnt(S)) {
			printf("%s <Learned>\n", Name(S));
		}
		else {
			printf("%s <Not yet learned>\n", Name(S));
		}
		ShowSkill(Left(S));
		ShowSkill(Right(S));
	}
}
boolean Search(SkillTree S, char nama[])
// Mengembalikan true jika terdapat skill dengan nama 'nama' di S
{
	if (IsTreeEmpty(S)) {
		return false;
	}
	else {
		if (Strcmp(Name(S), nama))  {
			return true;
		}
		else { 
			return (Search(Left(S), nama) || Search(Right(S), nama));
		}
	}
}

void SearchAndLearn(SkillTree *S, char nama[])
// I.S : S telah diinisialisasi, skill dengan nama 'nama' ada dalam S
// F.S : Learnt skill 'nama' = true
{
	// Kamus
	
	// Algoritma
	if (IsTreeEmpty(*S)) {
		;
	}
	else {
		if (Strcmp(Name(*S), nama)) {
			Learnt(*S) = true;
		}
		else {
			if (Search(Left(*S), nama)) {
				SearchAndLearn(&(Left(*S)), nama);
			}
			else if (Search(Right(*S), nama)) {
				SearchAndLearn(&(Right(*S)), nama);
			}
			else {
				;
			}
		}
	}
}

boolean IsLearnt(SkillTree S, char nama[])
// Mengirimkan true jika skill dengan nama 'nama' telah dipelajari (Learnt = True)
{
	if (IsTreeEmpty(S)) {
		return false;
	}
	else {
		if (Strcmp(Name(S), nama) && (Learnt(S)))  {
			return true;
		}
		else { 
			return (IsLearnt(Left(S), nama) || IsLearnt(Right(S), nama));
		}
	}
}	