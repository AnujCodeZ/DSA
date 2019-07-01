// Stack.h
#ifndef Stack_H
#define Stack_H //for include many times this file
#include <iostream>
#include"Node.h"
using namespace std;
template<typename T>

class Stack
{
	Node<T>* head;
public:

	Stack(){
		head=NULL;
	}

	void push(T d){
		Node<T> *n = new Node<T>(d);
		n->next = head;
		head = n;
	}

	void pop(){
		if(head!=NULL){
			Node<T> *temp=head;
			head=head->next;
			delete temp;
		}
	}

	T top(){
		return head->data;
	}

	bool empty(){
		return head == NULL;
	}
	
};

#endif
