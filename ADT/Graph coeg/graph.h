#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

typedef int infotype;

typedef tNode address;
typedef tEdge address;
typedef tBusur address;

typedef struct tNode {
    infotype infonode;
    address next;
    ListOfEdge busur;
} Node;

typedef struct tEdge {
    infotype infoedge;
    address next;
    address node1;
    address node2;
} Edge;

typedef struct tBusur {
    address infobusur;
    address next;
} Busur;

typedef {
    address first;
} ListOfEdge;

typedef {
    address first;
} ListOfNode;

typedef {
    address first;
} ListOfBusur;

typedef {
    ListOfNode ListNode;
    ListOfEdge ListEdge;
} Graph;

#define Next(P) (P)->next
#define First(L) ((L).first)

#define Infoedge(P) (P)->infoedge
#define Node1(P) (P) ->node1
#define Node2(P) (P) ->node2

#define Infonode(P) (P)->infonode
#define Busur(P) (P)->busur
#define Infobusur(P) (P)->infobusur

Graph CreateGraph (ListOfNode V, ListOfEdge E);

boolean IsEmpty (Graph G);

Graph AddE (Graph G, infotype info, address V1, address V2);

void AddEdge1 (Graph *G, Node V1, Node V2);

Graph AddEdge2 (Graph G, Node V1, Node V2);

Graph DeleteE(Graph G, Node V1, Node V2);

boolean IsAdjacent (Graph G, Node V1, Node V2);

boolean IsIncident (Graph G, Node V, Edge E);

ListOfNode Neighbours (Graph G, Node V);

Graph AddV (Graph G, infotype V);

Graph DelV (Graph G, Node V);
