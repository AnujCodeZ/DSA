// ExperimentalAnalysis
#include <iostream>
using namespace std;

void merge(int *x,int *y,int *a,int s,int e){
	int i = s;
	int mid = (s+e)/2;
	int j = mid+1;
	int k =s;

	while(i<=mid && j<=e){
		if(x[i]<y[j]){
			a[k++] = x[i++];
		}
		else{
			a[k++]=y[j++];
		}
	}

	while(j<=e){
		a[k++]=y[j++];
	}

	while(i<=mid){
		a[k++]=x[i++];
	}
}


void MergeSort(int *a,int s,int e){
	// Base case
	if(s>=e){
		return;
	}
	// Recursive case
	// Divide
	int mid = (s+e)/2;
	int x[100],y[100];
	for(int i=s;i<=mid;i++){
		x[i]=a[i];
	}
	for(int i=mid+1;i<=e;i++){
		y[i]=a[i];
	}
	// Sort
	MergeSort(x,s,mid);
	MergeSort(y,mid+1,e);
	//Merge
	merge(x,y,a,s,e);
}

void BubbleSort(int *a,int n){
	for (int i = 0; i < n-1; ++i)
	{
		for(int j = 0;j<=n-2-i;j++){
			if(a[j]>a[j+1]){
				
			}
		}
	}
}