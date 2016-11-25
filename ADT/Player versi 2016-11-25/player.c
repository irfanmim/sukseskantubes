#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "custring.h"
#include "player.h"
#include "point.h"
#include "soqlist.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

void HPUP (player *P1, int N)
/*	Mengembalikan HP Pemain sejumlah N */
{
	HP(*P1) += N;
}

void HPDOWN (player *P1, player P2)
/*	Mengurangi HP Pemain akibat serangan Pemain lain */
{
	if (STR(P2) > DEF(*P1))
	{
		HP(*P1) -= STR(P2) - DEF(*P1);
	}
	else
	{
		--HP(*P1);
	}
}

boolean isLvlUp (player *P1, int Exp[])
/*  Menentukan apakah Pemain dapat naik ke Level berikutnya
	dengan EXP sekarang */
{
	return (EXP(*P1) >= Exp[LVL(*P1)]);
}

void LVLUP (player *P1, int Exp[])
/*	Menaikkan Level Pemain sebanyak 1 */
{
	EXP(*P1) -= Exp[LVL(*P1)];
	++LVL(*P1);
}

void RestoredHP (player *P1)
/*	Mengembalikan HP Pemain menjadi Maksimum */
{
	HP(*P1) = HPMAX(*P1);
}

boolean isDeath (player *P1)
/*	Mengecek apakah pemain sudah mati atau belum */
{
	return (HP(*P1) <= 0);
}

//BATTLE
void bertarungreal(char lawan, char cplayer, player *me, player *enemy)
{
	if (lawan == 'A')
	{
		if (cplayer == 'A')
		{
			HPDOWN(me, *enemy);
			HPDOWN(enemy, *me);			
			/* DRAW */
		}
		else if (cplayer == 'F')
		{	
			HPDOWN(me, *enemy);

		}
		else if (cplayer == 'B')
		{
			/* WE SUCESSFULLY BLOCKED ENEMY ATTACK */
		}
	}
	else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			HPDOWN(enemy, *me);
			
		}
		else if (cplayer == 'F')
		{
			HPDOWN(me, *enemy);
			HPDOWN(enemy, *me);
			/* DRAW */
		}
		else if (cplayer == 'B')
		{
			HPDOWN(me, *enemy);
		}
	}
	else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
			/* IT DOESN'T EFFECT WITH FOE */
		}
		else if (cplayer == 'F')
		{
			HPDOWN(enemy, *me);
		}
		else if (cplayer == 'B')
		{
			/* NO ONE DO PYSHICAL ATTACK */
		}
	}
}

void bertarungstatus(char lawan, char cplayer, player me, player enemy)
{
	if (lawan == 'A')
	{
		if (cplayer == 'A')
		{
			printf(" %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy) );
			printf(" %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me) );
			
			//seri
		}
		else if (cplayer == 'F')
		{	
			printf(" %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy) );
		
		}
		else if (cplayer == 'B')
		{
			printf(" %s attacks %s, but it's blocked \n",NAME(enemy),NAME(me) );
		}
	}
	else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			printf(" %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me));
			
		}
		else if (cplayer == 'F')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy));
			printf(" %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me));
			//
		}
		else if (cplayer == 'B')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy));
		}
	}
	else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
			printf(" %s attacks %s, but it's blocked \n",NAME(me),NAME(enemy));
		}
		else if (cplayer == 'F')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me) );
		}
		else if (cplayer == 'B')
		{
			printf(" %s blocks %s! \n",NAME(enemy),NAME(me));
			
			printf(" %s blocks %s! \n",NAME(me),NAME(enemy));
			//seri
		}
	}

}

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i, int r)
{
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),STR(me),DEF(me),round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	PrintQueueClosed(qenemy,i,r);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x)
{
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),STR(me),DEF(me),round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	PrintQueuewithpointer(qenemy,x,i,r,true);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintAndInput(Queue *Q, int *i)
{
	char input, temp;
	int x;

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("Inserted Command : ");
	
	if (!IsEmptyQueue(*Q))
	{
		PrintQueue(*Q);
	}
	x = *i;
	while(x != 4)
	{
		printf("_ ");
		x++;
	}
	printf("\n");

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );

	printf("Command : ");
	scanf(" %c", &input);
	if ( input == 'E' )
	{
		if(!IsEmptyQueue(*Q))
		{	
			DelTail(Q,&temp);
			*i = *i -1;
		}
	}
	
	else if(input == 'A' || input == 'B' || input == 'F')
	{
		*i = *i + 1;
		Add(Q,input);
	}
	
	else
	{
		printf("Masukan salah.\n");
	}

}

void PrintCommandInBattle(Queue Q, int i)
{

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("Inserted Command : ");

	PrintQueuewithpointer(Q,i,0,0,false);

	printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );

}

void RandomAngka(int *i, int *r)
{
	srand(time(NULL));
    *i = rand() % 4;
    *r = rand() % 4;
    int temp1, count;

    while ( *i == *r )
    {
        *i = rand() % 4;
    }

    if ( *i > *r )
    {
        temp1 = *i;
        *i = *r;
        *r = temp1;
    }

}

void BattleOn(player *me, player enemy, Stack enemySTR, boolean *win)
{
	system("clear");
	Queue STRenm, STRpl;
	int i, x, z, r1, r2, round;
	addressq penemy, pplayer;

	round = 1;
	while(HP(*me) > 0 && HP(enemy) > 0 && round <= 10)
	{
		CreateEmptyQueue(&STRpl);
		Pop(&enemySTR,&STRenm);

		RandomAngka(&r1,&r2);

		i = 0;
		do
		{
			PrintHeader(*me,enemy,round,STRenm,r1,r2);
			printf("\n");
			printf("\n");
			printf("\n");
			PrintAndInput(&STRpl,&i);
			//Jika masukan salah belum ditambah

			if (i == 4)
			{
				//Tambahin Print
				printf("Are you sure with this command? (Y/N)\n");
				printf("Answer ");
				char ans;
				scanf(" %c",&ans);
				while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n')
				{
					printf("Answer error, Answer again :");
					scanf(" %c",&ans);
				}	
				if (ans == 'Y' || ans == 'y')
				{
					/* PROESESSING */
				}
				else if(ans == 'N' || ans == 'n')
				{
					DelTail(&STRpl,&ans);
					i--;
				}
					
			}

			system("clear");
				
		} while(i != 4);

		while (getchar()!='\n');		

		pplayer = Head(STRpl);
		penemy = Head(STRenm);

		z = 0;
		while (HP(*me) > 0 && HP(enemy) > 0 && z <= 3)
		{
			infotypeq prevplayer, prevlawan;
			bertarungreal(Info(penemy), Info(pplayer), me, &enemy);
			PrintHeaderInBattle(*me,enemy,round,STRenm,r1,r2,z);

			printf("\n");
			if (z == 0)
			{
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);
			}
	
			else
			{
				bertarungstatus(prevlawan,prevplayer,*me,enemy);
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);

			}

			printf("\n");

			PrintCommandInBattle(STRpl,z);

			while(getchar()!='\n');
			
			system("clear");
			penemy = Next(penemy);
			pplayer = Next(pplayer);
			z++;
		}
		round++;	
	}
	if (HP(enemy) <= 0)
	{
		*win = true;
	}
	else
	{
		*win = false;
	}
}