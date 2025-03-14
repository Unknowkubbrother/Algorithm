#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &X,int start,int end){
	for(int i=start-1;i>=0;i--){
		cout<<X[i]<<" ";
	}
	cout<<endl;

	for(int i=1;i<=end;i++){
		X[start] = i;
		solve(X,start+1,i-1);
	}

}

int main(){
	int n;
	cin>>n;
	vector<int> X(n+1);
	solve(X,0,n);
	return 0;
}