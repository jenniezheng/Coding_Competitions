#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num;
    cin>>num;
    vector<int> v;
    //store nums in vector

    for(int i=0; i<num; i++)
    {int a; 
     cin>>a;
     v.push_back(a);}
    
    //sort vector
    sort(v.begin(),v.end());
    //define variables for mode and med finding
    int mode=*v.begin();
    int maxInRow=0;
    int currentInRow=0;
    int previous=*v.begin();
    int total=*v.begin();
    for(vector<int>::iterator it=v.begin()+1; it!=v.end(); it++){
        total+=*it;
        if(previous==*it)currentInRow++;
        else{
            if(currentInRow>maxInRow){
                maxInRow=currentInRow;                                                 mode=previous;}
            currentInRow=0;
             previous=*it; }
    }
    if(currentInRow>maxInRow) mode=previous;
    double mean=(double)total/v.size();
    double median=*(v.begin()+v.size()/2);
    if(v.size()%2==0) median=((double)median)/2+((double)(*(v.begin()+v.size()/2-1)))/2;
    
    cout<<mean<<endl<<median<<endl<<mode<<endl;

    return 0;
}
