
 #include <iostream>
#include <string>
using namespace std;



int main(){
//best case first of his length
//worst case last of his length
//after each, add 1 sec
//after k, add 5 sec
int num, tries;
cin>>num>>tries;
string* arr=new string[num];
for(int i=0; i<num;i++)
    cin>>arr[i];
string pass;
cin>>pass;
int numShorter=0, numSameSize=0, numPasses=0;
for(int i=0;i<num;i++){
    if(arr[i].size()<pass.size())numShorter++;
    else if (arr[i].size()==pass.size()){numSameSize++;
    if(arr[i]==pass)numPasses++;}
}

int minTime=numShorter+5*(numShorter/tries)+1;
int maxTime=(numShorter+numSameSize-numPasses)+ 5*((numShorter+numSameSize-numPasses)/tries) +1;
cout<<minTime<<" "<<maxTime;

return 0;
}