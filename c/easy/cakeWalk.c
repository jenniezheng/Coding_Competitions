#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int main(){
	
	int sizeA;
	scanf("%d",&sizeA);
	int* arrA=malloc(sizeof(int)*sizeA);
	int i;
	for(i=0; i<sizeA; i++){
		int ele;
		scanf("%d",&ele);
		arrA[i]=ele;
	}
	int sizeB;
	scanf("%d",&sizeB);
	int* arrB=malloc(sizeof(int)*sizeB);
	for(i=0; i<sizeB; i++){
		int ele;
		scanf("%d",&ele);
		arrB[i]=ele;
	}

	qsort(arrA, sizeA, sizeof(int), cmpfunc);
	qsort(arrB, sizeB, sizeof(int), cmpfunc);

	int* arrC=malloc(sizeof(int)*(sizeB-sizeA));

	int ptrA=0, ptrB=0;
	while(ptrA<sizeA && ptrB<sizeB){
		if (arrA[ptrA]==arrB[ptrB]){
			ptrA++;ptrB++;
	  	}
	  	else{
	  		printf("%d ",arrB[ptrB]);
	  		ptrB++;
	  		while(ptrB<sizeB && arrB[ptrB]==arrB[ptrB-1])
	  			ptrB++;
	  	}
	}
	
}