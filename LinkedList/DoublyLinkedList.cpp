// DoublyLinkedList
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *prev;
	Node *next;
	Node(int d){
		data = d;
		prev = NULL;
		next = NULL;
	}
	~Node();
	
};

class DoublyLinkedList
{
public:
	Node *head;
	Node *tail;
	DoublyLinkedList(){
		head = NULL;
		tail = NULL;
	}
	void InsertAtBeg(int d){
		if(head == NULL){
			Node *n = new Node(d);
			head = n;
			tail = n;
		}
		else{
			Node *n = new Node(d);
			n->next = head;
			head->prev = n;
			head = n;
		}
	}
	void InsertAtEnd(int d){
		if(head == NULL){
			Node *n = new Node(d);
			head = n;
			tail = n;
		}
		else{
			Node *n = new Node(d);
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
	}
	int size(){
		int count=0;
		Node *temp=head;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}
	void InsertAtPos(int d,int pos){
		if(pos==0){
			InsertAtBeg(d);
		}
		else if(pos>=size()){
			InsertAtEnd(d);
		}
		else{
			Node *temp=head;
			while(--pos){
				temp=temp->next;
			}
			Node *n = new Node(d);
			n->next = temp->next;
			n->prev = temp;
			temp->next = n;
		}
	}
	void printReverse(){
		Node *temp=tail;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->prev;
		}
		cout<<"NULL"<<endl;
	}
	void print(){
		Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
	
};

int main()
{
	DoublyLinkedList dl;
	dl.InsertAtBeg(5);
	dl.InsertAtBeg(4);
	dl.InsertAtBeg(3);
	dl.InsertAtEnd(6);
	dl.InsertAtPos(7,3);
	dl.print();
	dl.printReverse();
	return 0;
}