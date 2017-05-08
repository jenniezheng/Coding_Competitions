
#include <queue> 
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int numPreliminary, maxNumberContests;
	cin>>numPreliminary>>maxNumberContests;
	long result=0;
	priority_queue<int,vector<int>,greater<int> > q;
    
	while (numPreliminary){
		int luckAmount, important;
		cin>>luckAmount>>important;
		if(important){
			if(q.size() < maxNumberContests)
				q.push(luckAmount);
			else if (maxNumberContests>0 && luckAmount > q.top()){
				result-=q.top();
				q.pop();
				q.push(luckAmount);
			}
			else result-=luckAmount;
		}
		else result+=luckAmount;
		numPreliminary--;
	}

	while( ! q.empty() ) {
        result+=q.top(); 
        q.pop();
    }
	cout<<result;
    return 0;
}
