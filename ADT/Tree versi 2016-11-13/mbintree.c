/* Nama 		: Martin Lutta Putra */
/* NIM 			: 13515121 */
/* Tanggal 		: 13 November 2016 */
/* Deskripsi	: ADT TUBES YEYEYE */

#include "bintree.h"
#include <stdio.h>

int main() {
	infotype e;
	address root, left, right;
	
	MakeTree(1, Nil, Nil, &root);
	AddLMLeaf(&root, 2);
	AddLMLeaf(&root, 2);
	AddLMLeaf(&root, 2);
	PrintPreOrder(root);	
	printf("%d\n", NbDaun(root));
	
	printf("\n");
	while(!IsTreeEmpty(root)) {
		(DelLMLeaf(&root, &e));
		printf("%d\n", e);
	}
	
	printf("Left Right Biner : %d %d %d\n", IsUnerLeft(root), IsUnerRight(root), IsBiner(root));
	return 0;
}