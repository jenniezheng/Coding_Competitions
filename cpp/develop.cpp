#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printTree(set<int>& tree){
    cout<<"Tree: ";
    for (std::set<int>::iterator it=tree.begin(); it!=tree.end(); ++it)
        cout<<*it<<" ";
     cout<<endl;
}

void printTrees(vector<set<int> >& tree){
    cout<<"Tree: ";
    for (int i=0; i<tree.size();i++){
        cout<<"Tree "<<i<<" : ";
        printTree(tree[i]);
    }
    cout<<endl;
}

void printMap(map<int, int> mmap){
    cout<<"map start\n";
    for(map<int, int >::const_iterator it = mmap.begin(); it != mmap.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    cout<<"map end"<<endl;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int numCities;
        int numRoads;
        int libCost;
        int roadCost;
        map<int, int> visited;
        map<int, vector<int>> revvisited;

        cin >> numCities >> numRoads>> libCost >> roadCost;
        if(libCost<=roadCost || numCities==0){
            cout<<libCost*(unsigned long long)numCities<<endl;
            for(int i=0; i<numRoads; i++){
                int trash;
                cin>>trash>>trash;
            }
            continue;
        }
        int treeSize=0;
        for(int a1 = 0; a1 < numRoads; a1++){
            //printMap(visited);
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            //cout<<"Cities: "<<city_1<<" "<<city_2<<endl;
            int connectOne=-1,connectTwo=-1;
            if( visited.find(city_1)!=visited.end())
                connectOne=visited[city_1];
            if( visited.find(city_2)!=visited.end())
                connectTwo=visited[city_2];
            
            if(connectOne!=-1 && connectOne==connectTwo)
                continue;
            else if(connectOne==-1 && connectTwo!=-1) {
                visited[city_1]=connectTwo;
                revvisited[connectTwo].push_back(city_1);
               // cout<<"inserting into ";
              //  printTree(trees[connectTwo]);
              //  cout<<"node "<<city_1<<endl;
            }
            else if(connectOne!=-1 && connectTwo==-1) {
                visited[city_2]=connectOne;
                revvisited[connectOne].push_back(city_2);
              //  cout<<"inserting into ";
             //  printTree(trees[connectOne]);
              //  cout<<"node"<<city_2<<endl;
            }
            else if(connectOne==-1 && connectTwo==-1){
                visited[city_1]=treeSize+1;
                visited[city_2]=treeSize+1;
                revvisited[treeSize+1].push_back(city_1);
                revvisited[treeSize+1].push_back(city_2);
                treeSize++;
            }
            else {
                vector<int> rev=revvisited[connectOne];
                 for(int i=0; i<rev.size(); i++){
                    visited[rev[i]]=connectTwo;
                    revvisited[connectTwo].push_back(rev[i]);
                }
                revvisited[connectOne].clear();
            }
               
        }

        set<int> uniqueTrees;
        for(map<int, int >::const_iterator it = visited.begin(); it != visited.end(); ++it){
            uniqueTrees.insert(it->second);
        }
        //cout<<uniqueTrees.size()<<endl;
        int roads=visited.size()-uniqueTrees.size();
        cout<<(unsigned long long)roads*roadCost + ((unsigned long long)numCities-roads)*libCost <<endl;
    }
    return 0;
}