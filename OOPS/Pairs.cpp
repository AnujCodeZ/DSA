// Pairs
#include <iostream>
using namespace std;

class A{
public:
	int x;
	int y;
	A(int a,int b){
		x = a;
		y = b;
	}
	bool operator>(A X){
		if(x>X.x and y>X.y){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(int argc, char const *argv[])
{
	A p1(20,30);
	A p2(15,25);
	if(p1>p2){
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;
	
	return 0;
}