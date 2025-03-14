#include <bits/stdc++.h>
using namespace std;

void subset1(vector<int> &arr, vector<int> &X, int l, int r, int &count)
{
    if (l == r)
    {
        bool isEmpty = true;
        for (int i = 1; i <= r; i++)
        {
            if (X[i] == 1)
            {
                cout << arr[i - 1];
                isEmpty = false;
            }
        }
        if (isEmpty)
        {
            cout << "0";
        }
        cout << endl;
        count++;
        return;
    }

    X[l + 1] = 1;
    subset1(arr, X, l + 1, r, count);
    X[l + 1] = 0;
    subset1(arr, X, l + 1, r, count);
}

int main()
{
    int n;
    cin >> n;
    vector<int> X(n + 1);
    vector<int> arr(n);

    for (int i = 1; i <= n; i++)
    {
        arr[i - 1] = i;
    }

    int count = 0;
    subset1(arr, X, 0, n, count);
    cout << count << endl;
}