/* NIM/Nama		: 13515139/Jehian Norman Saviero */
/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "boolean.h"
#include "stackt.h"


/* Empty adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

/* Definisi akses dengan Selektor : Set dan Get */

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateDeque (Deque *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Empty */
{
	Top(*S) = Empty;
}


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsDequeEmpty (Deque S)
/* Mengirim true jika Deque kosong: lihat definisi di atas */
{
	return (Top(S)==Empty);
}

boolean IsDequeFull (Deque S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	return (Top(S)==MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Deque ************ */
void PushD (Deque * S, jenis X)
/* Menambahkan X sebagai elemen Deque S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	++Top(*S);
	InfoTops(*S) = X;
}

/* ************ Menghapus sebuah elemen Deque ************ */
void PopD (Deque * S, jenis* X)
/* Menghapus X dari Deque S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTops(*S);
	--Top(*S);
}

void CopyDeque (Deque Sin, Deque *Sout)
/* Mengcopy isi Deque input ke Deque output */
/* I.S. Sin mungkin kosong */
/* F.S. Sout sama dengan Sin */
{
	Deque temp;
	jenis X;
	while (!IsDequeEmpty(Sin))
	{
		PopD(&Sin, &X);
		PushD(&temp, X);
	}
	while (!IsDequeEmpty(temp))
	{
		PopD(&temp, &X);
		PushD(Sout, X);
	}
}

void InverseDeque (Deque *S)
/* Menukar isi awal dengan akhir secara berurutan (susunan terbalik) */
/* I.S. S mungkin kosong */
/* F.S. Urutan dari S merupakan kebalikan dari urutan sebelumnya */
{
	Deque temp;
	jenis X;
	CopyDeque(*S, &temp);
	CreateDeque(S);
	while (!IsDequeEmpty(temp))
	{
		PopD(&temp, &X);
		PushD(S, X);
	}
}
