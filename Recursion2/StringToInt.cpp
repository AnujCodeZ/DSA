// StringToInt
#include <iostream>
#include<string.h>
using namespace std;
int StringToInt(char *s,int n){
	if(n==0){
		return 0;
	}
	int LastDigit = s[n-1]-'0';
	int ans = StringToInt(s,n-1)*10+LastDigit;
	return ans;
}
int main(int argc, char const *argv[])
{
	char s[1000];
	cin>>s;
	int n=strlen(s);
	cout<<StringToInt(s,n)*10;
	return 0;
}