#include "point.h"
#include "boolean.h"
#include "battleandplayer.h"
#include <time.h>
#include "soqlist.h"
#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>
#include <string.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

void HPUP (player *P1, int N)
/*	Mengembalikan HP Pemain sejumlah N */
{
	HP(*P1) += N;
}

void HPDOWN (player *P1, player P2)
/*	Mengurangi HP Pemain akibat serangan Pemain lain */
{
	HP(*P1) -= ATK(P2) - DEF(*P1);
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

/* *** SKILL TREE *** */
void InitSkillTree(SkillTree *S)
// I.S : Sembarang
// F.S : Daftar skill player diinisialisasi, learnt = false kecuali root
{
	// Kamus
	FILE *daftarskill;
	daftarskill = fopen("daftarskill.txt", "r");
	char line[50];
	int i;
	char temp[50];
	
	// Algoritma
	i = 0;
	while (!feof(daftarskill)) {
		/*
		statusarr[0] = Pertambahan HPMAX;
		statusarr[1] = Pertambahan ATK;
		statusarr[2] = Pertambahan DEF;
		*/
		
		// InitStatus
		fgets(line, 50, daftarskill);
		sscanf(line, "%s", temp);
		MakeTree(temp, Nil, Nil, S);
		Learnt(STREE(*P1)) = true;
	
		// ATTACK SKILL TREE
		while(strcmp(line, "ATTACK") != 0) {
			fgets(line, 50, daftarskill);
		}
		while(strcmp(line, "DEFENSE") != 0) { 
			sscanf(line, "%s", temp);
			AddDaunTerkiri(S, temp);
			fgets(line, 50, daftarskill);
		}
		
		// DEFENSE SKILL TREE
		while(strcmp(line, "END") != 0) {
			sscanf(line, "%s", temp);
			AddDaunTerkanan(S, temp);
			fgets(line, 50, daftarskill);
		}
	}
	// EOF
}
	
void ActivateSkill(SkillTree * S)
// I.S : Lvl terdefinisi, skill tree telah diinisialisasi
// F.S : Menambah status karakter sesuai skill yang telah diperoleh
{
	// Kamus
	
	// Algoritma
/*	if (IsTreeOneElmt(STREE(*P1))) {
		 if (Learnt(STREE(*P1))) {
			 if (strcmp(Akar(STREE(*P1)), "ATKUP") == 0) {
				 ATKUP(P1);
			 }
			 else if (strcmp(Akar(STREE(*P1)), "DEFUP") == 0) {
				 DEFUP(P1);
			 }
		 }
		else {
			;
		}
	}
	else {
		ActivateSkill(P1, Left(skilltree));
		ActivateSkill(P1, Right(skilltree));
	} */
	if (IsTreeEmpty(*S)) {
		;
	}
	else {
		if (Learnt(*S)) {
			 if (strcmp(Akar(*S)), "ATKUP") == 0) {
				 ATKUP(P1);
			 }
			 else if (strcmp(Akar(*S)), "DEFUP") == 0) {
				 DEFUP(P1);
			 }
		 }
		else {
			;
		}
		ActivateSkill(Left(S));
		ActivateSkill(Right(S));
}

