#include<iostream>
using namespace std;
string s[10] = {
	"zero","one","two","three","four","five","six","seven","eight","nine"
};
void StringToInt(int n){
	if(n==0){
		return;
	}
	int digit = n%10;
	StringToInt(n/10);
	cout<<s[digit]<<" ";
}
int main(int argc, char const *argv[])
{
	int a;
	cin>>a;
	StringToInt(a);
	return 0;
}