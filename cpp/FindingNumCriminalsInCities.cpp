#include <iostream>
using namespace std;



int main() {
int cities, cop;
cin>>cities>>cop;
cop--;
bool* arr=new bool[cities];
for(int i=0; i<cities; i++)
    cin>>arr[i];
int criminals=0;
if (arr[cop]==1)criminals++;
for(int i=1; i+cop<cities&&cop-i>=0; i++)
    if(arr[cop+i]==1&&arr[cop-i]==1)
        {criminals+=2;
        //cout<<"add two for pos "<< cop+i<<" and pos "<<cop-i<<endl;
        }

if(cop>=cities/2)
    for(int i=0; i<2*cop-cities+1; i++)
    {if (arr[i]==1) criminals++;
    //cout<<"add one for pos "<< i<<endl;
    }
else
    for(int i=2*cop+1; i<cities; i++)
    {if (arr[i]==1) criminals++;
    //cout<<"add one for pos "<< i<<endl;
    }
cout<<criminals;
delete arr;
return 0;
}