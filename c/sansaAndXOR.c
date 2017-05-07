#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    unsigned testCases;
    scanf("%u", &testCases);
    while(testCases){
        unsigned nums;
        scanf("%u", &nums);
        unsigned long result=0;
        unsigned long total=0;
        unsigned long size=nums/2;
        unsigned long numIndex=0;
        while (numIndex<size){
            unsigned long num;
            scanf("%lu", &num);
            total^=num;
            scanf("%lu", &num);
            numIndex++;
            
        }
        if(nums%2){
            unsigned long num;
            scanf("%lu", &num);
            total^=num;
            result=total;
        }
        printf("%lu\n",result);
        testCases--;
    }
    return 0;
}
