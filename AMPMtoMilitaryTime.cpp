#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string time;
    cin >> time;
    const string beg=time.substr(0,2);
    const string mid=time.substr(2,6);
    const string end=time.substr(8,2);

    if(beg=="12"){
        if(end=="AM") cout<<"00"<<mid;
        else  cout<<"12"<<mid;
    }
    else if(end=="AM")cout<<beg<<mid;
    else { int hour=stoi(beg);
          hour+=12;
          cout<<hour<<mid;
    }
    return 0;
}
