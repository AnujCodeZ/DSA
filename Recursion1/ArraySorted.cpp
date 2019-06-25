#include<iostream>
using namespace std;
bool isSorted(int *a,int n){
	if(n==0||n==1){
		return true;
	}
	bool KyaChotaSortedHai = isSorted(a+1,n-1);
	if(a[0]<a[1]&&KyaChotaSortedHai==true){
		return true;
	}
	else{
		return false;
	}
}
int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	int a[1000];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	if(isSorted(a,n)){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}