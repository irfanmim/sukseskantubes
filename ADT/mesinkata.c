/* Definisi Mesin Kata: Model Akuisisi Versi I		*/
/* NIM/Nama		: 13515139 / Jehian Norman Saviero	*/
/* Tanggal		: 2016-09-22						*/
/* Nama File	: mesinkata.c						*/ 

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{ 	/* Kamus Lokal */
	/* Algoritma */
	while ((CC == BLANK) && (CC != MARK))
	{
		ADV();
	} /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{	/* Kamus Lokal */
	/* Algoritma */
	START();
	IgnoreBlank();
	if (CC==MARK)
	{
		EndKata = true;
	}
	else
	{
		EndKata = false;
		SalinKata();
	}
	IgnoreBlank();
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{	/* Kamus Lokal */
	/* Algoritma */
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		SalinKata();
	}
	IgnoreBlank();
}
	
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{	/* Kamus Lokal */
	int i = 1;
	/* Algoritma */
	for (;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC==MARK) || (CC==BLANK) || (i>=NMax))
		{
			break;
		}
		else
		{
			++i;
		}
	}
	CKata.Length = i;
}
