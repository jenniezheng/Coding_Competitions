#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int res=0;
    int shiftsCurrently=0;
    while(l!=0 && r!=0){
        if(l<r)  
            res+=(1<<shiftsCurrently);
        shiftsCurrently++; 
        l>>=1;
        r>>=1;
    }
    return res;

}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
