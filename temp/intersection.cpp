#include <bits/stdc++.h>
using namespace std;


int main(){
    // faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("test.txt", "r", stdin);
    int a,b,c,j,k,l;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&j,&k,&l);
    double x= double(c*k-b*l) / (b*j-a*k);
    double y= double(a*l-c*j) / (b*j-a*k);

    cout.precision(10);
    cout << fixed << x << " " << y << endl;
}