#include <vector> 
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int numNums;
	cin>>numNums;
	vector<int> myNums;
	for(int i=0; i<numNums; i++){
		int myInt;
		cin>>myInt;
		myNums.push_back(myInt);
	}
	sort(myNums.begin(),myNums.end());
	long min=abs(myNums[0]-myNums[1]);
	for(int i=2; i<numNums; i++)
		if(min>abs(myNums[i-1]-myNums[i]))
			min=abs(myNums[i-1]-myNums[i]);
	cout<<min;
    return 0;
}
