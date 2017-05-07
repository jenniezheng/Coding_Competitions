#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long n; 
    scanf("%ld",&n);
    long res=1;
    while(n){
        if(!(n&1))
            res<<=1;
        n>>=1;
    }
    printf("%ld",res);
    return 0;
}