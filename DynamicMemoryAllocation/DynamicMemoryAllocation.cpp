// DynamicMemoryAllocation
#include <iostream>
using namespace std;

int* fun(int n){
	int *a = new int[n];
	for(int i = 0;i<n;i++){
		a[i] = i; //a[i] = *(a+i)
	}
	// for(int i = 0;i<n;i++){
	// 	cout<<a[i]<<" ";
	// }
	return a;
}
void **Array2D(int rows, int col){
	int **a = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		a[i] = new int[col];
	}
	int number=1;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			a[i][j] = number++;
			/* code */
		}
		/* code */
	}
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout<<a[i][j]<<" ";
			/* code */
		}
		cout<<endl;
		/* code */
	}

}

int main(int argc, char const *argv[])
{
	/* code */
	int *a = new int;
	*a = 10;
	cout<<*a<<endl;
	int n,m;
	cin>>n>>m;
	// int *arr = fun(n); //same array
	// for(int i = 0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	Array2D(n,m);
	//delete []arr; //delete memory from an array
	//arr = NULL;
	delete a; //delete memory 
	for (int i = 0; i < n; ++i)
	{
		delete []a[i];
		/* code */
	}
	delete []a;
	return 0;
}