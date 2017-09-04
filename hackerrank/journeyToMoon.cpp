#include <vector>
#include <iostream>
using namespace std; 

unsigned long long nodes;
bool visited[500000];
vector<int> adj[500000];

void DFS(int num){
    nodes++;
    visited[num]=true;
    for(int i=0; i<adj[num].size(); i++){
        int newNode=adj[num][i];
        if( !visited[newNode])
            DFS(newNode);
    }
}
 
int main()
{ 
    int numAstro, numPairs;
    cin >> numAstro >> numPairs;
    for (int i = 0; i < numPairs; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<unsigned long long> totals;
   
    for(int i=0; i<numAstro; i++){
        if(!visited[i]){
            nodes=0;
            DFS(i);
            totals.push_back(nodes);
        }
    }
    
    unsigned long long result = (unsigned long long)numAstro/2*(numAstro-1);
    for(int i=0; i<totals.size(); i++){
        int numInGroup=totals[i];
        result-=(numInGroup*(numInGroup-1))/2;
    }
    
    cout << result << endl;
    return 0;
}