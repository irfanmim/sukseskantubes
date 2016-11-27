#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "custring.h"
#include "player.h"
#include "point.h"
#include "soqlist.h"

void gotoxy(int x, int y) {
	printf("%c[%d;%df", 0x1B, y, x);
}

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

void HPUP (player *P1, int N)
/*	Mengembalikan HP Pemain sejumlah N */
{
	HP(*P1) += N;
}

void HPDOWN (player *P1, player P2)
/*	Mengurangi HP Pemain akibat serangan Pemain lain */
{
	HP(*P1) -= STR(P2) - DEF(*P1);
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

boolean isDeath (player P1)
/*	Mengecek apakah pemain sudah mati atau belum */
{
	return (HP(P1) <= 0);
}

void ShowStatus(player P1)
// I.S : P1 terdefinisi
// F.S : Menampilkan current status P1 (HP, STR, DEF)
{
	printf("HP : %ld\nATK : %ld\nDEF : %ld\n", HPMAX(P1), STR(P1), DEF(P1));
}

/* *** PROSES SKILL TREE *** */
void ActivateSkill(player * P1, SkillTree *S)
// I.S : Lvl terdefinisi, skill tree telah diinisialisasi
// F.S : Menambah status karakter sesuai skill yang telah diperoleh
{
	if (IsTreeEmpty((*S))) {
		;
	}
	else {
		if (Learnt(*S)) {
			 if (Strcmp(Name(*S), "ATKUP")) {
				 ATKUP(P1);
			 }
			 else if (Strcmp(Name(*S), "Slayer")) {
				 Slayer(P1);
			 }
			else if (Strcmp(Name(*S), "Berserk")) {
				 Berserk(P1);
			 }
			else if (Strcmp(Name(*S), "Terror")) {
				 Terror(P1);
			 }
			else if (Strcmp(Name(*S), "DEFUP")) {
				 DEFUP(P1);
			 }
			else if (Strcmp(Name(*S), "TortoiseShell")) {
				 TortoiseShell(P1);
			 }
			else if (Strcmp(Name(*S), "DemonPact")) {
				 DemonPact(P1);
			 }
			else if (Strcmp(Name(*S), "Guardian")) {
				 Guardian(P1);
			 }
		 }
		else {
			;
		}
		ActivateSkill(P1, &(Left(*S)));
		ActivateSkill(P1, &(Right(*S)));
	}
}
	
	
void Learn(player *P1, char * nama)
// I.S : Skill point >= nol
// F.S : Mempelajari skill baru dalam skill tree
{
	if (SPt(*P1) > 0) {
		SearchAndLearn(&(STREE(*P1)), nama);
		SPt(*P1) = SPt(*P1) - 1;
	}
	else {
		printf("Skill pointmu tidak mencukupi.");
	}
}

/* *** DAFTAR SKILLL *** */

void ATKUP(player *P1)
{
	STR(*P1) += 5;
}
void Slayer(player *P1)
{
	STR(*P1) += 10;
}
void Berserk(player *P1)
{
	DEF(*P1) -= 15;
	STR(*P1) = STR(*P1) + ((5 / 100) * STR(*P1));
}
void Terror(player *P1)
{
	STR(*P1) = STR(*P1) + ((1/10) * STR(*P1));
	HPMAX(*P1) = HPMAX(*P1) + ((5/100) * HPMAX(*P1));
}
void InstantKill(player *P1)
{
	;
}
// DEFEND
void DEFUP(player *P1)
{
	DEF(*P1) += 5;
}
void TortoiseShell(player *P1) 
{
	DEF(*P1) += 15;
}
void DemonPact(player *P1)
{
	STR(*P1) -= 10;
	HPMAX(*P1) = HPMAX(*P1) + ((1/10) * HPMAX(*P1));
}
void Guardian(player *P1)
{
	HPMAX(*P1) = HPMAX(*P1) + ((5/100) * HPMAX(*P1));
	DEF(*P1) = DEF(*P1) + ((1/10) * DEF(*P1));
}

//BATTLE
void bertarungreal(char lawan, char cplayer, player *me, player *enemy){
	if (lawan == 'A')
	{
		if (cplayer == 'A')
		{
			HP(*me) = HP(*me) - STR(*enemy);
			HP(*enemy) = HP(*enemy) - STR(*me);
			
			//seri
		}else if (cplayer == 'F')
		{	
			HP(*me) = HP(*me) - STR(*enemy);

		}else if (cplayer == 'B')
		{
		}
	}else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			HP(*enemy) = HP(*enemy) - STR(*me);
			
		}else if (cplayer == 'F')
		{
			HP(*me) = HP(*me) - STR(*enemy);
			HP(*enemy) = HP(*enemy) - STR(*me);
			//
		}else if (cplayer == 'B')
		{
			HP(*me) = HP(*me) - STR(*enemy);
		}
	}else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
		}else if (cplayer == 'F')
		{
			HP(*enemy) = HP(*enemy) - STR(*me);
		}else if (cplayer == 'B')
		{
		}
	}
}

