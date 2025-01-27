#include <iostream>
#include <vector>
using namespace std;

int n = 4;
int Wmax = 0;
int Vmax = 0;

void findMostV(vector<vector<int>> &inventory,vector<int> &x,int l,int k){
    int Vsum = 0;
    int Wsum = 0;

    for(int i=1;i<=l;i++){
        if (Wsum < k){
            Wsum += inventory[x[i]-1][0];
            Vsum += inventory[x[i]-1][1];
        }
    }

    if (Wsum > Wmax && Wsum <= k && Vsum > Vmax){
        Wmax = Wsum;
        Vmax = Vsum;
    }
}

void subset2(vector<vector<int>> &inventory,vector<int> &x,int l,int n,int k){
    findMostV(inventory,x,l,k);
    int j;
    if (l==0){
        j=1;
    }else{
        j = x[l] + 1;
    }

    for(int i=j;i<=n;i++){
        x[l+1] = i;
        subset2(inventory,x,l+1,n,k);
    }


}

int main(){
    int k;
    vector<int> x(n+1);
    vector<vector<int>> inventory(n, vector<int>(2));
    cin>>k;

    for(int i=0;i<n;i++){
        cin>>inventory[i][1];
    }

    for(int i=0;i<n;i++){
        cin>>inventory[i][0];
    }

    subset2(inventory,x,0,n,k);

    cout<<Vmax;

    return 0;
}

// 18
// 12 5 4 2
// 8 7 4 2