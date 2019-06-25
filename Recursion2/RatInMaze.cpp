// RatInMaze
#include <iostream>
using namespace std;
bool RatInMaze(char maze[][1000],int sol[][1000], int i,int j,int n,int m){
	//Base case
	if(i==n-1 && j==m-1){
		//Print the solution
		sol[i][j]=1;
		for (int k = 0; k < n; ++k)
		{
			for (int l = 0; l < m; ++l)
			{
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}
	//Recursive call
	sol[i][j] = 1;
	//Check Rightwards
	if(j+1<m && maze[i][j+1]!='X'){
		bool KyaRaastaMila = RatInMaze(maze,sol,i,j+1,n,m);
		if(KyaRaastaMila){
			return true;
		}
	}
	//Check Downwards
	if(i+1<n && maze[i+1][j]!='X'){
		bool KyaNeecheRaastaMila = RatInMaze(maze,sol,i+1,j,n,m);
		if(KyaNeecheRaastaMila){
			return true;
		}
	}
	sol[i][j] = 0;
	return false;
}
int main(int argc, char const *argv[])
{
	char maze[1000][1000];
	int sol[1000][1000] = {0};
	int n,m;
	cin>>n>>m;
	for (int k = 0; k < n; ++k){
		cin>>maze[k];
		}
	/* code */
	if(!RatInMaze(maze,sol,0,0,n,m)){
		cout<<-1;
	}
	
	return 0;
}