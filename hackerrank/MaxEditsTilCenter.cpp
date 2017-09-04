#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
string a;
getline(cin,a);

if(a.size()%2==1) {cout<<-1; return 0;}

int up=0, right=0;
for(int i=0; i<a.size();i++){
    if(a[i]=='U')up++;
    else if(a[i]=='D')up--;
    else if(a[i]=='L')right--;
    else if(a[i]=='R')right++;
}


cout<<(abs(up)+abs(right))/2;

}