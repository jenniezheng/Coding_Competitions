
#include <iostream>
using namespace std;



int main() {
long cowbells, boxes;
cin>>cowbells>>boxes;
long* sizes= new long[cowbells];
for(long i=0; i<cowbells;i++)
    cin>>sizes[i];

long maxBellSize=sizes[0]; long long totalSizes=0;
for(long i=0; i<cowbells;i++)
    {
        if(sizes[i]>maxBellSize)maxBellSize=sizes[i];
        totalSizes+=sizes[i];
    }

long minBoxSize;
if(maxBellSize>totalSizes/boxes) minBoxSize=maxBellSize;
else minBoxSize=long(totalSizes/boxes);

for (long currentBoxSize=minBoxSize;;currentBoxSize++){
    long start=0, endd=cowbells-1, currentBoxes=0;
    bool bigEnough=true;
    while(start<=endd){
        if (start==endd) {currentBoxes++;start++;}
        else if(sizes[start]+sizes[endd]<=currentBoxSize) {
                //cout<<"boxes fit together! "<<start<<" "<<endd<<endl;
                currentBoxes++; start++; endd--;}
        else {currentBoxes++;endd--;}
        if(currentBoxes>boxes){
            //cout<<"breaking for size "<<currentBoxSize<<endl;
            //cout<<currentBoxes<<" vs "<<boxes<<endl;
            bigEnough=false;
                break;}
        }
        if (bigEnough==true) {cout<<currentBoxSize<<endl; break;}
}
return 0;
}