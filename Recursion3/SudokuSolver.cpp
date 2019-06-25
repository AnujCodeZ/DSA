// SudokuSolver
#include <iostream>
#include <cmath>
using namespace std;

bool isSafeToPut(int board[][9],int n,int number,int i,int j){
	for(int k =0;k<n;k++){
		if(board[k][j] == number || board[i][k]==number){
			return false;
		}
	}

	n = sqrt(n);

	int starti = (i/n)*n;
	int startj = (j/n)*n;

	for(int k=starti;k<starti+n;k++){
		for(int l=startj;l<startj+n;l++){
			if(board[k][l]==number){
				return false;
			}
		}
	}
	return true;

}


bool SudokuSolver(int board[][9],int n,int i,int j){
	// Base Case
	if(i==n){
		// Print the board
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<board[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	if(j==n){
		return SudokuSolver(board,n,i+1,0);
	}

	if(board[i][j]!=0){
		return SudokuSolver(board,n,i,j+1);
	}

	//Recursive case
	for(int number = 1; number <= n ; number++){
		if(isSafeToPut(board,n,number,i,j)){
			board[i][j] = number; // Place the number
			bool KyaBaakiBaatBani = SudokuSolver(board,n,i,j+1);
			if(KyaBaakiBaatBani){
				return true;
			}
			board[i][j] = 0;
		}
	}
	return false;
}


int main(){
	int n;
	cin>>n;
	int mat[9][9];
	for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cin>>mat[k][l];
			}
	}

	cout<<"---------------------------"<<endl;

	SudokuSolver(mat,n,0,0);
	

	return 0;
}