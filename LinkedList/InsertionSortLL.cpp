// InsertionSortLL
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int d){
		data = d;
		next = NULL;
	}
	
};

void InsertAtEnd(Node* &head,int d){
	if(head==NULL){
			Node *n = new Node(d);
			head = n;
		}
		else{
			Node* temp = head;
			while(temp->next){
				temp = temp->next;
			}
			Node *n = new Node(d);
			temp->next = n;
		}
}

void print(Node* head){
	Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
}

void InsertionSortLL(Node* &head,Node* current,Node* sorted){
	//Base case
	if(current==NULL){
		head = sorted;
		return;
	}

	Node* temp;
	Node* curr = current->next;
	if(sorted==NULL || sorted->data >= current->data){
		current->next = sorted;
		sorted = current;
	}
	else{
		temp = sorted;
		while(temp->next!=NULL && temp->next->data < current->data){
			temp = temp->next;
		}
		current->next = temp->next;
		temp->next = current;
	}
	InsertionSortLL(head,curr,sorted);
}

int main()
{
	int n,d;
	Node* head = NULL;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		InsertAtEnd(head,d);
	}
	InsertionSortLL(head,head,NULL);
	print(head);
	return 0;
}