#include "soqlist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotypes X){
    *P = (address)malloc(sizeof(Queue));
    if(*P!=Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dasarnyan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmpty (Stack S){
    return (Top(S) == Nil);
}
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
void CreateEmpty (Stack * S){
    Top(*S) = Nil;
}
/* I.S. sembarang */
/* F.S. Membuat sebuah stack S yang kosong */
void Push (Stack * S, infotypes X){
    address P;
    Alokasi(&P,X);
    if(P!=Nil){
        if (IsEmpty(*S)){
            Top(*S) = P;
        }else{
            Next(P) = Top(*S);
            Top(*S) = P;
        }
    }
}
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
void Pop (Stack * S, infotypes * X){
    *X = InfoTop(*S);
    if(Next(Top(*S)) == Nil){
        CreateEmpty(S);
    }else{
        address P = Top(*S);
        Top(*S) = Next(Top(*S));
        Dealokasi(P);
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */

void AlokasiQueue(addressq *P, infotypeq X){
    *P = (addressq) malloc(sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void DealokasiQueue (addressq  P){
    free(P);
}
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmptyQueue(Queue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
int NbElmt(Queue Q){
    if (!IsEmptyQueue(Q)){
        addressq P = Head(Q);
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
void CreateEmptyQueue(Queue * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotypeq X){
    addressq P;
    AlokasiQueue(&P,X);
    if(P!=Nil){
        if (IsEmptyQueue(*Q)){
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
void Del(Queue * Q, infotypeq * X){
    *X = InfoHead(*Q);
    if(Head(*Q) == Tail(*Q)){
        CreateEmptyQueue(Q);
    }else{
        addressq P = Head(*Q);
        Head(*Q) = Next(Head(*Q));
        DealokasiQueue(P);
    }

}
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

/*
void PrintQueue(Queue Q){
    printf("[");
    if(!IsEmptyQueue(Q)){
        addressq P = Head(Q);
        while(P != Tail(Q)){
            printf("%c,",Info(P));
            P = Next(P);
        }
        printf("%c",Info(P));
    }
    printf("]\n");
}
*/

void BacaFile(Stack *S, FILE * source, str filetxt){
    source = fopen(filetxt,"r");
    int x = 0;
    int i;
    Queue temp;
    str antri;
    while (!feof(source)){
        CreateEmptyQueue(&temp);
        fgets(antri,1000,source);
        x = strlen(antri);
        if(antri[x] == '\n'){
            x--;
        }
        for(i=0;i<=x-1;i++){
            Add(&temp,antri[i]);
        }
        Push(S,temp);
    }
    fclose(source);
}

//----------------------------------------------

void DelTail(Queue *Q, infotypeq *X){
    *X = InfoTail(*Q);
    if(Head(*Q) == Tail(*Q)){
        CreateEmptyQueue(Q);
    }else{
        addressq P = Tail(*Q);
        addressq O = Head(*Q);
        while(Next(O) != P){
            O = Next(O);
        }
        Next(O) = Nil;
        Tail(*Q) = O;
        DealokasiQueue(P);
    }

}

void PrintQueue(Queue Q){

    if ( IsEmptyQueue(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        addressq P = Head(Q);
        while(P!=Nil){
            printf("%c ",Info(P));
            P = Next(P);
        }
    }
}

void PrintQueueRandom (Queue Q, int *i,int *r){
    infotypeq temp;
    
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

    if ( IsEmptyQueue(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        addressq P = Head(Q);
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

    if ( IsEmptyQueue(Q) ) {
        printf("Queue Kosong\n");
    }
    else {
        addressq P = Head(Q);
        count = 0;
        while(P!=Nil){
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

    if ( IsEmptyQueue(Q) ) {
        printf("Queue Kosong\n");
    }
    else if (lawan){
        count = 0;
        addressq P = Head(Q);
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
        addressq P = Head(Q);
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