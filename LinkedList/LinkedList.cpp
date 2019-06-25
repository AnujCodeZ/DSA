// LinkedList
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next; //Self refrential pointer
	Node(int d){
		data = d;
		next = NULL;
	}
	
};

class LinkedList
{
public:
	Node *head;
	Node *tail;
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	void InsertAtBeg(int d){
		if(head==NULL){
			Node *n = new Node(d);
			head = n;
			tail = n;
		}
		else{
			Node *n = new Node(d);
			n->next = head;
			head = n;
		}
	}
	void InsertAtEnd(int d){
		if(head==NULL){
			Node *n = new Node(d);
			head = n;
			tail = n;
		}
		else{
			Node *n = new Node(d);
			tail->next = n;
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
			temp->next = n;
		}
	}
	void DeleteAtBeg(){
		if(head==NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = NULL;
			tail = NULL;
		}
		else{
			Node *temp=head;
			head=head->next;
			delete temp;
		}
	}
	void DeleteAtEnd(){
		if(head==NULL){
			return;
		}
		else if(head->next == NULL){
			delete head;
			head = NULL;
			tail = NULL;
		}
		else{
			Node *temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			temp->next = NULL;
			delete tail;
			tail=temp;
		}
	}
	void DeleteAtPos(int pos){
		if(pos==0){
			DeleteAtBeg();
		}
		else if(pos==size()){
			DeleteAtEnd();
		}
		else{
			Node *temp=head;
			while(--pos){
				temp = temp->next;
			}
			Node *n = temp->next;
			temp->next = n->next;
			delete n;
		}
	}
	Node *search(int d,Node *temp){
		if(temp==NULL){
			return NULL;
		}
		if(temp->data == d)
			return temp;
		search(d,temp->next);
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
	LinkedList l;
	while(1){
		cout<<"---------------Menu---------------"<<endl;
		cout<<"1 for insert"<<endl;
		cout<<"2 for delete"<<endl;
		cout<<"3 for print"<<endl;
		cout<<"4 for search"<<endl;
		cout<<"5 for exit"<<endl;
		int c;
		cin>>c;
		switch(c){
			case 1: {
				int d,p;
				cout<<"Enter data and position: ";
				cin>>d>>p;
				l.InsertAtPos(d,p);
				break;
			}
			case 2: {
				int p;
				cout<<"Enter position for delete: ";
				cin>>p;
				l.DeleteAtPos(p);
				break;
			}
			case 3: {
				l.print();
				break;
			}
			case 4: {
				int d;
				cout<<"Enter data to be search: ";
				cin>>d;
				if(l.search(d,l.head) == NULL){
					cout<<"Not Found"<<endl;
				}
				else
					cout<<"Found : "<<l.search(d,l.head)->data<<endl;
				break;
			}
			case 5: exit(0);
			break;
			default: cout<<"Wrong input"<<endl;
			break;
		}

	}

	return 0;
}