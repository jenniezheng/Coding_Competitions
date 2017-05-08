
#include <iostream>
using namespace std;

int sumDigits(long long num){
	if(num<10)
		return num;
	return sumDigits(num%10 + sumDigits(num/10));
}


int main(){
string s;
cin>>s;
long long result=0;
for(int i=0; i<s.size(); i++)
	result+=(s[i]-'0');
int multiple;
cin>>multiple;
result*=multiple;
cout<<sumDigits(result);
return 0;
}