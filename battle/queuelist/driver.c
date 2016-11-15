#include "boolean.h"
#include "queuelist.h"
#include <stdio.h>
#include <time.h>
//#include <conio.h>

void inputdata(char nama[200], int *atk, int *def, int *lvl);


void bertarungreal(char lawan, char player, int *splayer, int *slawan, int atkplayer, int atklawan);

void bertarungstatus(char lawan, char player, int atkplayer, int atklawan, char nplayer[200], char nlawan[200]);

void PrintHeader(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r);

void PrintHeaderInBattle(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r,int x);

void PrintAndInput(Queue *Q, int *i);

void PrintCommandInBattle(Queue Q, int i);

void RandomAngka(int *i, int *r);

int main() {
	Queue Q,Battle;
	char input,temp,tempplayer,templawan;
	int i,x,z,r1,r2,round;

	int atk,def,hpplayer,hplawan,lvlplayer;

	address penemy,pplayer;

	char pl[200],en[200];

	round = 1;



	printf("\n");
	

	inputdata(pl,&atk,&def,&lvlplayer);
	hpplayer = 100;
	hplawan = 25;

		printf("nama lawan : "); scanf(" %s",en);

	while(hpplayer > 0 && hplawan > 0 && round<=10){

		CreateEmpty(&Q);
		CreateEmpty(&Battle);

		Add(&Q,'F');
		Add(&Q,'B');
		Add(&Q,'F');
		Add(&Q,'A');

		RandomAngka(&r1,&r2);

		i = 0;
		do{
			PrintHeader(pl,en,hpplayer,lvlplayer,atk,def,round,hplawan,Q,r1,r2);
			printf("\n");
			printf("\n");
			printf("\n");
			PrintAndInput(&Battle,&i);
			
			//clrscr();
		}while(i != 4);

		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		while(getchar()!='\n');

		penemy = Head(Q);
		pplayer = Head(Battle);

		z = 0; 
		while(hpplayer > 0 && hplawan > 0 && z<=3)
		{
			bertarungreal(Info(penemy),Info(pplayer),&hpplayer,&hplawan,atk,3);

			PrintHeaderInBattle(pl,en,hpplayer,lvlplayer,atk,def,round,hplawan,Q,r1,r2,z);

			printf("\n");

			bertarungstatus(Info(penemy),Info(pplayer),atk,3,pl,en);

			printf("\n");

			PrintCommandInBattle(Battle,z);
			
			while(getchar()!='\n');
			//clrscr();

			penemy = Next(penemy);
			pplayer = Next(pplayer);
			z++;

		}
		round++;

	}
	printf("\n");
	return 0;
}

//PORSEDUR

void inputdata(char nama[200], int *atk, int *def, int *lvl){
	printf("nama : "); scanf(" %s",nama);
	printf("attack : "); scanf(" %d",atk);
	printf("defense : "); scanf(" %d",def);
	printf("level : "); scanf(" %d",lvl);
}

void bertarungreal(char lawan, char player, int *splayer, int *slawan, int atkplayer, int atklawan){

	if (lawan == 'A')
	{
		if (player == 'A')
		{
			*splayer = *splayer - atklawan;
			*slawan = *slawan - atkplayer;
			
			//seri
		}else if (player == 'F')
		{	
			*splayer = *splayer - atklawan;

		}else if (player == 'B')
		{
		}
	}else if (lawan == 'F')
	{
		if (player == 'A')
		{
			*slawan = *slawan - atkplayer;
			
		}else if (player == 'F')
		{
			*splayer = *splayer - atklawan;
			*slawan = *slawan - atkplayer;
			//
		}else if (player == 'B')
		{
			*splayer = *splayer - atklawan;
		}
	}else if (lawan == 'B')
	{
		if (player == 'A')
		{
		}else if (player == 'F')
		{
			*slawan = *slawan - atkplayer;
		}else if (player == 'B')
		{
		}
	}
}

void bertarungstatus(char lawan, char player, int atkplayer, int atklawan, char nplayer[200], char nlawan[200]){
	if (lawan == 'A')
	{
		if (player == 'A')
		{
			printf(" %s attacks %s! %s -%dHP \n",nlawan,nplayer,nplayer,atklawan );
			printf(" %s attacks %s! %s -%dHP \n",nplayer,nlawan,nlawan,atkplayer );
			
			//seri
		}else if (player == 'F')
		{	
			printf(" %s attacks %s! %s -%dHP \n",nlawan,nplayer,nplayer,atklawan );
		
		}else if (player == 'B')
		{
			printf(" %s attacks %s, but it's blocked \n",nlawan,nplayer );
		}
	}else if (lawan == 'F')
	{
		if (player == 'A')
		{
			printf(" %s attacks %s! %s -%dHP \n",nplayer,nlawan,nlawan,atkplayer );
			
		}else if (player == 'F')
		{
			printf(" %s flanks %s! %s -%dHP \n",nlawan,nplayer,nplayer,atklawan );
			printf(" %s flanks %s! %s -%dHP \n",nplayer,nlawan,nlawan,atkplayer );
			//
		}else if (player == 'B')
		{
			printf(" %s flanks %s! %s -%dHP \n",nlawan,nplayer,nplayer,atklawan );
		}
	}else if (lawan == 'B')
	{
		if (player == 'A')
		{
			printf(" %s attacks %s, but it's blocked \n",nplayer,nlawan );
		}else if (player == 'F')
		{
			printf(" %s flanks %s! %s -%dHP \n",nplayer,nlawan,nlawan,atkplayer );
		}else if (player == 'B')
		{
			printf(" %s blocks %s! \n",nlawan,nplayer);
			
			printf(" %s blocks %s! \n",nplayer,nlawan);
			//seri
		}
	}

}

void PrintHeader(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r){

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6d | STR : %-6d | DEF : %-6d | Round : %-6d \n",nama,level,hpplayer,atk,def,round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6d  | Command : ",enemy,hpenemy);
	PrintQueueClosed(qenemy,i,r);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintHeaderInBattle(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r,int x){

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6d | STR : %-6d | DEF : %-6d | Round : %-6d \n",nama,level,hpplayer,atk,def,round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6d  | Command : ",enemy,hpenemy);
	PrintQueuewithpointer(qenemy,x,i,r,true);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintAndInput(Queue *Q, int *i){
	char input,temp;
	int x;

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("Inserted Command : ");
	
	if (!IsEmpty(*Q)){
		PrintQueue(*Q);
	}
	x = *i;
	while(x != 4){
		printf("_ ");
		x++;
	}
	printf("\n");

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );

	printf("Command : ");
	scanf(" %c", &input);
	if ( input == 'D' ) {
		DelTail(Q,&temp);
		*i = *i -1;
	}else if(input == 'A' || input == 'B' || input == 'F'){
		*i = *i + 1;
		Add(Q,input);
	}else{
		printf("Masukan salah.\n");
	}

}

void PrintCommandInBattle(Queue Q, int i){

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("Inserted Command : ");

	PrintQueuewithpointer(Q,i,0,0,false);

	printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );

}

void RandomAngka(int *i, int *r){

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

}