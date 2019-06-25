// GridWays
#include <iostream>
using namespace std;
int GridWays(int i,int j){
	if(i==0 and j==0){
		return 1;
	}
	if(i<0 or j<0){
		return 0;
	}
	return GridWays(i-1,j)+GridWays(i,j-1);
}
int main(int argc, char const *argv[])
{
	/* code */
	int i,j;
	cin>>i>>j;
	cout<<GridWays(i,j);
	return 0;
}