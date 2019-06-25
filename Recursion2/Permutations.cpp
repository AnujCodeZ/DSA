// Permutations
#include <iostream>
using namespace std;
void Permutations(char *in,int i){
	//Base case
	if(in[i]=='\0'){
		cout<<in<<endl;
		return;
	}
	//Recursion case
	for (int j = i; in[j] != '\0'; ++j)
	{
		swap(in[j],in[i]);
		Permutations(in,i+1);
		//Backtracking
		swap(in[j],in[i]);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	char in[100];
	cin>>in;
	Permutations(in,0);
	
	return 0;
}