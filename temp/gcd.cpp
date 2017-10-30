
#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int findGCDofArray(vector<int>& v, int n)
{
    int mygdc = v[0];
    for (int i=1; i<n; i++)
        mygdc = gcd(v[i], mygdc);
    return mygdc;
}


int main()
{
    vector<int> v;
    int n;
    cin>>n;
    for (int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cout << findGCDofArray(v, n) << endl;
    return 0;
}