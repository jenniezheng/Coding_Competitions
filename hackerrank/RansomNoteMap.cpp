#include <map>
#include <iostream>
#include <vector>
using namespace std;



bool ransom_note(vector<string> magazine, vector<string> ransom) {
    map<string, int> m;
      for(string &it: magazine){
           m[it]++;
            }
    
      for(string &it: ransom){
            //if s not in map, return false
            if(m[it]<0)return false;
                m[it]--;
            }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}