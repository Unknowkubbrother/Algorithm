#include <iostream>
using namespace std;

void interpolation(int *A,int target,int l,int r){
	int mid = l + ((target - A[l])*(r-l)/(A[r]-A[l]));
	cout<<mid<<" ";
	if (l>r){
		return;
	}else{
		if (A[mid] == target){
			return;
		}
		if (A[mid] < target){
			interpolation(A,target,mid+1,r);
		}else{
			interpolation(A,target,l,mid-1);
		}
	}
}

int main(){
	int n;
	int target;
	cin>>n>>target;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	interpolation(arr,target,0,n-1);
	return 0;
}
