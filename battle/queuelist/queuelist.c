/* File : queuelist.h */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X){
    *P = (address) malloc(sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (Queue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
    if (!IsEmpty(Q)){
        address P = Head(Q);
        int count = 0;

        while(P!=Tail(Q)){
            count++;
            P = Next(P);
        }
        count++;
        return count;
    }else{
        return 0;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(Queue * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X){
    address P;
    Alokasi(&P,X);
    if(P!=Nil){
        if (IsEmpty(*Q)){
            Head(*Q) = Tail(*Q) = P;
        }else{
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
void Del(Queue * Q, infotype * X){
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        CreateEmpty(Q);
    }else{
        address P = Head(*Q);
        Head(*Q) = Next(Head(*Q));
        Dealokasi(P);
    }

}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

void DelTail(Queue *Q, infotype *X){
    *X = InfoTail(*Q);
    if(Head(*Q) == Tail(*Q)){
        CreateEmpty(Q);
    }else{
        address P = Tail(*Q);
        address O = Head(*Q);
        while(Next(O) != P){
            O = Next(O);
        }
        Next(O) = Nil;
        Tail(*Q) = O;
        Dealokasi(P);
    }

}

void PrintQueue(Queue Q){

    if ( IsEmpty(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        address P = Head(Q);
        while(P!=Nil){
            printf("%c ",Info(P));
            P = Next(P);
        }
    }
}

void PrintQueueRandom (Queue Q, int *i,int *r){
    infotype temp;
    
    srand(time(NULL));
    *i = rand() % 4;
    *r = rand() % 4;
    int temp1, count;

    while ( *i == *r ){
        *i = rand() % 4;
    }

    if ( *i > *r ) {
        temp1 = *i;
        *i = *r;
        *r = temp1;
    }

    //printf("%d %d\n", i, r);

    if ( IsEmpty(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        address P = Head(Q);
        count = 0;
        while(P != Nil){
            if(count == *i || count == *r){
                printf("# ");
            }else{
                printf("%c ",Info(P));
            }
            P = Next(P);
            count++;
        }
    }
}

void PrintQueueClosed (Queue Q, int i,int r){
    int count;

    if ( IsEmpty(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        address P = Head(Q);
        count = 0;
        while(P != Nil){
            if(count == i || count == r){
                printf("# ");
            }else{
                printf("%c ",Info(P));
            }
            P = Next(P);
            count++;
        }
    }
}

void PrintQueuewithpointer (Queue Q, int x, int i, int r, boolean lawan){

    int count;

    if ( IsEmpty(Q) ) {
        printf("Queue Kosong\n");
    }
    else if (lawan){
        count = 0;
        address P = Head(Q);
        while ( P != Nil ) {
            if (x < i){
                if (count == i || count == r)
                {
                    printf("# ");
                }else if (count == x){
                    printf(">%c ",Info(P) );
                }else{
                    printf("%c ",Info(P) );
                }
            }else if (x == i){
                if (count == r)
                {
                    printf("# ");
                }else if(count == x){
                    printf(">%c ",Info(P) );
                }else{
                    printf("%c ",Info(P) );
                }
            }else if (x > i && x < r){
                if (count == r)
                {
                    printf("# ");
                }else if(count == x){
                    printf(">%c ",Info(P) );
                }else{
                    printf("%c ",Info(P) );
                }
            }else if (x == r){
                if (count == r){
                    printf(">%c ",Info(P) );
                }else{
                    printf("%c ",Info(P) );
                }
            }else{
                if (count == x)
                {
                    printf(">%c ",Info(P) );
                }else{
                    printf("%c ",Info(P) );
                }    
            }
            P = Next(P);
            count++;
        }
    }else{
        count = 0;
        address P = Head(Q);
        while ( P!=Nil) {
            if (count == x)
            {
                printf(">%c ",Info(P) );
            }else{
                printf("%c ",Info(P) );
            }
            P = Next(P);
            count++;
        }
    }
}