void Learn(SkillTree * S, char * nama)
// I.S : Skill point >= nol
// F.S : Mempelajari skill baru dalam skill tree
{
	if (SPt(*P1) > 0) {
		SearchAndLearn(S, nama);
	}
	else {
		printf("Skill pointmu tidak mencukupi.");
	}
		
void ShowSkill(SkillTree * S){}
// I.S : Skill Tree P1 terdefinisi
// F.S : Menampilkan seluruh daftar skill yang sudah dan belum dipelajari. Skill yang sudah dipelajari diberi keterangan (learned).

boolean Search(SkillTree S, char * nama);
// Mengembalikan true jika terdapat skill dengan nama 'nama' di S
{
	if (IsTreeEmpty(S)) {
		return false;
	}
	else {
		if (strcmp(Name(S), nama) == 0)  {
			return true;
		}
		else { 
			return (Search(Left(S), nama) || Search(Right(S), nama));
		}
	}
}

void SearchAndLearn(SkillTree *S, char * nama)
// I.S : S telah diinisialisasi, skill dengan nama 'nama' ada dalam S
// F.S : Learnt skill 'nama' = true
{
	// Kamus
	
	// Algoritma
	if (IsTreeEmpty(*S)) {
		;
	}
	else {
		if (strcmp(Name(*S), nama) == 0) {
			Learnt(*S) = true;
		}
		else {
			if (Search(Left(*S), nama)) {
				SearchAndLearn(&Left(*S), nama);
			}
			else if (Search(Right(*S)), nama) {
				SearchAndLearn(&Right(*S), nama);
			}
			else {
				;
			}
		}
	}
}

/* *** DAFTAR SKILL *** */
void ATKUP(player *P1){}
// I.S : 
// F.S : 
void DEFUP(player *P1){}
// I.S :
// F.S : 	
//BATTLE
void bertarungreal(char lawan, char cplayer, player *me, player *enemy){
	if (lawan == 'A')
	{
		if (cplayer == 'A')
		{
			HP(*me) = HP(*me) - ATK(*enemy);
			HP(*enemy) = HP(*enemy) - ATK(*me);
			
			//seri
		}else if (cplayer == 'F')
		{	
			HP(*me) = HP(*me) - ATK(*enemy);

		}else if (cplayer == 'B')
		{
		}
	}else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			HP(*enemy) = HP(*enemy) - ATK(*me);
			
		}else if (cplayer == 'F')
		{
			HP(*me) = HP(*me) - ATK(*enemy);
			HP(*enemy) = HP(*enemy) - ATK(*me);
			//
		}else if (cplayer == 'B')
		{
			HP(*me) = HP(*me) - ATK(*enemy);
		}
	}else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
		}else if (cplayer == 'F')
		{
			HP(*enemy) = HP(*enemy) - ATK(*me);
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
			printf(" %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),ATK(enemy) );
			printf(" %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),ATK(me) );
			
			//seri
		}else if (cplayer == 'F')
		{	
			printf(" %s attacks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),ATK(enemy) );
		
		}else if (cplayer == 'B')
		{
			printf(" %s attacks %s, but it's blocked \n",NAME(enemy),NAME(me) );
		}
	}else if (lawan == 'F')
	{
		if (cplayer == 'A')
		{
			printf(" %s attacks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),ATK(me));
			
		}else if (cplayer == 'F')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),ATK(enemy) );
			printf(" %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),ATK(me));
			//
		}else if (cplayer == 'B')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(enemy),NAME(me),NAME(me),ATK(enemy));
		}
	}else if (lawan == 'B')
	{
		if (cplayer == 'A')
		{
			printf(" %s attacks %s, but it's blocked \n",NAME(me),NAME(enemy));
		}else if (cplayer == 'F')
		{
			printf(" %s flanks %s! %s -%ldHP \n",NAME(me),NAME(enemy),NAME(enemy),ATK(me) );
		}else if (cplayer == 'B')
		{
			printf(" %s blocks %s! \n",NAME(enemy),NAME(me));
			
			printf(" %s blocks %s! \n",NAME(me),NAME(enemy));
			//seri
		}
	}

}

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i,int  r){
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),ATK(me),DEF(me),round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	PrintQueueClosed(qenemy,i,r);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x){
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| LVL : %-6d | HP : %-6ld | STR : %-6ld | DEF : %-6ld | Round : %-6d \n",NAME(me),LVL(me),HP(me),ATK(me),DEF(me),round);
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf(" %-22s| HP : %-6ld  | Command : ",NAME(enemy),HP(enemy));
	PrintQueuewithpointer(qenemy,x,i,r,true);printf("\n");
	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
}

void PrintAndInput(Queue *Q, int *i){
	char input,temp;
	int x;

	printf("════════════════════════════════════════════════════════════════════════════════════════════════════\n" );
	printf("Inserted Command : ");
	
	if (!IsEmptyQueue(*Q)){
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
		if(!IsEmptyQueue(*Q)){	
			DelTail(Q,&temp);
			*i = *i -1;
		}
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

void BattleOn(player *me, player enemy, Stack enemyatk ){
	Queue atkenm,atkpl;
	int i,x,z,r1,r2,round;
	addressq penemy,pplayer;

	round = 1;
	while(HP(*me) > 0 && HP(enemy) > 0 && round <= 10){
		CreateEmptyQueue(&atkpl);
		Pop(&enemyatk,&atkenm);

		RandomAngka(&r1,&r2);

		i = 0;
		do{
			PrintHeader(*me,enemy,round,atkenm,r1,r2);
			printf("\n");
			printf("\n");
			printf("\n");
			PrintAndInput(&atkpl,&i);
			//Jika masukan salah belum ditambah

			if (i == 4){
				//Tambahin Print
				printf("Are you sure with this command? (Y/N)\n");
				printf("Answer ");
				char ans;
				scanf(" %c",&ans);
				while(ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'){
					printf("Answer error, Answer again :");
					scanf(" %c",&ans);
				}	
				if(ans == 'Y' || ans == 'y'){

				}else if(ans == 'N' || ans == 'n'){
					DelTail(&atkpl,&ans);
					i--;
				}
					
			}

			system("clear");
				
		}while(i != 4);

		while(getchar()!='\n');		

		pplayer = Head(atkpl);
		penemy = Head(atkenm);

		z = 0;
		while(HP(*me) > 0 && HP(enemy) > 0 && z <= 3){
			infotypeq prevplayer,prevlawan;
			bertarungreal(Info(penemy),Info(pplayer),me,&enemy);
			PrintHeaderInBattle(*me,enemy,round,atkenm,r1,r2,z);

			printf("\n");
			if (z == 0){
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);
			}else{
				bertarungstatus(prevlawan,prevplayer,*me,enemy);
				bertarungstatus(Info(penemy),Info(pplayer),*me,enemy);
				prevlawan = Info(penemy);
				prevplayer = Info(pplayer);

			}

			printf("\n");

			PrintCommandInBattle(atkpl,z);

			while(getchar()!='\n');
			
			system("clear");
			penemy = Next(penemy);
			pplayer = Next(pplayer);
			z++;
		}
		round++;	
	}

}