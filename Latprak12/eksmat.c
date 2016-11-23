#include "listrek.h"
#include "boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void BuildTreeFromString (BinTree *T, char st[200], int *idx);

int strtoint(char s);

void PrintPostfix (BinTree P);

int hitungtree(BinTree T);

int hitung(int a, int b, int s);

char inttochar(int s);

boolean inputvalid(char c);

int main (){
	
	BinTree T;
	char S[200],c;
	int idx = 0;
	int hasil,i,temp;
	boolean valid;
	/* ALGORITMA */
	/*
	i = 0;
	scanf("%c",&c);
	valid = inputvalid(c);
	while(valid){
		S[i] = c;
		i++;
		scanf("%c",&c);	
		valid = inputvalid(c);
	}*/

	//scanf("%s",S);
	fgets(S,sizeof(S),stdin);

	i = strlen(S);

	/*
	if(i == 1 && S[0] != '\n'){
		temp = S[0] - '0';
	}*/

	if (i - 1 == 0 && !inputvalid(S[0])){
		printf("Ekspresi kosong\n");
	}else{
		//printf("%c\n",S );
		BuildTreeFromString(&T,S,&idx);
		//PrintTree(T,2); 
		//printf("\i > 0
		PrintPostfix(T);
		printf("\n");				
		hasil = hitungtree(T);
		printf("=%d\n",hasil);
	}/*else{
		printf("Ekspresi kosong\n");
	}*/
	
	return 0;
	
	//return 0;
}

void BuildTreeFromString (BinTree *T, char st[200], int *idx){
	
	//(*idx)++;  
	
	int temp = strtoint(st[*idx]);
	                        		/* advance */	
	if (temp >=0 && temp <=9){  						/* Basis : pohon kosong */
		*T = AlokNode(temp);
		(*idx)++; 
	}else {
				
		*T = AlokNode(temp);
		(*idx)++;                         		/* advance */
		BuildTreeFromString(&Left(*T),st,idx);
		BuildTreeFromString(&Right(*T),st,idx);
		
	}
	
	//(*idx)++;                          	 	/* advance */
}

int strtoint(char s){
	int temp;
	if(s =='-'){
		temp = -1;
	}else if (s == '+'){
		temp = -2;
	}else if (s == '*'){
		temp = -3;
	}else if (s == '/'){
		temp = -4;
	}else if (s == '^'){
		temp = -5;
	}else if (s == '%'){
		temp = -6;
	}else{		
		temp = 	s -'0';								/* Rekurens */
	}
	return temp;
}

char inttochar(int s){
	int temp;
	if(s ==  -1){
		temp = '-';
	}else if (s == -2){
		temp = '+';
	}else if (s == -3){
		temp = '*';
	}else if (s == -4){
		temp = '/';
	}else if (s == -5){
		temp = '^';
	}else if (s == -6){
		temp = '%';
	}else{		
		temp = 	s +'0';								/* Rekurens */
	}
	return temp;
}

void PrintPostfix (BinTree P){
  if (IsTreeEmpty(P)){
    //printf("()");
  }else{
    //printf("(");
    PrintPostfix(Left(P));
    PrintPostfix(Right(P));
    char temp = inttochar(Akar(P));
    printf("%c",temp);
  }
}

int hitungtree(BinTree T){
	
	if(Akar(T) >= 0){
		return Akar(T);
	}else{
		return hitung(hitungtree(Left(T)),hitungtree(Right(T)),Akar(T));
	}
	
}

int hitung(int a, int b, int s){
	int temp;
	if(s ==  -1){
		temp = a - b;
	}else if (s == -2){
		temp = a + b;
	}else if (s == -3){
		temp = a * b;
	}else if (s == -4){
		temp = a / b;
	}else if (s == -5){
		temp = pow(a,b);
	}else if (s == -6){
		temp = a % b;
	}
	return temp;
}

boolean inputvalid(char c){
	if(c == '-'){
		return true;
	}else if(c == '+'){
		return true;
	}else if(c == '/'){
		return true;
	}else if(c == '^'){
		return true;
	}else if(c == '*'){
		return true;
	}else if(c == '%'){
		return true;
	}else if(c -'0' >= 0 && c - '0' <= 9){
		return true;
	}else{
		return false;
	}
}