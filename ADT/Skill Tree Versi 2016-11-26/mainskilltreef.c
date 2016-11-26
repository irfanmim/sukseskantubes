#include <stdio.h>
#include "battleandplayerf.h"
#include "skilltreef.h"

#define bug printf("bug");
#define nl printf("\n");
#define ping printf("ping!!!");

int main () {
	
	// Kamus
	
	char temp[20];
	SkillTree S;
	SkillTree Tes, P;
	
	// Algoritma
	MakeTree(1, Nil, Nil, &S);
	strcpy(Name(S), "Tes");
	printf("Tes %d", IsSkewLeft(S));
	printf("Starting .. \n");
	InitSkillTree(&S);
	ping bug ping nl
	SearchAndLearn(&S, "Hihi");
	printf("Hahaha");
	SearchAndLearn(&S, "InitStatus");
	printf("Skills loaded ... \n");
	ShowSkill(S);
	ShowAvailable(S);
	printf("\n");
	printf("IsBiner : %d\n", IsBiner(S));
	printf("Learn hihi .. \n");
	ShowSkill(S);
	ShowAvailable(S);
	printf("%d\n %d\n", IsSkewLeft(Left(S)), IsSkewRight(S)); bug bug nl
	printf("Ada skill Hoho : %d", Search(S, "Hoho")); printf("\n"); 
	printf("Ada skill Huhu ? : %d", Search(S, "Huhu")); printf("\n");
	AddDaunTerkiri(&S, 9, "HmHm");
	AddDaunTerkanan(&S, 8, "Huhu");
	ShowSkill(S);
	
	
	return 0;
}
	