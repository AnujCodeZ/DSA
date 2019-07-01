// Queue
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int d):data(d),next(NULL){};
	
};

class Queue
{
public:
	Node* head;
	Node* tail;
	Queue(){
		head = tail = NULL;
	}

	void push(int d){
		if(head==NULL){
			Node* n = new Node(d);
			head = tail = n;
		}
		else{
			Node* n = new Node(d);
			tail->next = n;
			tail = n;
		}
	}

	void pop(){
		if(head==NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = tail = NULL;
		}
		else{
			Node* temp = head;
			delete temp;
			head = head->next;
		}
	}

	int front(){
		return head->data;
	}

	bool empty(){
		return head==NULL;
	}
};

int main()
{
	Queue q;
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