void bertarungstatus(char lawan, char cplayer, player me, player enemy){
	if (lawan == 'A')
	{
		if (cplayer == 'A')
		{	
			printf("║ %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy) );
			printf("║ %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me) );
			
			//seri
		}else if (cplayer == 'F')
		{	
			printf("║ %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy) );
		
		}else if (cplayer == 'B')
		{
			printf("║ %s attacks %s, but it's blocked \n",NAME(enemy),NAME(me) );
		}
	}else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			printf("║ %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me));
			
		}else if (cplayer == 'F')
		{
			printf("║ %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy) );
			printf("║ %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me));
			//
		}else if (cplayer == 'B')
		{
			printf("║ %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),STR(enemy));
		}
	}else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
			printf("║ %s attacks %s, but it's blocked \n",NAME(me),NAME(enemy));
		}else if (cplayer == 'F')
		{
			printf("║ %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),STR(me) );
		}else if (cplayer == 'B')
		{
			printf("║ %s blocks %s! \n",NAME(enemy),NAME(me));
			
			printf("║ %s blocks %s! \n",NAME(me),NAME(enemy));
			//seri
		}
	}

}

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i,int  r, int lebar, int tinggi){
	for (int w = 0; w <= lebar; w++){
		gotoxy(w,1);
		if(w == 1){
			printf("╔");
		}else if (w == lebar){
			printf("╗");
		}else if(w == lebar-10 || w == lebar-18 || w == lebar-26 || w == lebar-35 || w == lebar-43){
			printf("╦");
		}else{
			printf("═" );
		}
	}
	
	gotoxy(0,2);
	//printf(" %s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),STR(me),DEF(me),round);
	printf("║%s",NAME(me) );
	gotoxy(lebar - 43,2);
	printf("║LVL:%d",LVL(me) );
	gotoxy(lebar - 35,2);
	printf("║HP:%ld",HP(me) );
	gotoxy(lebar - 26,2);
	printf("║STR:%ld",STR(me) );
	gotoxy(lebar - 18,2);
	printf("║DEF:%ld",DEF(me) );
	gotoxy(lebar - 10,2);
	printf("║Round:%d",round );
	gotoxy(lebar,2);
	printf("║\n");
	for (int w = 0; w <= lebar; w++){
		gotoxy(w,3);
		if(w == 1){
			printf("╠");
		}else if (w == lebar){
			printf("╣");
		}else if(w == lebar-10 || w == lebar-18 || w == lebar-26 ){
			printf("╩");
		}else if (w == lebar-43 || w == lebar-35){
			printf("╬");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,4);
	//printf("%-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	printf("║%s",NAME(enemy) );
	gotoxy(lebar - 43,4);
	printf("║HP:%ld",HP(enemy) );
	gotoxy(lebar - 35,4);
	printf("║Command :");
	PrintQueueClosed(qenemy,i,r);printf("\n");
	gotoxy(lebar,4);
	printf("║");

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,5);
		if(w == 1){
			printf("╠");
		}else if(w == lebar-35 || w == lebar-43){
			printf("╩");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	for (int w = 6; w <= tinggi-5; w++){
		gotoxy(0,w);
		printf("║");
		gotoxy(lebar,w);
		printf("║");
	}
}

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x,int lebar , int tinggi){
	for (int w = 0; w <= lebar; w++){
		gotoxy(w,1);
		if(w == 1){
			printf("╔");
		}else if (w == lebar){
			printf("╗");
		}else if(w == lebar-10 || w == lebar-18 || w == lebar-26 || w == lebar-35 || w == lebar-43){
			printf("╦");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,2);
	//printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),STR(me),DEF(me),round);
	printf("║%s",NAME(me) );
	gotoxy(lebar - 43,2);
	printf("║LVL:%d",LVL(me) );
	gotoxy(lebar - 35,2);
	printf("║HP:%ld",HP(me) );
	gotoxy(lebar - 26,2);
	printf("║STR:%ld",STR(me) );
	gotoxy(lebar - 18,2);
	printf("║DEF:%ld",DEF(me) );
	gotoxy(lebar - 10,2);
	printf("║Round:%d",round );
	gotoxy(lebar,2);
	printf("║");

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,3);
		if(w == 1){
			printf("╠");
		}else if (w == lebar){
			printf("╣");
		}else if(w == lebar-10 || w == lebar-18 || w == lebar-26 ){
			printf("╩");
		}else if (w == lebar-43 || w == lebar-35){
			printf("╬");
		}else{
			printf("═" );
		}
	}
	gotoxy(0,4);
	//printf("%-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	printf("║%s",NAME(enemy) );
	gotoxy(lebar - 43,4);
	printf("║HP:%ld",HP(enemy) );
	gotoxy(lebar - 35,4);
	printf("║Command :");	

	PrintQueuewithpointer(qenemy,x,i,r,true);printf("\n");
	gotoxy(lebar,4);
	printf("║");
	
	for (int w = 0; w <= lebar; w++){
		gotoxy(w,5);
		if(w == 1){
			printf("╠");
		}else if(w == lebar-35 || w == lebar-43){
			printf("╩");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	for (int w = 6; w <= tinggi-5; w++){
		gotoxy(0,w);
		printf("║");
		gotoxy(lebar,w);
		printf("║");
	}

}

void PrintAndInput(Queue *Q, int *i, int lebar, int tinggi, int *menang){
	char input,temp;
	int x,w;

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-4);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-3);
	printf("║Inserted Command : ");
	
	if (!IsEmptyQueue(*Q)){
		PrintQueue(*Q);
	}
	x = *i;
	while(x != 4){
		printf("_ ");
		x++;
	}
	printf("\n");

	gotoxy(lebar,tinggi-3);
	printf("║");

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-2);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(lebar,tinggi-1);
	printf("║");	

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi);
		if(w == 1){
			printf("╚");
		}else if(w == lebar){
			printf("╝");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-1);
	printf("║Command : ");
	scanf("%c", &input);
	if ( input == 'D' ) {
		if(!IsEmptyQueue(*Q)){	
			DelTail(Q,&temp);
			*i = *i -1;
		}
	}else if(input == 'A' || input == 'B' || input == 'F'){
		*i = *i + 1;
		Add(Q,input);
	}else if (input == 'Q'){
		*menang = *menang + 1;
	}else{
		printf("Masukan salah.\n");
	}

}

