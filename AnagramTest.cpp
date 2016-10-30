#include <map>
#include <iostream>
#include <cmath>
using namespace std;

map<char, int>* mapString(string s){
    map<char, int>* m=new map<char,int>();
    for(int i=0; i<s.size(); i++){
        map<char,int>::iterator it=m->find(s[i]);
        if(it==m->end()) m->insert(pair<char, int>(s[i], 1));
        else it->second+=1;
   }

    return m;

}

int number_needed(string a, string b) {
   map<char, int>* mb=mapString(b);
   map<char, int>* ma=mapString(a);
   map<char,int>::iterator ia=ma->begin();
   map<char,int>::iterator ib=mb->begin();
   int del=0;
   while(ia!=ma->end()&&ib!=mb->end()){
       if(ia->first==ib->first){
           del+= abs(ia->second - ib->second); ia++;ib++; }
       else if(ia->first > ib->first) { del+=ib->second; ib++;}
       else { del+=ia->second; ia++;}

   }
   while(ia!=ma->end()){
      del+=ia->second; ia++;
   }
    while(ib!=mb->end()){
      del+=ib->second; ib++;
   }

   return del;
}

int main(){
    string a;
  cin >> a;
    string b;
   cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}