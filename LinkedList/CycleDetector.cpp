// CycleDetector
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int d)
	{
		data = d;
		next = NULL;
	}
	
};

void InsertAtBeg(Node* &head,int d){
	if(head==NULL){
			Node *n = new Node(d);
			head = n;
		}
		else{
			Node *n = new Node(d);
			n->next = head;
			head = n;
		}
}

void MakeCycle(Node* head, int k){
	Node* fast = head;
	int count = 1;
	while(count < k){
		fast = fast->next;
		count++;
	}
	Node* slow = fast;
	while(fast->next){
		fast = fast->next;
	}
	fast->next=slow;
	cout<<"Cycle at : "<<slow->data<<endl;
}

void print(Node* head){
	Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
}

bool IsCycle(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while(fast){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
			if(fast==slow){
				return true;
			}
		}
	}
	return false;
}

int main()
{
	Node* head=NULL;
	InsertAtBeg(head,8);
	InsertAtBeg(head,7);
	InsertAtBeg(head,6);
	InsertAtBeg(head,5);
	InsertAtBeg(head,4);
	InsertAtBeg(head,3);
	InsertAtBeg(head,2);
	InsertAtBeg(head,1);
	MakeCycle(head,3);
	// print(head);
	if(IsCycle(head)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}

	return 0;
}