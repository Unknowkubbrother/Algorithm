#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int V[] = {8,4,7};
int W[] = {12,5,4};
int maxWeight = 18;
int maxV = INT_MIN;

void printArr(vector<int> &x,int n){
    int sumW = 0;
    int sumV = 0;
    for(int i=1;i<=n;i++){
        if (x[i] == 1){
            sumW += W[i-1];
            sumV += V[i-1];

        }
    }

    if (sumW <= maxWeight){
        maxV = max(maxV,sumV);
    }
}


void subset1(vector<int> &x,int l,int r){
    if (l==r){
        printArr(x,r);
    }else{
        x[l+1] = 1;
        subset1(x,l+1,r);
        x[l+1] = 0;
        subset1(x,l+1,r);

    }

}

int main(){
    int n = 4;
    vector<int> x(n+1);

    subset1(x,0,n);
    cout<<maxV<<endl;
    return 0;
}