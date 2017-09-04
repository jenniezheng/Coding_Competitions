#include <iostream>

using namespace std;


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    

    
    //find amount of A in the full strings
    long numA=0;    
    for(int i=0; i<s.size(); i++)
        if(s[i]=='a')numA++;
    numA*=n/s.size();
    
    //find amount of A remaining
     int remainder=0;
    for(int i=0; i<n%s.size(); i++)
        if(s[i]=='a')remainder++;
     
    cout<<numA+remainder;
    return 0;
    
}