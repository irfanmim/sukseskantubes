#include "soqlist.h"

int main () {
    int X,i;
    char C;
    Queue qc,temp;
    Stack sq;
    CreateEmpty(&sq);

    scanf(" %c",&C);

while(C != 'F'){
    if (C == 'A'){
        CreateEmptyQueue(&qc);
        scanf(" %c",&C);
        while(C != '.'){
            Add(&qc,C);
            scanf(" %c",&C);
        }
        Push(&sq,qc);
        PrintQueue(qc);
    } else if(C == 'P') {
        CreateEmptyQueue(&temp);
        if(!IsEmpty(sq)){
            Pop(&sq,&temp);
        }else {
            printf("kosong\n");
        }
        PrintQueue(temp);
    }else if (C=='O'){
        str kata;
        scanf("%s",kata);
        FILE *pita;
        BacaFile(&sq,pita,kata);
    }
    scanf(" %c",&C);
}
    return 0;
}
