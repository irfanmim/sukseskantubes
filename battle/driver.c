#include "boolean.h"
#include "queue.h"
#include <stdio.h>

void bertarung(char lawan, char player, int *splayer, int *slawan);

int main() {
	Queue Q,Battle;
	char input,temp,tempplayer,templawan;
	int i,scorelawan,scoreplayer,x,z,r1,r2;

	CreateEmpty(&Q,4);
	CreateEmpty(&Battle,4);

	Add(&Q,'F');
	Add(&Q,'B');
	Add(&Q,'F');
	Add(&Q,'A');

	PrintQueueRandom(Q,&r1,&r2);

	printf("\n");
	scorelawan = 0;
	scoreplayer = 0;
	i = 0;
	printf("Masukkan Aksi : ");
	scanf("%c", &input);
	while ( i != 4 ) {
		
		if ( input == 'D' ) {
			Del(&Battle,&temp);
			i--;
		}else if(input == 'A' || input == 'B' || input == 'F'){
			i++;
			Add(&Battle,input);
		}else{
			printf("Masukan salah.\n");
		}

		PrintQueue(Battle);
		x = i;
		while(x != 4){
			printf("_ ");
			x++;
		}

		printf("\n");
		if (i != 4){
			printf("Masukkan Aksi : ");
			scanf(" %c", &input);
		}
	}


	PrintQueue(Battle);
	printf("\n");

	printf("Player : %d           Enemy : %d\n",scoreplayer,scorelawan);

	for (int z = 0; z <= 3; z++)
	{
		PrintQueuewithpointer(Q,z,r1,r2,true);
		printf("\n");
		PrintQueuewithpointer(Battle,z,r1,r2,false);
		printf("\n");
	
		Del(&Q,&templawan);
		Del(&Battle,&tempplayer);

		bertarung(templawan,tempplayer,&scoreplayer,&scorelawan);
		printf("Player : %d           Enemy : %d\n",scoreplayer,scorelawan);

		Add(&Q,templawan);
		Add(&Battle, tempplayer);
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