//tambahan
void PrintWithoutInput(Queue *Q, int *i, int lebar, int tinggi){
	char input,temp;
	int x,w;

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-4);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-3);
	printf("║Inserted Command : ");
	
	if (!IsEmptyQueue(*Q)){
		PrintQueue(*Q);
	}
	x = *i;
	while(x != 4){
		printf("_ ");
		x++;
	}
	printf("\n");

	gotoxy(lebar,tinggi-3);
	printf("║");

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-2);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-1);
	printf("║");	

	gotoxy(lebar,tinggi-1);
	printf("║");	

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi);
		if(w == 1){
			printf("╚");
		}else if(w == lebar){
			printf("╝");
		}else{
			printf("═" );
		}
	}
}

void PrintCommandInBattle(Queue Q, int i,int lebar, int tinggi){
	int w;

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-4);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-3);
	printf("║Inserted Command : ");

	PrintQueuewithpointer(Q,i,0,0,false);

	gotoxy(lebar,tinggi-3);
	printf("║");

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi-2);
		if(w == 1){
			printf("╠");
		}else if(w == lebar){
			printf("╣");
		}else{
			printf("═" );
		}
	}

	gotoxy(0,tinggi-1);
	printf("║");	

	gotoxy(lebar,tinggi-1);
	printf("║");	

	for (int w = 0; w <= lebar; w++){
		gotoxy(w,tinggi);
		if(w == 1){
			printf("╚");
		}else if(w == lebar){
			printf("╝");
		}else{
			printf("═" );
		}
	}

	gotoxy(2,tinggi-1);
	printf("Press enter to continue");

}

