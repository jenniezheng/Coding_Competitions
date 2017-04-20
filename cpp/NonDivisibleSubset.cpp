#include <iostream>
using namespace std;


int main() {
    int size, k;//find largest subset where set values aren't divisible by k;
    cin>>size>>k;
    int* arr=new int[k];
    for(int i=0; i<k; i++){
        arr[i]=0;
    }
    for(int i=0; i<size; i++){
        int x;
        cin>>x;
        arr[x%k]+=1;
    }

    for(int i=0; i<k; i++)
        cerr<<arr[i]<<" ";
    cerr<<endl;

    int count=0;
    if(k%2==0){
        for(int i=1; i<k/2; i++){
            count+=((arr[i]>arr[k-i])? arr[i]: arr[k-i]);//find larger set
            cerr<<"Count now: "<<count<<endl;
        }
        if(arr[k/2]!=0)count++;
        cerr<<"Count now: "<<count<<endl;
     }
    else {
        for(int i=1; i<=k/2; i++){
            count+=((arr[i]>arr[k-i])?arr[i]:arr[k-i]);//find larger set
            cerr<<"Count now: "<<count<<endl;
        }
    }
    if(arr[0]!=0)count++;
    delete[] arr;
    cout<<count<<endl;
}
