#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> &arr, int start)
{
    for (int p = 0; p < start; p++)
    {
        if ((abs(p - start) == abs(arr[p] - arr[start])) || (arr[p] == arr[start]))
        {
            return false;
        }
    }
    return true;
}

void solve(vector<int> &arr, int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i < end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    for (int i = start; i < end; i++)
    {
        swap(arr[i], arr[start]);
        if (isSafe(arr, start))
        {
            solve(arr, start + 1, end);
        }
        swap(arr[i], arr[start]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    solve(arr, 0, n);

    return 0;
}