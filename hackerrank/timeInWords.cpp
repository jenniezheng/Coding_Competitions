#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string minToWord(int a){
	switch (a){
		case 0: return "o' clock";
		case 1: return "one minute";
		case 2: return "two minutes";
		case 3: return "three minutes";
		case 4: return "four minutes";
		case 5: return "five minutes";
		case 6: return "six minutes";
		case 7: return "seven minutes";
		case 8: return "eight minutes";
		case 9: return "nine minutes";
		case 10: return "ten minutes";
		case 11: return "eleventen minutes";
		case 12: return "twelve minutes";
		case 13: return "thirteen minutes";
		case 14: return "fourteen minutes";
		case 15: return "quarter";
		case 16: return "sixteen minutes";
		case 17: return "seventeen minutes";
		case 18: return "eighteen minutes";
		case 19: return "nineteen minutes";
		case 20: return "twenty minutes";
		case 21: return "twenty one minutes";
		case 22: return "twenty two minutes";
		case 23: return "twenty three minutes";
		case 24: return "twenty four minutes";
		case 25: return "twenty five minutes";
		case 26: return "twenty six minutes";
		case 27: return "twenty seven minutes";
		case 28: return "twenty eight minutes";
		case 29: return "twenty nine minutes";
		case 30: return "half";
		default: return "";
	}
}


string hourToWord(int a){
	switch (a){
		case 1: return "one";
		case 2: return "two";
		case 3: return "three";
		case 4: return "four";
		case 5: return "five";
		case 6: return "six";
		case 7: return "seven";
		case 8: return "eight";
		case 9: return "nine";
		case 10: return "ten";
		case 11: return "eleven";
		case 12: return "twelve";
		default: return "";
	}
}

int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    string strHour;
    string strMin;
    if(m>30){
    	strMin=minToWord(60-m)+" to ";
    	strHour=hourToWord(h%12+1);
    	cout<<strMin<<strHour<<endl;
    }
    else if(m==0){
    	strMin=minToWord(m);
    	strHour=hourToWord(h)+" ";
    	cout<<strHour<<strMin<<endl;
    }
    else{
    	strMin=minToWord(m)+" past ";
    	strHour=hourToWord(h);
    	cout<<strMin<<strHour<<endl;
    }
    
    return 0;
}
