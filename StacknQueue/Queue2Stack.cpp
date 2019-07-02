// Queue2Stack
#include <iostream>
#include <queue>
using namespace std;

class Queue2Stack
{
	queue<int> q1;
	queue<int> q2;
public:
	Queue2Stack();
	
	void push(int d){
		if(q1.empty() && q2.empty()){
			q1.push(d);
		}
		else if(!q1.empty() && q2.empty()){
			q1.push(d);
		}
		else{
			q2.push(d);
		}
	}

	void pop(){
		if(!q1.empty() && q2.empty()){
			while(q1.size()>1){
				int element = q1.front();
				q2.push(element);
			}
			q1.pop();
		}
		else{
			while(q2.size()>1){
				int element = q2.front();
				q1.push(element);
			}
			q2.pop();
		}
	}

	int top(){
		if(!q1.empty() && q2.empty()){
			while(q1.size()>1){
				int element = q1.front();
				q2.push(element);
			}
			int ans = q1.front();
			q1.pop();
			q2.push(ans);
			return ans;
		}
		else{
			while(q2.size()>1){
				int element = q2.front();
				q1.push(element);
			}
			int ans = q2.front();
			q2.pop();
			q1.push(ans);
			return ans;
		}
	}

	bool empty(){
		if(q1.empty() && q2.empty()){
			return true;
		}
		else{
			return false;
		}
	}
};

int main()
{
	Queue2Stack s;
	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}