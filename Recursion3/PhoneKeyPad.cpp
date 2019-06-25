// PhoneKeyPad
#include <iostream>
using namespace std;
int count = 0;
string keys[10]={
	"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"
};
void PhoneKeyPad(char *in,int i,char *out,int j){
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<" ";
		count++;
		return;
	}
	int digit = in[i]-'0';
	for(int k = 0;keys[digit][k]!='\0';k++){
		out[j] = keys[digit][k];
		PhoneKeyPad(in,i+1,out,j+1);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	char in[10],out[100];
	cin>>in;
	PhoneKeyPad(in,0,out,0);
	cout<<endl<<count;
	return 0;
}