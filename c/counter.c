#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int testCases;
	scanf("%d",&testCases);
	int i;
	for(int i=0; i<testCases;i++){
		unsigned long long num; 
		scanf("%llu",&num);
		int count=0;
		while(num>1){
			if((num & (num-1)) == 0)num>>=1;
			else {
				unsigned long long number=num;
				number |= number >> 1;
				number |= number >> 2;
				number |= number >> 4;
				number |= number >> 8;
				number |= number >> 16;
				number |= number >> 32;
				num-= (number >> 1) + 1;
			}
			count++;
		}
		if(count%2==1)
			printf("Louise\n");
		else printf("Richard\n");
	}
	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
