// ElephantInChess
#include <iostream>
using namespace std;
int Ways(int i,int j){
	if(i==0 and j==0){
		return 1;
	}
	int sum = 0;
	for(int k=0;k<i;k++){
		sum += Ways(k,j);
	}
	for(int k=0;k<j;k++){
		sum += Ways(i,k);
	}
	return sum;

}
int main(int argc, char const *argv[])
{
	/* code */
	int i,j;
	cin>>i>>j;
	cout<<Ways(i,j);
	return 0;
}