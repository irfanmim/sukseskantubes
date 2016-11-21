#include <stdio.h>
#include "battleandplayer.h"
#include "skilltree.h"

int main () {
	
	// Kamus
	
	player P1;
	
	// Algoritma
	InitSkillTree(&(STREE(P1)));
	ShowSkill(STREE(P1));
	
	return 0;
}
	