// BinarySearchTree
#include <iostream>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d):data(d),left(NULL),right(NULL){}
	
};

node* InsertInBST(node* root,int data){
	if(root == NULL){
		root = new node(data);
		return root;
	}

	if(data<=root->data){
		root->left = InsertInBST(root->left,data);
	}
	else{
		root->right = InsertInBST(root->right,data);
	}
	return root;
}

node* BuildTree(){
	node* root = NULL;

	int data;
	cin>>data;
	while(data!=-1){
		root = InsertInBST(root,data);
		cin>>data;
	}
	return root;
}

bool isBST(node* root,int min = INT_MIN,int max = INT_MAX){
	//Base case
	if(root == NULL){
		return true;
	}

	//Recursive Case
	if(root->data<=max && root->data>=min && isBST(root->left,min,root->data) && isBST(root->right,root->data,max)){
		return true;
	}
	else{
		return false;
	}
}

void PrintOrderLevel(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp == NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}

//Is Tree Balanced
class Pair
{
public:
	int Height;
	bool Balanced;
};

Pair isBalanced(node* root){
	Pair p;
	//Base Case
	if(root == NULL){
		p.Height = 0;
		p.Balanced = true;
		return p;
	}

	//Recursive Case
	Pair left = isBalanced(root->left);
	Pair right = isBalanced(root->right);

	p.Height = max(left.Height,right.Height)+1;

	if(left.Balanced && right.Balanced && abs(left.Balanced-right.Balanced)<=1){
		p.Balanced = true;
	}
	else{
		p.Balanced = false;
	}
	return p;
}

node* ArrayToBST(int *a,int s,int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node* root = new node(a[mid]);
	root->left = ArrayToBST(a,s,mid-1);
	root->right = ArrayToBST(a,mid+1,e);
	return root;

}

node* LevelOrderInput(){
	node* root = NULL;
	cout<<"Enter data : ";
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	root = new node(data);
	queue <node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		cout<<"Enter Children of "<<temp->data<<" : ";
		int c1,c2;
		cin>>c1>>c2;
		if(c1!=-1){
			temp->left = new node(c1);
			q.push(temp->left);
		}
		if(c2!=-1){
			temp->right = new node(c2);
			q.push(temp->right);
		}
	}
	return root;
}

class LinkedList
{
public:
	node* head;
	node* tail;	
};
LinkedList BstToLL(node* root){
	LinkedList l;
	//Base Case
	if(root == NULL){
		l.head = l.tail = NULL;
		return l;
	}
	//Recursive Case
	if(root->right==NULL && root->left!=NULL){
		LinkedList left = BstToLL(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}
	else if(root->right!=NULL && root->left==NULL){
		LinkedList right = BstToLL(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}
	else if(root->right==NULL && root->left==NULL){
		l.head = l.tail = root;
		return l;
	}
	else{
		LinkedList left = BstToLL(root->left);
		LinkedList right = BstToLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
}

void PrintLL(node* head){
	while(head){
		cout<<head->data<<"->";
		head = head->right;
	}
	cout<<endl;
}

int main()
{
	node* root = BuildTree();
	PrintOrderLevel(root);
	if(isBST(root)){
		cout<<"BST"<<endl;
	}
	else{
		cout<<"NOT BST"<<endl;
	}
	Pair p = isBalanced(root);
	if(p.Balanced){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}

	int a[]={1,3,4,5,6,7,8,10};
	int n = sizeof(a)/sizeof(int);

	node* root1 = ArrayToBST(a,0,n-1);
	if(p.Balanced){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}
	PrintOrderLevel(root1);

	cout<<"Input Level Order : "<<endl;
	node* root2 = LevelOrderInput();
	PrintOrderLevel(root2);

	LinkedList l = BstToLL(root);
	PrintLL(l.head);

	return 0;
}