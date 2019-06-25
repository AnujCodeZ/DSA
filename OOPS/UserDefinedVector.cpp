// UserDefinedVector
#include <iostream>
using namespace std;

class Vector{
 public:
 	int *arr;
 	int cs;
 	int ms;
 	Vector(int n=2){
 		arr = new int[n];
 		cs = 0;
 		ms = n;
 	}
 	void push_back(int data){
 		if(cs==ms){
 			int *oldarr = arr;
 			int oldms = ms;
 			arr = new int[2*ms];
 			ms = 2*ms;
 			for (int i = 0; i < oldms; ++i)
 			{
 				arr[i]=oldarr[i];
 				/* code */
 			}
 			delete []oldarr;
 		}
 		arr[cs] = data;
 		cs++;
 	}
 	void pop_back(){
 		if(cs>0)
 		cs--;
 	}
 	int size(){
 		return cs;
 	}
 	int capacity(){
 		return ms;
 	}
 	int operator[](int X){
 		return arr[X];
 	}
 };
int main()
{
	Vector a;
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.pop_back();
	for (int i = 0; i < a.size(); ++i)
	{

		cout<<a[i]<<" ";
	}
	cout<<a.size()<<endl;
	cout<<a.capacity()<<endl;
	
	return 0;
}