#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
   int d1=0, d2=0;
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          int x; 
           cin>>x;
           if (a_i==a_j) d1+=x;
           if(a_i==n-1-a_j)d2+=x;
       }
    }
    int diff=d1-d2;
    cout<< ((diff>0)?diff:-diff);
    
    return 0;
}