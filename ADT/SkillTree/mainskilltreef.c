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
	
	// Algoritma
	
	printf("Starting .. \n");
	InitSkillTree(&S);
	SearchAndLearn(&S, "InitStatus");
	printf("Skills loaded ... \n");
	ShowSkill(S);
	ShowAvailable(S);
	printf("\n");
	printf("Learn hihi .. \n");
	ShowSkill(S);
	ShowAvailable(S);
	printf("%d\n %d\n", IsSkewLeft(S), IsSkewRight(S)); bug bug nl
	printf("Ada skill Hoho : %d", Search(S, "Hoho")); printf("\n"); 
	printf("Ada skill Huhu ? : %d", Search(S, "Huhu")); printf("\n");
	AddDaunTerkiri(&S, 9, "HmHm");
	AddDaunTerkanan(&S, 8, "Huhu");
	ShowSkill(S);
	
	
	return 0;
}
	