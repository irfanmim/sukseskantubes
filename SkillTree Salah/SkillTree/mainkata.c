#include "boolean.h"
#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
int main() {
	int i;
STARTKATA();
while (!EndKata) {
for (i=1;i<=CKata.Length;i++) {
printf("%c",CKata.TabKata[i]);
}
printf("\n");
ADVKATA();
}
return 0;
}