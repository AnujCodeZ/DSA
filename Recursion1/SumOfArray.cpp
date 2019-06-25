// SumOfArray
#include<iostream>
using namespace std;
int sum(int *a,int n){
	if(n==0){
		return 0; 
	}
	return a[0]+sum(a+1,n-1);
}
int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		a[i]=i+1;
	}
	cout<<sum(a,n);
	return 0;
}