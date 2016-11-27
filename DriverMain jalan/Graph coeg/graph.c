
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listlinier.h"
#include "graph.h"
#include "matriks.h"

void SetVertex(Graph *G, Node V){
    NbNode(*G) = V;
}
/* Mengganti jumlah simpul dari graf G dengan V*/
void SetEdge(Graph *G, Edge E){
    NbEdge(*G) = E;
}
/* Mengganti jumlah sisi dari graf G dengan E*/
Graph CreateGraph(Node V){
    Graph G;
    SetVertex(&G,V);
    SetEdge(&G,0);
    MakeMATRIKS(V,V,&Adj(G));
    return G;
}
/* Menghasilkan sebuah graf kosong dengan jumlah simpul V. Graf kosong
adalah graf dengan sisi 0 dalam representasi matriks ketetanggaan
dengan jumlah baris efektif V dan jumlah kolom efektif V*/
boolean IsGraphEmpty(Graph G){
    return (NbEdge(G) == 0);
}
/* Megembalikan true apabila graf kosong, sisi graf = 0*/
boolean Adjacent(Graph G, Node V, Node V2){
    return (Elmt(Adj(G),V,V2) == '1');
}
/* Mengembalikan true jika simpul V1 dan V2 pada graf G bertetangga,
yaitu apabila elemen ke [V1][V2] pada graf G bernilai 1*/
ListOfNodes Neighbors(Graph G, Node V){
    int i = NbNode(G);
    ListOfNodes temp;
    while (i != 0){
        if (Elmt(Adj(G),V,i) == '1'){
            InsVLast(&temp,i);
        }
        i--;
    }
}
/* Mengembalikan sebuah list of nodes yang berisi daftar simpul-simpul
yang bertetangga dengan simpul V*/
void AddV(Graph *G, Node V){
    NBrsEff(Adj(*G))++;
    NKolEff(Adj(*G))++;
    int i;
    for(i=1;i<=NBrsEff(Adj(*G));i++){
        Elmt(Adj(*G),NBrsEff(Adj(*G)),i) = '0';
        Elmt(Adj(*G),i,NKolEff(Adj(*G))) = '0';
    }
    NbNode(*G) = V;
}
/* Menambahkan simpul V kedalam G, dengan menambahkan NbrsEff dan NkolEff
dengan 1*/
void AddE(Graph *G, Node V1, Node V2){
    Elmt(Adj(*G),V1,V2) = '1';
    Elmt(Adj(*G),V2,V1) = '1';
}
/* Menambahkan sebuah sisi diantara simpul V1 dan V2*/
void DelE(Graph *G, Node V1, Node V2){
    Elmt(Adj(*G),V1,V2) = '0';
    Elmt(Adj(*G),V2,V1) = '0';
}
/* Menghapus sisi diantara simpul V1 dan V2*/
void DelV(Graph *G, Node V){
    int i,j;
    for(j=1;j<=NKolEff(Adj(*G));j++){
        for(i=1;i<=NBrsEff(Adj(*G));i++){
            Elmt(Adj(*G),i,j) = Elmt(Adj(*G),i+1,j);
        }
    }
    for(i=1;i<=NKolEff(Adj(*G));i++){
        for(j=1;j<=NBrsEff(Adj(*G));j++){
            Elmt(Adj(*G),i,j) = Elmt(Adj(*G),i,j+1);
        }
    }
    NBrsEff(Adj(*G))--;
    NKolEff(Adj(*G))--;
    SetVertex(G,NbNode(*G)-1);
}
/* Menghapus simpul V. Kolom ke-V dan baris ke-V dihapus dari kolom.
Menggeser seluruh elemen di setiap kolom ke-V dengan elemen sesudahnya
sampai NKolEff dan setiap bari ke-V dengan elemen sesudahnya sampai NBrsEff*/




