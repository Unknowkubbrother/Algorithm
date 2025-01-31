#include <iostream>

using namespace std;

int ar[10000];

int stone(int l,int r){
	if(r-l+1 == 3){ // base case
		if(ar[l] == ar[l+1] && ar[l ]!= ar[r]){
			return r;
		}else if(ar[l ]== ar[r ]&& ar[l ]!= ar[l+1]){
			return l+1;
		}else if(ar[l+1] == ar[r] && ar[r ]!= ar[l]) {
			return l;
		}
	}else{
		int st = (l+r - 1) / 3;
		int first = stone(l,st);
		int second = stone(st+1,st+st+1);
		int tird = stone(st+2+st , r);
		
		if(ar[first] == ar[second] && ar[first ]!= ar[tird]){
			return tird;
		}else if(ar[first ]== ar[tird]&& ar[first]!= ar[second]){
			return second;
		}else if(ar[second] == ar[tird] && ar[tird ]!= ar[first]) {
			return first;
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i<n ;i++){
		cin >> ar[i];
	}
	
	cout << stone(0,n-1);
	return 0;
}