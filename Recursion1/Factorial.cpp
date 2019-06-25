#include<iostream>
using namespace std;
int fact(int n){
	//Base case
	if(n==0){
		return 1;
	}

	//Recursive case
	// int ChotaAns = fact(n-1);
	// int BadaAns = n*ChotaAns;
	return n*fact(n-1);
}
int main()
{
	
	int a;
	cin>>a;
	cout<<fact(a)<<endl;
	return 0;
}