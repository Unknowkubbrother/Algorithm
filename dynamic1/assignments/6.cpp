#include <bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<int> &memo)
{
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (memo[n] != -1){
        return memo[n];
    }
    int ways = 0;
    for (int i = 1; i <= m; i++)
    {
        ways += solve(n-i, m, memo);
    }
    memo[n] = ways;
    return ways;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> memo(n + 1, -1);
    cout<<solve(n, m, memo);
    return 0;
}