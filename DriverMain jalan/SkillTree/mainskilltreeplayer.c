#include <stdio.h>
#include "player.h"
#include "skilltree.h"

#define bug printf("bug");
#define nl printf("\n");
#define ping printf("ping!!!");

int main () {
	
	// Kamus
	
	char temp[20];
	SkillTree S;
	player Utama;
	
	// Algoritma
	
	InitSkillTree(&(STREE(Utama)));
	ShowAvailable(STREE(Utama));
	
	return 0;
}
	