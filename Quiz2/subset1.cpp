#include <bits/stdc++.h>
using namespace std;

void subset1(vector<int> X, int l, int r)
{
    if (l == r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << X[i] << " ";
        }
        cout << endl;
    }
    else
    {

        X[l + 1] = 1;
        subset1(X, l + 1, r);
        X[l + 1] = 0;
        subset1(X, l + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> X(n + 1);

    subset1(X, 0, n);
}