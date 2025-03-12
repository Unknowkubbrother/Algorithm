#include <bits/stdc++.h>
using namespace std;

void solve(vector<char> &arr, int start, int end)
{
    if (start == end - 1)
    {
        for (int i = 0; i < end; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

    for (int i = start; i < end; i++)
    {
        sort(arr.begin()+start,arr.end());
        swap(arr[i], arr[start]);
        solve(arr, start + 1, end);
        swap(arr[i], arr[start]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(arr,0,n);

    return 0;
}