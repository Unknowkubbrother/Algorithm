#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &memo,int endX,int endY) {
    if (n == endX && m == endY) return matrix[0][0];
    if (n < 0 || m < 0) return INT_MAX;
    if (memo[n][m] != -1) return memo[n][m];

    int costFromTop = (n > 0) ? minCost(matrix, n-1, m, memo,endX,endY) : INT_MAX;
    int costFromLeft = (m > 0) ? minCost(matrix, n, m-1, memo,endX,endY) : INT_MAX;

    memo[n][m] = matrix[n][m] + min(costFromTop, costFromLeft);
    return memo[n][m];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    int startX,startY,endX,endY;
    cin>>endX>>endY>>startX>>startY;


    int result = minCost(matrix,startX,startY,memo,endX,endY);
    cout<<result;

    return 0;
}

// 3 3 
// 10 15 20 
// 25 30 35 
// 40 45 50 
// 0 0 2 2