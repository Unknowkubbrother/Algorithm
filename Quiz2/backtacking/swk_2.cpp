#include <bits/stdc++.h>
using namespace std;

int countCombinations = 0;

void per(vector<int> &X, int start, int end, int k) {
    if (start == k) {
        for (int i = 0; i < k; i++) {
            cout << X[i] << " ";
        }
        cout << "\n";
        countCombinations++;
        return;
    }

    for (int i = start; i < end; i++) {
        sort(X.begin()+start,X.end());
        swap(X[start],X[i]);
        per(X,start+1,end,k);
        swap(X[start],X[i]);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> X(n);

    for(int i=1;i<=n;i++){
        X[i-1] = i;
    }

    per(X, 0, n, k);
    cout << countCombinations << "\n";
    return 0;
}