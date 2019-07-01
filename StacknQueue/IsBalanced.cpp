// IsBalanced
#include<iostream>
#include<stack>
using namespace std;

bool IsBalanced(char *in){
	stack<char> s;
	for(int i=0;in[i]!='\0';i++){
		char ch = in[i];
		switch(ch){
			case '(': s.push(ch);break;
			case '{': s.push(ch);break;
			case '[': s.push(ch);break;
			case ')': if(!s.empty() && s.top()=='('){
				s.pop();
			}
			else{
				return false;
			}
			break;
			case '}': if(!s.empty() && s.top()=='{'){
				s.pop();
			}
			else{
				return false;
			}
			break;
			case ']': if(!s.empty() && s.top()=='['){
				s.pop();
			}
			else{
				return false;
			}
			break;
		}
	}
	if(s.empty()){
		return true;
	}
	else
		return false;
}

int main()
{
	stack<char> s;
	 char in[100] = "{a+(b+c)*d+[e+f]/g}";
	 if(IsBalanced(in)){
	 	cout<<"YES"<<endl;
	 }
	 else{
	 	cout<<"NO"<<endl;
	 }
}