#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "point.h"
#include "battleandplayer.h"
#include <time.h>
#include "soqlist.h"
#include "peta.h"
void printlogo();
// I.S : Sembarang
// F.S : Menghasilkan logo bright souls sebagai output 

void inputdata(player *pl);
// I.S : BattleOn dipanggil, bersiap memulai battle
// F.S : Status pl diinisialisasi sebelum memulai battle
		
void makestack(Stack *st);
// I.S : inputdata telah dipanggil
// F.S : Stack aksi musuh diinisialisasi sebelum meulai battle
	

void NewGame();
// I.S : Main Menu sedang dieksekusi
// F.S : Masuk ke dalam permainan
	 
int main() {
	
	// Kamus
	int input;
	boolean quit;
	
	// Algoritma
	printlogo();
	printf("\n\n");
	printf("1.	New Game\n");
	printf("2.	Continue\n");
	printf("3.	Quit Game\n\n");
	printf("Masukkan input . . .\n"); 
	
	quit = false;
	while (!quit) {
		scanf("%d", &input); printf("\n");
		switch (input) {
			case 1 : NewGame();
					break;
			case 2 :;
					break;
			case 3 : quit = true;
					break;
			default : printf("Input salah\n");
		}
	}
	
	return 0;
}
	
void printlogo() 
// I.S : Sembarang
// F.S : Menghasilkan logo bright souls sebagai output 
{
	FILE * logo;

	char M[300][300];
	int i, j, count; 	
	char cc;
	
	logo = fopen("logo.txt", "r");
	count = 0; i = 0; j = 0;
	while (cc != EOF) {
		cc = fgetc(logo);
		if ((cc != EOF) && ((int)(cc) != 10)) {
			M[i][j] = cc;
			j++;
		}
		else { // cc == EOF or cc == nl
			if ((int)(cc) == 10) {
				i++;
				count++;
				j = 0;
			}
		}
	}
	for (i = 0; i < count; i++) {
		printf("%s\n", M[i]);
	}
	
	fclose(logo);
	
}

void NewGame() {
	// I.S : Main Menu sedang dieksekusi
	// F.S : Masuk ke dalam permainan
	
	// Kamus Battle
	player kita,musuh;
	Stack stenemy;
	Queue q;
	// Kamus Peta
	FILE *namafile;
    PETA P;
    int Lebar = 10;
    int Panjang = 10;
	
	// Inisialisasi Peta
    MakePeta(Lebar,Panjang,&P);
    str filetxt = "pitakar.txt";
    ReadPeta(namafile,&P,filetxt);
    PrintPeta(P);
    PutarPeta(&P);
    printf("\n");
    PrintPeta(P);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	inputdata(&kita);
	inputdata(&musuh);

	HP(kita) = 50;
	HP(musuh) = 25;
	
	system("clear");

	makestack(&stenemy);

	//Pop(&stenemy,&q);

	//PrintQueue(q);
	
	BattleOn(&kita,musuh,stenemy);
}

void inputdata(player *pl){
	// I.S : BattleOn dipanggil, bersiap memulai battle
	// F.S : Status pl diinisialisasi sebelum memulai battle
	
	printf("NAME : ");
	scanf("%s",NAME(*pl));
	printf("ATK : ");
	scanf("%ld",&ATK(*pl));
	printf("DEF : ");
	scanf("%ld",&DEF(*pl));
	printf("LVL : ");
	scanf("%d",&LVL(*pl));
}

void makestack(Stack *st){
	// I.S : inputdata telah dipanggil
	// F.S : Stack aksi musuh diinisialisasi sebelum meulai battle
	
	int i,r,z;
	Queue temp;

    z = 1;
    while(z <= 10){
    	CreateEmptyQueue(&temp);
		for (int i = 1; i <= 4; i++)
		{
			srand(time(NULL));
    		r = rand() % 3;

			if(r == 0){
				Add(&temp,'A');	
			}else if(r == 1){
				Add(&temp,'F');
			}else if(r == 2){
				Add(&temp,'B');
			}
		}
		Push(st,temp);
		z++;
    }


}