#include <stdio.h>
#include "player.h"
#include "skilltree.h"

int main () {
	
	// Kamus
	
	player Utama;
	char temp[20];
	SkillTree Parent;
	
	// Algoritma
	InitSkillTree(&(STREE(Utama)));
	ShowSkill(STREE(Utama));
	return 0;
}
	