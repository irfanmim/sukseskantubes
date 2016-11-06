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
        Pop(&sq,&temp);
        PrintQueue(temp);
    }
    scanf(" %c",&C);
}
    return 0;
}