void RandomAngka(int *i, int *r){

	srand(time(NULL));
    *i = rand() % 4;
    *r = rand() % 4;
    int temp1;

    while ( *i == *r ){
        *i = rand() % 4;
    }

    if ( *i > *r ) {
        temp1 = *i;
        *i = *r;
        *r = temp1;
    }

}

void BattleOn(player *me, player enemy, Stack enemySTR, boolean *win, int lebar, int tinggi ){
	Queue STRenm,STRpl;
	int i,x,z,r1,r2,round,menang = 0;
	addressq penemy,pplayer;
	boolean selesai = false;

	round = 1;
	while(HP(*me) > 0 && HP(enemy) > 0 && round <= 10 ){
		CreateEmptyQueue(&STRpl);
		Pop(&enemySTR,&STRenm);

		RandomAngka(&r1,&r2);

		i = 0;
		selesai = false;
		while(!selesai){
			do{
				PrintHeader(*me,enemy,round,STRenm,r1,r2,lebar,tinggi);
				
				PrintAndInput(&STRpl,&i,lebar,tinggi,&menang);
				//Jika masukan salah belum ditambah

				system("clear");
				
				if(menang == 4){
					HP(enemy) = 0;
					i = 4;
					selesai = true;
				}
			}while(i!=4);
			if (menang != 4){
				PrintHeader(*me,enemy,round,STRenm,r1,r2,lebar,tinggi);
				
				PrintWithoutInput(&STRpl,&i,lebar,tinggi);
				if (i == 4){
					//Tambahin Print
					//printf("\n");
					gotoxy(2,tinggi-1);
					printf("Are you sure with this command? (Y/N) > ");
					//printf("Answer ");
					char ans;
					scanf("%c",&ans);
					//getchar();
					while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'){
						gotoxy(40,tinggi-1);
						for (int w = 40; w < lebar-1; w++){
							printf(" ");
						}
						gotoxy(40,tinggi-1);
						//printf("Answer error, Answer again :");
						scanf("%c",&ans);
					}	
					if(ans == 'Y' || ans == 'y'){
						selesai = true;
					}else if(ans == 'N' || ans == 'n'){
						DelTail(&STRpl,&ans);
						i--;
					}
						
				}
				gotoxy(2,tinggi-1);
				for (int w = 0; w <= lebar-3; w++){
					printf(" ");
				}
				system("clear");
			}

		}

		while(getchar()!='\n');		

		pplayer = Head(STRpl);
		penemy = Head(STRenm);

		z = 0;
		while(HP(*me) > 0 && HP(enemy) > 0 && z <= 3 ){
			infotypeq prevplayer,prevlawan;
			bertarungreal(Info(penemy),Info(pplayer),me,&enemy);
			PrintHeaderInBattle(*me,enemy,round,STRenm,r1,r2,z,lebar,tinggi);

			printf("\n");
			if (z == 0){
				gotoxy(1,tinggi/2);
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);
			}else{
				gotoxy(1,tinggi/2);
				bertarungstatus(prevlawan,prevplayer,*me,enemy);
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);

			}


			PrintCommandInBattle(STRpl,z,lebar,tinggi);

			//gotoxy(2,tinggi-1);
			while(getchar()!='\n');
			
			system("clear");
			penemy = Next(penemy);
			pplayer = Next(pplayer);
			z++;
		}
		round++;	
	}
	if(HP(*me) > 0 && round <= 10 && HP(enemy) <= 0 ){
		*win = true;
	}else{
		*win = false;
	}

}