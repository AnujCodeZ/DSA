// SubseqRec
#include <iostream>
using namespace std;
void SubseqRec(char *in,int i,char* out,int j){
	//Base case
	if(in[i]=='\0'){
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
	//Recursive case
	//Ek baar ignore karo
	SubseqRec(in,i+1,out,j);

	//Ek baar consider karo
	out[j]=in[i];
	SubseqRec(in,i+1,out,j+1);
}

int main(int argc, char const *argv[])
{
	char in[100],out[100];
	cin>>in;
	SubseqRec(in,0,out,0);
	
	return 0;
}