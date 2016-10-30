#include <iostream>
#include <vector>
using namespace std;



int main(){
int num;
cin>>num;
char* arr=new char[num];
for(int i=0;i<num;i++)
    cin>>arr[i];
//
int needBlack1=0;
int needRed1=0;
for(int i=0;i<num;i++){
    //RBRBR possibility
    if(i%2==0&&arr[i]=='b')needBlack1++;
    else if(i%2==1&&arr[i]=='r')needRed1++;
}
int total1;
if(needBlack1>needRed1)total1=needBlack1;
else total1=needRed1;
//

int needBlack2=0;
int needRed2=0;
for(int i=0;i<num;i++){
    //RBRBR possibility
    if(i%2==0&&arr[i]=='r')needBlack2++;
    else if(i%2==1&&arr[i]=='b')needRed2++;
}
int total2;
if(needBlack2>needRed2)total2=needBlack2;
else total2=needRed2;

if(total2>total1)cout<<total1;
else cout<<total2;

delete arr;
return 0;
}