#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int numCities;
        int numRoads;
        int libCost;
        int roadCost;
        vector<set<int>> trees; 
        cin >> numCities >> numRoads>> libCost >> roadCost;
        int connectOne=-1,connectTwo=-1;
        for(int a1 = 0; a1 < numRoads; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            for(int i=0; i<trees.size(); i++){
                if(trees[i].find(city_1)!=-1){
                    connectOne=i;
                    break;
                }
            }
            for(int i=0; i<trees.size(); i++){
                if(trees[i].find(city_2)!=-1){
                    connectTwo=i;
                    break;
                }
            }
            if(connectOne==connectTwo)continue;
            else if(connectOne==-1 && connectTwo!=-1) trees[connectTwo].insert(city_2);
            else if(connectOne!=-1 && connectTwo==-1) trees[connectOne].insert(city_1);
            else {
                trees[connectTwo].insert(trees[connectOne].begin(), trees[connectOne].end());
                trees.erase(connectOne);
            }
        }
        if(libCost<=roadCost)
            cout<<libCost*numCities<<endl;
        else {
            int roads=0;
            for(int i=0; i<trees.size(); i++)
                roads+=trees[i].size();
            cout<<(roads-trees.size())*roadCost+trees.size()*libCost<<endl;
        }
            
    }
    return 0;
}