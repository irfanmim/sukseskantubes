#include "point.h"
#include "boolean.h"
#include "battleandplayer.h"
#include <time.h>
#include "soqlist.h"
#include <stdio.h>

void inputdata(player *pl);

void makestack(Stack *st);

//void buatsoq( char *T , Stack *S, int *nb);

int main (){
	player kita,musuh;
	Stack stenemy,S;
	Queue q,Qtemp;
	boolean menang;
	int h,l,w,ronde;

	
	buatsoq("file.txt",&S,&ronde);
	
	printf("sudah\n");
	/*
	if(IsEmpty(S)){
		printf("Kosong\n");
	}else{
		printf("Ga Kosong\n");
		for (l=0; l<ronde;l++) {
			Pop(&S,&Qtemp);
			PrintQueue(Qtemp);
			printf("\n");
		}
	}

	printf("makestack\n");
	makestack(&stenemy);
	for (l=0; l<10;l++) {
		Pop(&stenemy,&Qtemp);
		PrintQueue(Qtemp);
		printf("\n");
	}*/

	inputdata(&kita);
	inputdata(&musuh);

	HP(kita) = 50;
	HP(musuh) = 25;	

	printf("Lebar : ");
	scanf("%d",&w);

	printf("Tinggi : ");
	scanf("%d",&h);
	
	system("clear");
	

	//stenemy = S;

	BattleOn(&kita,musuh,S,&menang,w,h);

	if (menang){
		printf("You Win\n");
	}else{
		printf("Try Again\n");
	}

}

void inputdata(player *pl){
	printf("NAME : ");
	scanf("%s",NAME(*pl));
	printf("ATK : ");
	scanf("%ld",&ATK(*pl));
	printf("DEF : ");
	scanf("%ld",&DEF(*pl));
	printf("LVL : ");
	scanf("%d",&LVL(*pl));
}

void makestack(Stack *st){
	int i,r,z;
	Queue temp;

	srand(time(NULL));
    z = 1;
    while(z <= 10){
    	CreateEmptyQueue(&temp);
		for (int i = 1; i <= 4; i++)
		{
			
    		r = rand() % 3;

			if(r == 0){
				Add(&temp,'A');	
			}else if(r == 1){
				Add(&temp,'F');
			}else if(r == 2){
				Add(&temp,'B');
			}
		}
		Push(st,temp);
		z++;
    }


}
/*
void buatsoq( char *T, Stack *S, int *nb) {

    FILE* pita;
    Queue Q, Qtemp;
    Queue final[2][50];
    int i,j;
    char isifile[1][300];
    char temp[1][100];
    int a,b,l,s,k;
    int r;
    char ct;


    CreateEmptyQueue(&Q);
    pita = fopen(T,"r");

    //Isi file dipindah ke array isifile 
    i = 0;
    while ( !feof(pita) ) {
        fscanf(pita, "%c", &isifile[0][i]);
        i++;    
    }

    fclose(pita);

    //Masukkin array ke Queue
    a=0;
    j=0;
    srand(time(NULL));
    while ( isifile[0][j] != '\0' ) {
        if ( isifile[0][j] != '\n' ) {
            Add( &Q, isifile[0][j] );
            a++;
        }
        else {
            for ( b=0; b<a;b++) {
                Del(&Q, &ct);
                temp[0][b] = ct;
            }

            //Random Array
            for (l = 0; l<a; l++) {
                r = rand() % a;
                ct = temp[0][l];
                temp[0][l] = temp[0][r];
                temp[0][r] = ct;
            }

            for ( b=0; b<a;b++) {
                Add(&Q, temp[0][b]);
            }
            
            final[0][s] = Q;
            
            s++;
            CreateEmptyQueue(&Q);
            a = 0;
        }
        j++;
    }

    
    //Random Array
    //srand(time(NULL));
    
    for (l = 0; l<s; l++) {
        r = rand() % s;
        //printf("%d\n", r);
        Qtemp = final[0][l];
        final[0][l] = final[0][r];
        final[0][r] = Qtemp;
    }

    k = 0;
    CreateEmpty(S);

    for (l=0; l<s;l++) {
        Push(S,final[0][l]);
    }

    *nb = s; 
}*/