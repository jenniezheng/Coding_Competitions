#include <iostream>
#include <list>
using namespace std;


class Solution {
    public:
list<char> stack;
list<char> queue;

void pushCharacter(char ch) {stack.push_back(ch);}
void enqueueCharacter(char ch) {queue.push_front(ch);}
char popCharacter() {char back=stack.back();  stack.pop_back();  return back;}
char dequeueCharacter() {char back=queue.back(); queue.pop_back(); return back; }
void check(){
for(list<char>::iterator it=stack.begin(); it!=stack.end();it++)
    cout<<*it;
    cout<<" ";
for(list<char>::iterator it=queue.begin(); it!=queue.end();it++)
    cout<<*it;
cout<<endl;
}
};