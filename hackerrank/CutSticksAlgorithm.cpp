#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int arr_i = 0;arr_i < n;arr_i++)
        cin>>v[arr_i];
    sort(v.begin(),v.end());


    for(int i=0; i<n; i++){
       cout<<n-i<<endl;
       while(i+1<n && v[i]==v[i+1])i++;//deaths increase
    }

    return 0;
}