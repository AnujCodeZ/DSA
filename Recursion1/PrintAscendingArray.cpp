// PrintAscendingArray
#include<iostream>
using namespace std;
void PrintAscendingArray(int *a, int n){
	if(n==0){
		return;
	}
	// cout<<a[0]<<" ";
	PrintAscendingArray(a+1,n-1);
	cout<<a[0]<<" ";
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);
	PrintAscendingArray(a,n);
	return 0;
}