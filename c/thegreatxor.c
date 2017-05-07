#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

unsigned long theGreatXor(long x){
    long index=0;
    long total=0;
    while(x){
        if(!(x&1))
            total+=((long)1<<index);
        index++;
        x>>=1;
    }
    return total;
}

int main() {
    int q; 
    scanf("%d", &q);
    for(int a0 = 0; a0 < q; a0++){
        long x; 
        scanf("%ld", &x);
        long result = theGreatXor(x);
        printf("%ld\n", result);
    }
    return 0;
}
