//MinHeap
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
	vector<int> v;

	void Heapify(int i){
		int min_index = i;
		int left_child = 2*i;
		int right_child = left_child + 1;
		if(left_child < v.size() && v[min_index]>v[left_child]){
			min_index = left_child;
		}
		if(right_child < v.size() && v[min_index]>v[right_child]){
			min_index = right_child;
		}
		if(min_index!=i){
			swap(v[min_index],v[i]);
			Heapify(min_index);
		}

	}
public:
	MinHeap(){
		v.push_back(-1);
	}

	void push(int d){
		v.push_back(d);
		int children = v.size()-1;
		int parent = children/2;
		while(children>1 && v[children]<v[parent]){
			swap(v[children],v[parent]);
			children = parent;
			parent = parent/2;
		}
	}

	void pop(){
		swap(v[1],v[v.size()-1]);
		v.pop_back();
		Heapify(1);
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size()==1;
	}
	
};

int main()
{
	MinHeap h;
	h.push(10);
	h.push(2);
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