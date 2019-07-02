// CircularQueue
#include <iostream>
using namespace std;

class Queue
{
	int *arr;
	int n;
	int cs;
	int f;
	int e;
public:
	Queue(int s = 5){
		cs = 0;
		arr = new int[s]; //Dynamically declare
		n = s;
		f = 0;
		e = s-1;
	}
	
	void push(int d){
		if(cs == n){
			cout<<"Queue overflow"<<endl;
		}
		else{
			e = (e+1)%n; //For making cycle
			arr[e] = d;
			cs++;
		}
	}

	void pop(){
		if(cs==0){
			cout<<"Queue underflow"<<endl;
		}
		else{
			f = (f+1)%n;
			cs--;
		}
	}

	bool empty(){
		return cs==0;
	}

	int size(){
		return cs;
	}

	int front(){
		return arr[f];
	}
	
};

int main()
{
	Queue q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}

	return 0;
}