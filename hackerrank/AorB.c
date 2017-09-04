#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int selected(char A, unsigned place){
	switch (place){
		case 0: return A=='1'|| A=='3'|| A=='5'|| A=='7'|| A=='9'|| A=='B'|| A=='D'|| A=='F';
		case 1: return A=='2'|| A=='3'|| A=='6'|| A=='7'|| A=='A'|| A=='B'|| A=='E'|| A=='F';
		case 2: return A=='4'|| A=='5'|| A=='6'|| A=='7'|| A=='C'|| A=='D'|| A=='E'|| A=='F';
		case 3: return A=='8'|| A=='9'|| A=='A'|| A=='B'|| A=='C'|| A=='D'|| A=='E'|| A=='F';
		default: return 0;
	}
}

char nextChar(char A, unsigned times){
	if(times==0)return A;
	if(A=='F')return 'F';
	if(A=='9')return nextChar('A',times-1);
	else return nextChar(A+1,times-1);
}

char prevChar(char A, unsigned times){
	if(times==0)return A;
	if(A=='0')return '0';
	if(A=='A')return prevChar('9',times-1);
	else return prevChar(A-1,times-1);
}

char selectPlace(char A, unsigned place){
	if (selected(A, place)) return A;
	switch (place){
		case 0: return nextChar(A,1);
		case 1: return nextChar(A,2);
		case 2: return nextChar(A,4);
		case 3: return nextChar(A,8);
		default: return 0;
	}
}

char unselectPlace(char A, unsigned place){
	if (!selected(A, place)) return A;
	switch (place){
		case 0: return prevChar(A,1);
		case 1: return prevChar(A,2);
		case 2: return prevChar(A,4);
		case 3: return prevChar(A,8);
		default: return 0;
	}
}

void printWithOutLeads(char A[]){
	int i;
	for(i=0; i<50000; i++){
		if(A[i]!='0')
			break;
	}
	if(i==50000)
		printf("0");
	else{
		for(;i<50000; i++){
		printf("%c",A[i]);
	}
	}
	
	printf("\n");
}

void convert(char A[],char B[],char C[],int k){
	int i=0;
	for(i=0; i<50000; i++){
		if(k<0) break;
		int j;
		for(j=3; j>=0; j--){
			if(selected(A[i],j) && !selected(C[i],j)){
				k--;
				A[i]=unselectPlace(A[i],j);
			}
			if(selected(B[i],j) && !selected(C[i],j)){
				k--;
				B[i]=unselectPlace(B[i],j);
			}
			if(!selected(A[i],j) && !selected(B[i],j) && selected(C[i],j)){
				k--;
				B[i]=selectPlace(B[i],j);
			}
		}

	}
	for(int i=0; i<50000; i++){
		if(k==0) break;
		int j;
		for(j=3; j>=0; j--){
			if(k>=2 && selected(A[i],j) && !selected(B[i],j)){
				k-=2;
				A[i]=unselectPlace(A[i],j);
				B[i]=selectPlace(B[i],j);
			}
			if(k>=1 && selected(A[i],j) && selected(B[i],j)){
				k--;
				A[i]=unselectPlace(A[i],j);
			}
		}
	}
	
	if(k<0)
		printf("-1\n");
	else {
		printWithOutLeads(A);
		printWithOutLeads(B);
	}
}

char* zeroExtend(char a[]){
	int i;

	unsigned msize=strlen(a);

	for(i=0; i<=msize; i++){
		a[50000-i]=a[msize-i];
	}
	int unused=50000-msize;
	for(i=0; i<unused; i++){
		a[i]='0';
	}

	return a;


}


int main(){
	int trials;
	scanf("%d",&trials);
	int i;
	for(int i=0; i<trials; i++){
		int k;
		scanf("%d",&k);
		char* a=(char*)malloc(50001*sizeof(char));
		char* b=(char*)malloc(50001*sizeof(char));
		char* c=(char*)malloc(50001*sizeof(char));
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", c);
		convert(zeroExtend(a),zeroExtend(b),zeroExtend(c),k);
		free(a);
		free(b);
		free(c);
	}
}