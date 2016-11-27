/* File : stackt.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
#include "peta.h"

#define Empty 0
#define MaxEl 10
/* Empty adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef PETA jenis;
typedef int alamat;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
	jenis T[MaxEl+1]; /* tabel penyimpan elemen */
	alamat TOP;  /* alamat TOP: elemen puncak */
} Deque;
/* Definisi stack S kosong : S.TOP = Empty */
/* Elemen yang dipakai menyimpan Emptyai Deque T[1]..T[MaxEl] */
/* Jika S adalah Deque maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTops(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateDeque (Deque *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP berEmptyai Empty */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsDequeEmpty (Deque S);
/* Mengirim true jika Deque kosong: lihat definisi di atas */
boolean IsDequeFull (Deque S);
/* Mengirim true jika tabel penampung Emptyai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Deque ************ */
void PushD (Deque * S, jenis X);
/* Menambahkan X sebagai elemen Deque S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Deque ************ */
void PopD (Deque * S, jenis* X);
/* Menghapus X dari Deque S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Emptyai elemen TOP yang lama, TOP berkurang 1 */

void CopyDeque (Deque Sin, Deque *Sout);
/* Mengcopy isi Deque input ke Deque output */
/* I.S. Sin mungkin kosong */
/* F.S. Sout sama dengan Sin */

void InverseDeque (Deque *S);
/* Menukar isi awal dengan akhir secara berurutan (susunan terbalik) */
/* I.S. S mungkin kosong */
/* F.S. Urutan dari S merupakan kebalikan dari urutan sebelumnya */

#endif
