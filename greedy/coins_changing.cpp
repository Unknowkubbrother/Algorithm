#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a,int b){
    return a >= b;
}

void printArr(int D[],int n){
    for(int i=0;i<n;i++){
        cout<<D[i]<<" ";
    }
    cout<<endl;
}


int coin_change(int W,int D[]){
    int cnts = 0;
    int i = 0;
    while (W > 0){
        int coin = W / D[i];
        cnts += coin;
        W = W - coin * D[i];
        i++;
    }
    return cnts;
}

int main(){
    int n = 4;
    int D[] = {1,5,2,10};
    int W = 13;
    sort(D,D+n,compare);
    printArr(D,n);
    cout<<coin_change(W,D);
}