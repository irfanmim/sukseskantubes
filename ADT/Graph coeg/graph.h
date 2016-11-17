#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "boolean.h"
#include "listlinier.h"
#include "matriks.h"

#define Nil NULL

typedef int Node;
typedef int Edge;
typedef Node NbNode;
typedef Edge NbEdge;
typedef struct{
    NbNode V;
    NbEdge E;
    MATRIKS adj;
} Graph;

typedef List ListOfNodes;

#define NbNode(G) (G).V
#define NbEdge(G) (G).E
#define Adj(G) (G).adj

void SetVertex(Graph *G, Node V);
/* Mengganti jumlah simpul dari graf G dengan V*/
void SetEdge(Graph *G, Edge E);
/* Mengganti jumlah sisi dari graf G dengan E*/
Graph CreateGraph(Node V);
/* Menghasilkan sebuah graf kosong dengan simpul v. Graf kosong
adalah graf dengan sisi 0 dalam representasi matriks ketetanggaan
dengan jumlah baris efektif V dan jumlah kolom efektif boolean IsEmpty(Graph G);
/* Megembalikan true apabila graf kosong, sisi graf = 0*/
boolean IsGraphEmpty(Graph G);
/* Megembalikan true apabila graf kosong, sisi graf = 0*/
boolean Adjacent(Graph G, Node V, Node V2);
/* Mengembalikan true jika simpul V1 dan V2 pada graf G bertetangga,
yaitu apabila elemen ke [V1][V2] pada graf G bernilai 1*/
boolean Incident(Graph G, Node V, Edge E);
/* Mengembalikan true jika simpul V berhubungan dengan sisi E*/
ListOfNodes Neighbors(Graph G, Node V);
/* Mengembalikan sebuah list of nodes yang berisi daftar simpul-simpul
yang bertetangga dengan simpul V*/
void AddV(Graph *G, Node V);
/* Menambahkan simpul V kedalam G, dengan menambahkan NbrsEff dan NkolEff
dengan 1*/
void AddE(Graph *G, Node V1, Node V2);
/* Menambahkan sebuah sisi diantara simpul V1 dan V2*/
void DelE(Graph *G, Node V1, Node V2);
/* Menghapus sisi diantara simpul V1 dan V2*/
void DelV(Graph *G, Node V);
/* Menghapus simpul V. Kolom ke-V dan baris ke-V dihapus dari kolom.
Menggeser seluruh elemen di setiap kolom ke-V dengan elemen sesudahnya
sampai NKolEff dan setiap bari ke-V dengan elemen sesudahnya sampai NBrsEff*/

#endif // _GRAPH_H_



