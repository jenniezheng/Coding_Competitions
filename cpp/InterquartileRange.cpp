
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
//,
void create( vector<pair<int, int>>& v, int* size){
int n;
cin>>n;
vector<int> element(n);

for(int i=0; i<n; i++){
    int e;
    cin>>e;
    element[i]=e;
}

for(int i=0; i<n; i++){
    int f;
    cin>>f;
    *size+=f;
    v.push_back( pair<int,int>(element[i], f));
}
sort(v.begin(),v.end());

}

int findElement(int index, vector<pair<int, int>>& v){
int totalIndex=0;
    for(pair<int,int>const &p: v){
        totalIndex+=p.second;
        if (totalIndex>index)return p.first;//return if frequency is large enough
    }
return -1;
}

double findMedian(int start, int end, vector<pair<int,int>> v){//start inclusive, end exclusive
if((end-start)%2==1)return findElement((start+end)/2, v);
else return (findElement((start+end)/2-1,v)+findElement((start+end)/2,v))/2.0;
}


int main(){
vector<pair<int, int>> v;
int size=0;
create(v,&size);
double firstQuartile=findMedian(0, size/2, v);
double thirdQuartile;
if(size%2==1) thirdQuartile=findMedian(size/2+1,size,v);
else thirdQuartile=findMedian(size/2,size,v);

cout<<fixed<<setprecision(1)<<thirdQuartile-firstQuartile;
}