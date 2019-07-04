// MiddleEleLL
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

int MiddleEleLL(Node* head){
	Node* fast = head->next;
	Node* slow = head;
	while(fast){
		fast = fast->next;
		if(fast==NULL){
			return slow->data;
		}
		else{
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow->data;
}

int main(int argc, char const *argv[])
{
	int n,d;
	Node* head = NULL;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		InsertAtEnd(head,d);
	}
	int mid = MiddleEleLL(head);
	cout<<mid<<endl;
	return 0;
}