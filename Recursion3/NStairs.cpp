// N_Stairs
#include <iostream>
using namespace std;
int NStairs(int n,int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int sum = 0;
	for(int i=1;i<=k;i++)
	sum += NStairs(n-i,k);
	return sum;
}
int main(int argc, char const *argv[])
{
	/* code */
	int n,k;
	cin>>n>>k;
	cout<<NStairs(n,k);
	return 0;
}