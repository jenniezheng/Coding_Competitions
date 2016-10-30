#include <iostream>
#include <vector>

using namespace std;

int lonely_integer(vector < int > a) {
    int result = 0;
    for (auto value : a)
        result ^= value;
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << lonely_integer(a) << endl;
    return 0;
}