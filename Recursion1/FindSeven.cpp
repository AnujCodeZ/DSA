// FindSeven
#include<iostream>
using namespace std;
int FirstSeven(int *a, int n, int i, int x){
	if(i==n){
		return -1;
	}
	if(a[i] == x){
		return i;
	}
	return FirstSeven(a,n,i+1,x);
}
// int Last7(int *a, int n,int i, int x){
// 	if(i==n){
// 		return -1;
// 	}
// 	if(a[i] == x){
// 		int ChotaIndex = i;
// 		int BadaIndex = Last7(a,n,i+1,x);
// 		if(BadaIndex>ChotaIndex){
// 			return BadaIndex;
// 		}
// 		else{
// 			return ChotaIndex;
// 		}
// 	}
// }
int LastIndex(int *a, int n, int i, int x){
	if(i==0){
		return -1;
	}
	if(a[i]==x){
		return i;
	}
	return LastIndex(a,n,i-1,x);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	while(x--){
		int b;
		cin>>b;
	cout<<FirstSeven(a,n,0,b)<<" "<<LastIndex(a,n,n-1,b)<<endl;
}
	return 0;
}