/* Nama 		: Martin Lutta Putra */
/* NIM 			: 13515121 */
/* Tanggal 		: 13 November 2016 */
/* Deskripsi	: ADT TUBES YEYEYE */

#include "bintree.h"
#include <stdio.h>

int main() {
	infotype e;
	addrNode root, left, right;
	
	MakeTree(1, Nil, Nil, &root);
	Left(root) = Tree(2, Nil, Nil);
	Right(root) = Tree(3, Nil, Nil);
	Right(Right(root)) = Tree(4, Nil, Nil);
	Left(Right(root)) = Tree(5, Nil, Nil);
	PrintTree(root,2);
	printf("\n%d %d\n", NbElmt(root));
	return 0;
}