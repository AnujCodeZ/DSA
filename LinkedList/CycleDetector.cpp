// CycleDetector
#include <iostream>
using namespace std;

int count1 = 1,count2=0;

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

bool search(Node *temp,int d){
	if(temp==NULL){
		count2 = 0;
		return false;
	}
	if(temp->data == d){
		return true;
	}
	else{
		count2++;
		search(temp->next,d);
	}
}

void MakeCycle(Node* &head){
	Node* temp = head;
	Node* n = head->next;
	while(n){
		if(search(n,temp->data)){
			break;
		}
		temp = temp->next;
		n = n->next;
		count1++;
	}
	temp = head;
	int count = 1;
	while(count<(count1+count2)){
		temp = temp->next;
		count++;
	}
	temp->next=NULL;
	int k = count1;
	Node* fast = head;
	count = 1;
	while(count < k){
		fast = fast->next;
		count++;
	}
	Node* slow = fast;
	while(fast->next){
		fast = fast->next;
	}
	fast->next=slow;
}

void print(Node* head){
	Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
}

void breakCycle(Node* &head,Node* fast,Node* p){
	Node* slow = head;
	while(1){
		if(fast==slow){
			break;
		}
		else{
			fast = fast->next;
			slow = slow->next;
			p = p->next;
		}
	}
	p->next = NULL;
}

void IsCycle(Node* &head)
{
	Node* fast = head;
	Node* slow = head;
	Node* p = NULL;
	while(fast){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			p = slow;
			slow=slow->next;
			if(fast==slow){
				breakCycle(head,fast,p);
			}
		}
	}
	return;
}

int main()
{
	Node* head=NULL;
	int d;

	while(1){
		cin>>d;
		if(d!=-1){
			InsertAtEnd(head,d);
		}
		else{
			break;
		}
	}

	MakeCycle(head);
	IsCycle(head);
	print(head);

	return 0;
}