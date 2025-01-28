#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currentSum = 0;
            for (int k = i; k <= j; k++)
            {
                currentSum += arr[k];
            }
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum << endl;

    return 0;
}