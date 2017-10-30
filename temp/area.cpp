#include <bits/stdc++.h>
using namespace std;


double area_of_triangle(double x1,double y1, double x2, double y2){
    //assume x0 y0 at origin
    return abs(x1*y2-y1*x2)/2;
}

int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt", "r", stdin);
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    int num_verticles, xstart,ystart, xprev, yprev;
    scanf("%d %d %d %d %d",&num_verticles,&xstart,&ystart,&xprev,&yprev);
    double total=0;
    for (int i=0; i<num_verticles-2; i++){
        int xnext,ynext;
        scanf("%d %d",&xnext,&ynext);
        double area_of_piece=area_of_triangle(
            xnext-xstart,ynext-ystart,
            xprev-xstart,yprev-ystart);
        total+=area_of_piece;
        xprev=xnext;
        yprev=ynext;
    }
    printf("%f\n",total);

}