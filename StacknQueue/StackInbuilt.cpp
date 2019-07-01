// StackInbuilt
#include <iostream>
#include<stack> //Inbuilt STL
using namespace std;

void print(stack<char> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}
void print(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main()
{
	stack<char> s;
	stack<int> s1;
	s.push('A');
	s.push('B');
	s.push('C');
	s1.push(3);
	s1.push(4);

	print(s);
	print(s1);

	return 0;
}