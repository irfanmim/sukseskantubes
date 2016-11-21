/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ( Head(Q) == Nil && Tail(Q) == Nil );
}


boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	
	return ( NBElmt(Q) == MaxEl(Q) );
}


int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if ( IsEmpty(Q) ) {
		return 0;
	}
	else {
		if ( Tail(Q) == Head(Q) ) {
			return  1;
		}
		else {
			if ( Tail(Q) > Head(Q) ) {
				return ( Tail(Q) - Head(Q) + 1);
			}
			else {
				return ( MaxEl(Q) - ( Head(Q) - Tail(Q) - 1 ) );
			}
		}
	}
}


/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
	
	(*Q).T = (infotype *) malloc ((Max+1) * sizeof(infotype));
	
	if ( (*Q).T != NULL ) {
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
		MaxEl(*Q) = Max;
	}
	else {
		MaxEl(*Q) = Nil;
	}
}


/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
	if ( IsEmpty(*Q) ) {
		Head(*Q) = 1;
		Tail(*Q) = 1;
		InfoTail(*Q) = X;
	}
	else {
		if ( Tail(*Q) != MaxEl(*Q) ) {
			Tail(*Q) = Tail(*Q) + 1 ;
			InfoTail(*Q) = X;
		}
		else {
			Tail(*Q) = 1 ;
			InfoTail(*Q) = X;
		}
	}
}


void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
	if ( Head(*Q) == Tail(*Q) ) {
		*X = InfoHead(*Q);
		Head(*Q) = Nil;
		Tail(*Q) = Nil;
	}
	else {
		if ( Head(*Q) != MaxEl(*Q) ) {
			*X = InfoHead(*Q);
			Head(*Q) = Head(*Q) + 1 ;
		}
		else {
			*X = InfoHead(*Q);
			Head(*Q) = 1 ;
		}
	}	
}


/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar */
{
    infotype temp;
    
    srand(time(NULL));
	int i = rand() % 4;
	int r = rand() % 4;
	int temp1, count;

	while ( i == r ){
		i = rand() % 4;
	}

	if ( i > r ) {
		temp1 = i;
		i = r;
		r = temp1;
	}

	printf("%d %d\n", i, r);

    if ( IsEmpty(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
    	count = 0;
        while ( !IsEmpty(Q) ) {
            if ( count == i || count == r ) {
            	printf("# ");
            	Del(&Q,&temp);
            }
            else {
            	printf("%c ", InfoHead(Q) );
            	Del(&Q,&temp);
            }
            count++;
        }
    }
}
