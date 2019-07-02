//BinaryTrees
#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;
	node(int d):data(d),right(NULL),left(NULL){}
};

node* CreateTree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	node* root = new node(data);
	root->left = CreateTree();
	root->right = CreateTree();

	return root;
}

void PreOrder(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root){
	if(root == NULL){
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(node* root){
	if(root == NULL){
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

int CountNodes(node* root){
	if(root == NULL){
		return 0;
	}

	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

int Height(node* root){
	if(root == NULL){
		return 0;
	}
	int left = Height(root->left);
	int right = Height(root->right);
	return max(left,right)+1;
}

int Diameter(node* root){ //O(n*n)
	if(root == NULL){
		return 0;
	}

	int opt1 = Height(root->left)+Height(root->right);
	int opt2 = Diameter(root->left);
	int opt3 = Diameter(root->right);

	return max(opt1,max(opt2,opt3));
}

class Pair
{
public:
	int Diameter;
	int Height;
	
};

Pair FastDiameter(node* root){ //O(n) 
	Pair p;
	if(root == NULL){
		p.Height = p.Diameter = 0;
		return p;
	}

	Pair left = FastDiameter(root->left);
	Pair right = FastDiameter(root->right);

	//Height of the tree
	p.Height = max(left.Height,right.Height) + 1;

	int opt1 = left.Height + right.Height;
	int opt2 = left.Diameter;
	int opt3 = right.Diameter;

	p.Diameter = max(opt1,max(opt2,opt3));

	return p;
}

int main()
{
	node* root =  CreateTree();
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
	cout<<"Nodes : "<<CountNodes(root)<<endl;
	cout<<"Height : "<<Height(root)<<endl;
	cout<<"Diameter : "<<Diameter(root)<<endl;
	
	Pair p = FastDiameter(root);
	cout<<"HeightFast : "<<p.Height<<endl;
	cout<<"DiameterFast : "<<p.Diameter<<endl;


	return 0;
}