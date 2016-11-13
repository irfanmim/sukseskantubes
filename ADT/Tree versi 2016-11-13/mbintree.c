/* Nama 		: Martin Lutta Putra */
/* NIM 			: 13515121 */
/* Tanggal 		: 13 November 2016 */
/* Deskripsi	: ADT TUBES YEYEYE */

#include "bintree.h"
#include <stdio.h>

int main() {
	infotype e;
	address root, left, right;
	
	
	MakeTree(1, Nil, Nil, &left);
	MakeTree(2, Nil, Nil, &right);
	MakeTree(3, left, right, &root);
	PrintPreOrder(root);
	printf("%d\n", NbDaun(root));
	
	printf("Left Right Biner : %d %d %d\n", IsUnerLeft(root), IsUnerRight(root), IsBiner(root));
	return 0;
}