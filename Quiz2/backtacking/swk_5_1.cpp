#include <iostream>
#include <algorithm>

using namespace std;
int arr[100000];
int n;
int maxs=0;
void gen(int s,int sum){
	if(sum>maxs){
		maxs=sum;
	}
	for(int i=s;i<n;i++){
		gen(i+2,sum+arr[i]);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	gen(0,0);
	cout<<maxs<<endl;
}