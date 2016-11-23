#include "point.h"
#include "boolean.h"
#include "battleandplayer.h"
#include <time.h>
#include "soqlist.h"
#include <stdio.h>

void inputdata(player *pl);

void makestack(Stack *st);

int main (){
	player kita,musuh;
	Stack stenemy;
	Queue q;

	inputdata(&kita);
	inputdata(&musuh);

	HP(kita) = 50;
	HP(musuh) = 25;
	
	system("clear");

	makestack(&stenemy);

	//Pop(&stenemy,&q);

	//PrintQueue(q);
	
	BattleOn(&kita,musuh,stenemy);

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

    z = 1;
    while(z <= 10){
    	CreateEmptyQueue(&temp);
		for (int i = 1; i <= 4; i++)
		{
			srand(time(NULL));
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
