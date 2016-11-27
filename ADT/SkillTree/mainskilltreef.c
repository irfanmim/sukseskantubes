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
	printf("Learn TortoiseShell .. \n");
	SearchAndLearn(&S, "TortoiseShell");
	ShowSkill(S);
	ShowAvailable(S);
	printf("%d\n", IsSkewLeft(S));
	printf("%d\n", IsSkewRight(S));
	printf("Ada skill Hoho : %d", Search(S, "Hoho")); printf("\n"); 
	printf("Ada skill Huhu ? : %d", Search(S, "Huhu")); printf("\n");
	AddDaunTerkiri(&S, 9, "HmHm");
	AddDaunTerkanan(&S, 8, "Huhu");
	ShowSkill(S);
	printf("%d\n", IsLearnt(S, "InitStatus"));
	SearchAndLearn(&S, "Terros");
	printf("%d\n", IsLearnt(S, "Guardian"));

	
	return 0;
}
	