#include <bits/stdc++.h>
using namespace std;

int minWires = INT_MAX;

void findMinWires(vector<int> &wires,vector<int> &x,int l,int k){
    int totalLength = 0;
    int wireCount = 0;

    for (int i = 1; i <= l; i++)
    {
        totalLength += wires[x[i] - 1];
        wireCount++;
    }


    if (totalLength == k)
    {
        minWires = min(minWires, wireCount);
    }
}

void solve(vector<int> &wires,vector<int> &x,int l,int n,int k){

    findMinWires(wires, x, l, k);

    int j = 1;
    if (l > 0){
        j = x[l] + 1;
    }

    for(int i=j;i<=n;i++){
        x[l + 1] = i;
        solve(wires, x, l + 1, n, k);
    }
}

int main(){
    int k;
    int n = 3;
    cin >> k;

    vector<int> x(k + 1);
    vector<int> wires(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wires[i];
    }

    solve(wires, x, 0, n, k);

    if (minWires != INT_MAX)
    {
        cout << minWires << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}