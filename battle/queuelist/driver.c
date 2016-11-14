#include "boolean.h"
#include "queuelist.h"
#include <stdio.h>
//#include <conio.h>

void bertarung(char lawan, char player, int *splayer, int *slawan);

void PrintHeader(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r);

void PrintHeaderInBattle(char nama[200],char enemy[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int i,int  r,int x);

void PrintAndInput(Queue *Q, int *i);

void PrintCommandInBattle(Queue Q, int i);

int main() {
	Queue Q,Battle;
	char input,temp,tempplayer,templawan;
	int i,scorelawan,scoreplayer,x,z,r1,r2;

	address penemy,pplayer;

	char pl[200],en[200];

	CreateEmpty(&Q);
	CreateEmpty(&Battle);

	Add(&Q,'F');
	Add(&Q,'B');
	Add(&Q,'F');
	Add(&Q,'A');

	PrintQueueRandom(Q,&r1,&r2);

	printf("\n");
	scorelawan = 0;
	scoreplayer = 0;
	i = 0;

	scanf(" %s",pl);
	scanf(" %s",en);

	do{
		PrintHeader(pl,en,100,999,999,999,1,25,Q,r1,r2);
		printf("\n");
		printf("\n");
		printf("\n");
		PrintAndInput(&Battle,&i);
		
		//clrscr();
	}while(i != 4);


	PrintQueue(Battle);

	printf("\n");

	printf("Player : %d           Enemy : %d\n",scoreplayer,scorelawan);

	penemy = Head(Q);
	pplayer = Head(Battle);

	for (int z = 0; z <= 3; z++)
	{
		PrintHeaderInBattle(pl,en,100,999,999,999,1,25,Q,r1,r2,z);

		printf("\n");

		bertarung(Info(penemy),Info(pplayer),&scoreplayer,&scorelawan);
		printf("Player : %d           Enemy : %d\n",scoreplayer,scorelawan);

		printf("\n");

		PrintCommandInBattle(Battle,z);
		
		while(getchar()!='\n');
		//clrscr();

		penemy = Next(penemy);
		pplayer = Next(pplayer);

	}

	printf("\n");
	return 0;
}

void bertarung(char lawan, char player, int *splayer, int *slawan){
	if (lawan == 'A')
	{
		if (player == 'A')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			//seri
		}else if (player == 'F')
		{	
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*slawan = *slawan + 1;
		}else if (player == 'B')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*splayer = *splayer + 1;
		}
	}else if (lawan == 'F')
	{
		if (player == 'A')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*splayer = *splayer + 1;
		}else if (player == 'F')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			//seri
		}else if (player == 'B')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*slawan = *slawan + 1;
		}
	}else if (lawan == 'B')
	{
		if (player == 'A')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*slawan = *slawan + 1;
		}else if (player == 'F')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
			*splayer = *splayer + 1;
		}else if (player == 'B')
		{
			printf("Player use %c and Enemy use %c\n",player,lawan );
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