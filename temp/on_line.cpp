#include <bits/stdc++.h>
using namespace std;


int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt", "r", stdin);
    freopen("point.in", "r", stdin);
    freopen("point.out", "w", stdout);
    int xp,yp,x1,y1,x2,y2;
    scanf("%d %d %d %d %d %d",&xp,&yp,&x1,&y1,&x2,&y2);
    bool on_line;
    if(xp > x1 && xp > x2  ||
    xp < x1 && xp < x2 ||
    yp > y1 && yp > y2 ||
    yp < y1 && yp < y2)
        on_line=false;
    else if(xp == x1 && yp == y1  ||
    xp == x2 && yp == y2)
        on_line=true;
    else{
        double rangex1=xp-x1;
        double rangex2=x2-x1;
        double rangey1=yp-y1;
        double rangey2=y2-y1;
        if(rangex1==0)
            on_line=(rangex2==0);
        else if(rangey1==0)
            on_line=(rangey2==0);
        else{
            double eps=.000000001;
            on_line=(rangex1/rangex2-rangey1/rangey2 < eps
                && rangex1/rangex2-rangey1/rangey2 > -eps);
        }
    }
    if(on_line)
        printf("YES\n");
    else
        printf("NO\n");

}