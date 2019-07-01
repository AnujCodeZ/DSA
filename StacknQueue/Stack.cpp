// Stack
#include <iostream>
#include "Stack.h"
using namespace std;

void print(Stack<char> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main()
{
	Stack<char> s;
	s.push('A');
	s.push('B');
	s.push('C');

	print(s);
	print(s);
	return 0;
}