// KthElementLL
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

Node* KthElementLL(Node* head, int k){
	Node* fast = head;
	Node* slow = head;
	int count = 1;
	while(count < k){
		fast = fast->next;
		count++;
	}
	while(fast->next){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
	int c;
	Node* head = NULL;
	while(1){
		cin>>c;
		if(c==-1){
			break;
		}
		else{
			InsertAtEnd(head,c);
		}
	}
	int k;
	cin>>k;
	Node* ans = KthElementLL(head,k);
	cout<<ans->data<<endl;
	return 0;
}