#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "battleandplayer.h"

void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}

int main () {
	int count;

	scanf("%d",&count);

	//while(c!=48){
		system("clear");
		int i;
		//system("color 30");
		for (int i = 0; i < count; ++i){
			gotoxy(i,1);
			printf("═" );
		}
		
		//printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),ATK(me),DEF(me),round);
		//system("color 30");
		for (int i = 0; i < count; ++i){
			gotoxy(i,3);
			printf("═" );
		}

		//printf(" %-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
		//PrintQueueClosed(qenemy,i,r);printf("\n");
		//system("color 30");
		for (int i = 0; i < count; ++i){
			gotoxy(i,5);
			printf("═" );
		}
		gotoxy(1,2);
		//system("color 30");
		printf("Nama : \n");
		gotoxy(0,5);
		printf("\n");

		getchar();

	//}
	return 0;
}