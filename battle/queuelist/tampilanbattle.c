#include <stdio.h>
#include <string.h>
#include "queuelist.h"

void PrintHeader(char nama[200], int hpplayer, int level, int atk, int def , int round,int hpenemy, Queue qenemy, int *i,int  *r){

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %d      | HP : %d       | STR : %d      | DEF : %d   | Round : %d    \n",nama,level,hpplayer,atk,def,round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("                       | HP : %d       | Command : ",hpenemy);
	PrintQueueRandom(qenemy,i,r);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

int main (){
	char x[200];
	scanf("%s",x);
	Queue Q;

	int i , r;

	CreateEmpty(&Q);

	Add(&Q,'F');
	Add(&Q,'B');
	Add(&Q,'F');
	Add(&Q,'A');

	PrintHeader(x,100,999,999,999,1,25,Q,&i,&r);	
	while(getchar()!='\n');

	printf("%d %d\n",i,r );
	return 0;
}