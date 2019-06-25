// LinkedList using function
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

void print(Node* head){
	Node *temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
}

Node* mid(Node* head){	//By two pointers
	Node* fast = head->next;
	Node* slow = head;
	while(fast){
		fast = fast->next;
		if(fast!=NULL){
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}

Node* merge(Node* a,Node* b){
	//Base Case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	//Recursive Case
	Node* c;
	if(a->data<b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

Node* MergeSort(Node* head){
	//Base Case
	if(head == NULL || head->next == NULL){
		return head;
	}

	//Divide
	Node* m = mid(head);
	Node* a = head;
	Node* b = m->next;
	m->next = NULL;

	//Sort
	a = MergeSort(a);
	b = MergeSort(b);

	//Merge
	Node* newHead = merge(a,b);
	return newHead;
}

void Reverse(Node* &head){
	Node* p = NULL;
	Node* c = head;
	Node* n;
	while(c){
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}

int length(Node* head){
		int count=0;
		Node *temp=head;
		while(temp!=NULL){
			count++;
			temp=temp->next;
		}
		return count;
	}

void BubbleSort(Node* &head){
	Node* p;
	Node* c;
	Node* n;
	int len = length(head);
	for (int i = 0; i < len-1; ++i)
	{
		c = head;
		p = NULL;
		while(c && c->next){
			n = c->next;
			if(c->data>n->data){
				// Swapping
				if(p == NULL){
					//head Swap
					c->next = n->next;
					n->next = c;
					head = p = n;
				}
				else{
					//no head Swap
					c->next = n->next;
					n->next = c;
					p->next = n;
					p = n;
				}
			}
			else{
				//No Swapping
				p = c;
				c = c->next;
			}
		}
	}

}

int main()
{
	Node* head = NULL;
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;

	InsertAtBeg(head,8);
	InsertAtBeg(head,6);
	InsertAtBeg(head,4);
	InsertAtBeg(head,2);
	InsertAtBeg(head,0);

	InsertAtBeg(head1,9);
	InsertAtBeg(head1,7);
	InsertAtBeg(head1,5);
	InsertAtBeg(head1,3);
	InsertAtBeg(head1,1);

	InsertAtBeg(head2,1);
	InsertAtBeg(head2,3);
	InsertAtBeg(head2,2);
	InsertAtBeg(head2,5);
	InsertAtBeg(head2,4);
	
	InsertAtBeg(head3,1);
	InsertAtBeg(head3,3);
	InsertAtBeg(head3,2);
	InsertAtBeg(head3,5);
	InsertAtBeg(head3,4);
	
	print(head);
	print(head1);

	cout<<"Merged: "<<endl;
	head = merge(head,head1);
	print(head);

	cout<<"middle element: "<<endl;
	Node* ans = mid(head);
	cout<<ans->data<<endl;

	cout<<"Unsorted: "<<endl;
	print(head2);
	head2 = MergeSort(head2);
	cout<<"Sorted by MergeSort: "<<endl;
	print(head2);
	BubbleSort(head3);
	cout<<"Sorted by BubbleSort: "<<endl;
	print(head3);
	
	Reverse(head2);
	cout<<"reversed: "<<endl;
	print(head2);

	return 0;
}