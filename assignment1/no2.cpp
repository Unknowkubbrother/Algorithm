#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(int a,int b){
	return a < b;
}

int bts(int *A,int target,int l,int r){
	int mid = (l+r)/2;
	if (l>r){
		return -1;
	}else{
		if (A[mid] == target){
			return mid;
		}
		if (A[mid] < target){
			bts(A,target,mid+1,r);
		}else{
			bts(A,target,l,mid-1);
		}
	}
}

int subtractLowest(int *A,int n,int target){
	int min = INT_MAX;
	for(int i=0;i<n;i++){
		int dest = abs(target - A[i]);
		int idx = bts(A,dest,0,n-1);
		if (idx != -1 && i!= idx){
			int cal = abs(A[i] - A[idx]);
			if (cal < min){
				min = abs(A[i] - A[idx]);	
			}
		}
	}
	return min;
}

int main(){
	int n;
	int target;
	cin>>n>>target;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	
	sort(arr,arr+n,compare);
	cout<<subtractLowest(arr,n,target)<<endl;
	return 0;
}
