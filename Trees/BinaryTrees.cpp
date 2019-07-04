//BinaryTrees
#include <iostream>
#include <queue>
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

//Fast Diameter and Height
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

void MirrorTree(node* root){
	//Base Case
	if(root==NULL){
		return;
	}
	//Recursive Case
	swap(root->right,root->left);
	MirrorTree(root->left);
	MirrorTree(root->right);
}

int i = 0;
int pre[] = {8,10,1,6,4,7,3,14,13};
node* BuildTree(int *in,int s,int e){
	if(s>e){
		return NULL;
	}
	int data = pre[i];
	node* root = new node(data);
	i++;
	int k=-1;
	for(int j = s;j<=e;j++){
		if(in[j]==data){
			k = j;
			break;
		}
	}
	root->left = BuildTree(in,s,k-1);
	root->right = BuildTree(in,k+1,e);
	return root;
}

int main()
{
	node* root =  CreateTree();
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl<<endl;
	cout<<"Nodes : "<<CountNodes(root)<<endl;
	cout<<"Height : "<<Height(root)<<endl;
	cout<<"Diameter : "<<Diameter(root)<<endl<<endl;
	
	Pair p = FastDiameter(root);
	cout<<"HeightFast : "<<p.Height<<endl;
	cout<<"DiameterFast : "<<p.Diameter<<endl<<endl;

	cout<<"Order Level : "<<endl;
	PrintOrderLevel(root);
	cout<<endl;

	cout<<"Mirror Tree : "<<endl;
	MirrorTree(root);
	PrintOrderLevel(root);
	cout<<endl;

	int in[] = {1,10,4,6,7,8,3,13,14};
	int n = sizeof(in)/sizeof(int);
	node* root1 = BuildTree(in,0,n-1);
	cout<<"Tree using PreOrder and InOrder : "<<endl;
	PrintOrderLevel(root1);

	return 0;
}