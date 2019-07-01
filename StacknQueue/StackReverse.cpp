// StackReverse
#include <iostream>
#include <stack>
using namespace std;

void pushBottom(stack<int> &s,int TopElement){
	//Base caes
	if(s.empty()){
		s.push(TopElement);
		return;
	}
	//Recursive case
	int top = s.top();
	s.pop();
	pushBottom(s,TopElement);
	s.push(top);
}

void StackReverse(stack<int> &s){
	//Base case
	if(s.empty()){
		return;
	}
	//Recursive case
	int TopElement = s.top();
	s.pop();
	StackReverse(s);
	pushBottom(s,TopElement);
}

void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main()
{
	stack<int> s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	print(s);
	StackReverse(s);
	cout<<endl;
	print(s);
	return 0;
}