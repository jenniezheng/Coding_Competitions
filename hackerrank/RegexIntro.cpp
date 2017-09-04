#include <regex>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<string, string>> data;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        data.push_back(pair<string,string>(firstName, emailID));
        
    }
    sort(data.begin(),data.end());
   regex e("@gmail.com");  
    for(pair<string,string> p: data){
        if(regex_search(get<1>(p),e))
            cout<<get<0>(p)<<endl;
    }
    return 0;
}
