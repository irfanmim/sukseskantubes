#include "listrek.h"
#include "boolean.h"
#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

int main (){
	int x,y,z;
	BinTree pohon;
	boolean kiri;

	List listdaun,lslvl,listpre;

	printf("Akar : ");
	scanf("%d",&x);
	MakeTree(x,Nil,Nil,&pohon);

	printf("Opsi : ");
	scanf("%d",&x);

	while(x != -9999){
		if(x == 1){
			printf("AddDaunTerkiri : ");
			scanf("%d",&x);
			AddDaunTerkiri(&pohon,x);
		}else if(x == 2){
			printf("AddDaun : ");
			scanf("%d",&x);
			printf("Dibawah : ");
			scanf("%d",&y);
			printf("kanan(1) / kiri (other) : ");
			scanf("%d",&z);
			if (z == 1){
				kiri = false;
			}else{
				kiri = true;
			}
			AddDaun(&pohon,y,x,kiri);
		}else if(x == 3){
			printf("DelDaunterkiri : ");
			DelDaunTerkiri(&pohon,&y);
			printf("%d\n",y);
		}else if(x == 4){
			printf("DelDaun : ");
			scanf("%d",&x);
			DelDaun(&pohon,x);			
		}else if(x == 5){
			printf("List daun\n");
			listdaun = MakeListDaun(pohon);
			PrintList(listdaun);
		}else if(x == 6){
			printf("List level\n");
			scanf("%d",&x);
			lslvl = MakeListLevel(pohon,x);
			PrintList(lslvl);
		}else if(x == 7){
			printf("identasi : ");
			scanf("%d",&x);
            PrintTree(pohon,x);
		}else if(x == 8){
			PrintPostorder(pohon);
			printf("\n");		
		}else if(x == 9){
			PrintInorder(pohon);
			printf("\n");		
		}else if(x == 0){
			PrintPreorder(pohon);
			printf("\n");
		}else if(x == 10){
			printf("List Preorder\n");
			lslvl = MakeListPreorder(pohon);
			PrintList(lslvl);
		}
		scanf("%d",&x);	
	}

	return 0;
}
