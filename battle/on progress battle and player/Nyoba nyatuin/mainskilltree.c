#include <stdio.h>
#include "battleandplayer.h"
#include "skilltree.h"

int main () {
	
	// Kamus
	
	player P1;
	char temp[20];
	
	// Algoritma
	InitSkillTree(&(STREE(P1)));
	ShowSkill(STREE(P1));
	ActivateSkill(&P1, &STREE(P1));
	HPMAX(P1) = 50;
	ATK(P1) = 20;
	DEF(P1) = 30;
	ShowStatus(P1);
	SPt(P1) += 5;
	strcpy(temp, "ATKUP");
	Learn(&P1, temp);
	strcpy(temp, "DEFUP");
	Learn(&P1, temp);	
	ActivateSkill(&P1, &STREE(P1));
	ShowSkill(STREE(P1));
	ShowStatus(P1);
	
	return 0;
}
	