// Sort012LL
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

void sort012(Node* &head)  
{
    int count[3] = {0, 0, 0};
    Node *temp = head;
    while (temp != NULL)
    {
        count[temp->data] += 1;
        temp = temp->next;
    }

    int i = 0;
    temp = head;

    while (temp != NULL)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            temp->data = i;
            --count[i];
            temp = temp->next;
        }
    }
}

int main()
{
	Node* head=NULL;
	int n,d;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>d;
		InsertAtEnd(head,d);
	}
	sort012(head);
	print(head);

	return 0;
}
