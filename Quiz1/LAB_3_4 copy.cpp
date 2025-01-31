#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> S(1000);

int get_Sum(int start,int end){
    return S[end] - S[start-1];
}

int cross(int l,int m,int r){
    int leftMaxSum = get_Sum(l,m);
    for(int i=l;i<m;i++){
        leftMaxSum = max(leftMaxSum,get_Sum(i,m));
    }

    int rightMaxSum = get_Sum(m+1,r);
    for(int i=m+2;i<=r;i++){
         rightMaxSum = max(rightMaxSum,get_Sum(m+1,i));
    }

    return leftMaxSum+rightMaxSum;
}

int maxSubArraySum(vector<int> &prices,int l,int r){
    if (l == r){
        return prices[l];
    }

    int mid = (l+r)/2;

    int leftMax = maxSubArraySum(prices,l,mid);
    int rightMax = maxSubArraySum(prices,mid+1,r);
    int crossMax = cross(l,mid,r);


    return max(max(leftMax,rightMax),crossMax);
}
int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    S.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    S[0] = 0;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+= prices[i];
        S[i] = sum;
    }


    int maxProfit = maxSubArraySum(prices, 0, n - 1);
    cout << maxProfit << endl;

    return 0;
}