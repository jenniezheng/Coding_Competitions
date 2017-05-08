#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



vector<string> fillWithWords(const vector<string>& words, int xPos, int yPos, bool horizontal, 
	int wordIndex, vector<string> crossWord){


	size_t len=words[wordIndex].size();

	for(int c=0; c<len; c++){
		if(horizontal){
			if(crossWord[xPos][yPos+c]=='-'||crossWord[xPos][yPos+c]==words[wordIndex][c])
				crossWord[xPos][yPos+c]=words[wordIndex][c];
			else return vector<string>();
		}
		else {
			if(crossWord[xPos+c][yPos]=='-'||crossWord[xPos+c][yPos]==words[wordIndex][c])
				crossWord[xPos+c][yPos]=words[wordIndex][c];
			else return vector<string>();
		}
	}

/*
	cout<<endl;
	for(int i=0; i<crossWord.size(); i++){
		cout<<crossWord[i]<<endl;
	}

	cout<<"("<<xPos<<", "<<yPos<<")"<<endl;
*/
	wordIndex++;
	if(wordIndex==words.size())
		return crossWord;
	
	len=words[wordIndex].size();
	//horizontal
	for(int r=0; r<10; r++){
		for(int c=0; c<10-len+1; c++){
			vector<string> res=fillWithWords(words, r, c, true, wordIndex, crossWord);
			if (res.size()!=0)return res;
		}
	}
	//vertical
	for(int r=0; r<10-len+1; r++){
		for(int c=0; c<10; c++){
			vector<string> res=fillWithWords(words, r, c, false, wordIndex, crossWord);
			if (res.size()!=0)return res;
		}
	}

}

vector<string> fillWithWordsHelper(const vector<string>& words, vector<string> crossWord){
	if(words.size()==0)
		return crossWord;
	size_t len=words[0].size();
	//horizontal
	for(int r=0; r<10; r++){
		for(int c=0; c<10-len+1; c++){
			vector<string> res=fillWithWords(words, r, c, true, 0, crossWord);
			if(res.size()!=0)return res;
		}
	}
	//vertical
	for(int r=0; r<10-len+1; r++){
		for(int c=0; c<10; c++){
			vector<string> res=fillWithWords(words, r, c, false, 0, crossWord);
			if(res.size()!=0)return res;
		}
	}
	return vector<string>();;

}

int main() {
    vector<string> crossWord(10);    
    for(int i=0; i<10; i++)
    	cin>>crossWord[i];
    string allWordsStr;
    cin>>allWordsStr;
    size_t pos;
	char delimiter=';';
	vector<string> words;
	while ((pos = allWordsStr.find(delimiter)) != -1) {
	    string s = allWordsStr.substr(0, pos);    
	    words.push_back(s);
	    allWordsStr.erase(0, pos + 1);
	}
	words.push_back(allWordsStr);
   	crossWord=fillWithWordsHelper(words,crossWord);
   	if(crossWord.size()==10)
	   	for(int i=0; i< 10; i++)
	   		cout<<crossWord[i]<<endl;   
}
