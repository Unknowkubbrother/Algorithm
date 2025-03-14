#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // ฐานกรณี: ยังไม่เดินถือว่ามี 1 วิธี

    // คำนวณวิธีการเดินแบบ DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << countWays(n, m) << endl;
    return 0;
}
