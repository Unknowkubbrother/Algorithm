#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int k,int n)
{

    if (k == n)
    {
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";

        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        arr[k] = i;
        solve(arr,k + 1,n);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    solve(arr,0,n);

    return 0;
}