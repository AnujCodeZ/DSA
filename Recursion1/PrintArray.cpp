// PrintArray
#include<iostream>
using namespace std;
void PrintArray(int *a, int n){
	if(n==0){
		return;
	}
	//For acsending
	// cout<<a[0]<<" ";
	PrintArray(a+1,n-1);
	//For descending
	cout<<a[0]<<" ";
}
void print1(int *a, int n){
	if(n==0){
		return;
	}
	cout<<a[n-1]<<" ";
	print1(a,n-1);
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);
	PrintArray(a,n);
	print1(a,n);
	return 0;
}