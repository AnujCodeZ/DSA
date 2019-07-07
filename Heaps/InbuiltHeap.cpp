// InbuiltHeap
#include <iostream>
#include <queue>
using namespace std;

class Comparator
{
public:
	bool operator()(int a,int b){
		return a>b;
	}
	
};

int main()
{
	priority_queue<int,vector<int>,Comparator> h;
	h.push(3);
	h.push(5);
	h.push(4);
	h.push(0);
	h.push(8);
	h.push(1);

	while(!h.empty()){
		cout<<h.top()<<endl;
		h.pop();
	}

	return 0;
}