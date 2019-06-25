// TowerOfHanoi 
#include <iostream>
#include<string>
using namespace std; 
int count = 0;
void towerOfHanoi(int n, char* from_rod, 
					char* to_rod, char* aux_rod) 
{ 
	if(n==0){
		return;
	}
	cout<<"n = : "<<n<<endl;
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 
	cout << "Move " << n << "th disc from " << from_rod << 
								" to " << to_rod << endl;
	count++;
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
}
int main() 
{ 
	int n;
	cin>>n;
	char a[]="T1",b[]="T2",c[]="T3";
	towerOfHanoi(n,a,b,c);
	cout<<count;
	return 0; 
}
