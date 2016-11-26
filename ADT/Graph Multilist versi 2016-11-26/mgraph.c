#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Graph G;
	infotype X = 1, prec, succ;
	adrNode Pn;
	CreateGraph(X, &G);
	++X;
	int T, temp;
	do
	{
		scanf("%d", &T);
		if (T == 0)
		{
			InsertNode(&G, X, &Pn);
			++X;
		}
		else if (T == 1)
		{
			printf("Titik apa yang kamu cari?: "); scanf("%d", &temp);
			if (SearchNode(G, temp) != Nil)
			{
				printf("Sans, titik yang kamu cari ada kok, hehe\n");
			}
			else
			{
				printf("Wadaw, titiknya gak ada bro!\n");
			}
		}
		else if (T == 2)
		{
			printf("Sisi apa yang kamu cari mas?:\n");
			printf("dari (prec): ");scanf("%d", &prec);
			printf("ke (succ): ");scanf("%d", &succ);
			if (SearchEdge(G, prec, succ) != Nil)
			{
				printf("Ada bro sisinya! ^^\n");
			}
			else
			{
				printf("Sorry, I can't find that edge :') huhu\n");
			}
		}
		else if (T == 3)
		{
			printf("Mau nambahin sisi dari mana ke mana nih?: ");
			printf("dari (prec): ");scanf("%d", &prec);
			printf("ke (succ): ");scanf("%d", &succ);
			if (SearchEdge(G, prec, succ) != Nil)
			{
				printf("Sudah ditambahkan mzz... ._.\n");
			}
			else
			{
				InsertEdge(&G, prec, succ);
				printf("Edge has been added!\n");
			}
		}
		else if (T == 4)
		{
			printf("Mau delete Node? Jangan delete node aku ya, nanti dari aku ke kamu harus kemana :'): \n");
			printf("Masukkan node yang ingin di delete: \n"); scanf("%d", &temp);
			if (SearchNode(G, temp) == Nil)
			{
				printf("Gomennasai~~ Node-nya gak ada di Graph sayangku :*\n");
			}
			else
			{
				DeleteNode(&G, temp);
				printf("Sudah dihapus ya!!\n");
			}
		}
		else if (T == 5)
		{
			printf("Mau pergi dari mana ke mana?: \n");
			printf("dari (from): "); scanf("%d", &prec);
			printf("ke (to): "); scanf("%d", &succ);
			if (IsPathExist(G, prec, succ))
			{
				printf("Selamat, kamu dapat sampai ke tujuan!!!\n");
			}
			else
			{
				printf("Maaf, perjalananan kita tidak dapat dilanjutkan :(\n");
			}
		}
		else
		{
			printf("Masukkan salah!\n");
		}

	} while (T < 10000);
	return 0;
}
