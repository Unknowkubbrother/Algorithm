#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool compareSort(long a, long b)
{
    return a < b;
}

long FreqDiff(vector<long> &arr)
{
    sort(arr.begin(), arr.end(), compareSort);
    long minFreq = LONG_MAX, maxFreq = LONG_MIN;
    long currentFreq = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currentFreq++;
        }
        else
        {
            minFreq = min(minFreq, currentFreq);
            maxFreq = max(maxFreq, currentFreq);
            currentFreq = 1;
        }
    }
    minFreq = min(minFreq, currentFreq);
    maxFreq = max(maxFreq, currentFreq);

    return abs(maxFreq - minFreq);
}

int main()
{
    int n;
    cin >> n;
    vector<long> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        long input;
        cin >> input;
        if (input > 0) {
            arr[i] = input;
        }
    }

    cout<<FreqDiff(arr);

    return 0;
}

// 7
// 4 2 4 4 4 2 2
// 7
// 1 2 4 4 4 2 2