
#include <iostream>

using namespace std;


int main(){
    int x1;
    int v1;
    int x2;
    int v2;
    cin >> x1 >> v1 >> x2 >> v2;
    bool meet=true;
    if(x1>x2) meet= ( v2>v1 && (x1-x2)%(v2-v1)==0);
    else if(x1<x2)meet=(v2<v1 && (x2-x1)%(v1-v2)==0);
    
    cout<<(meet?"YES":"NO");
    return 0;
}