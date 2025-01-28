#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int flag = false;

    for (int i = 0; i < n; i++)
    {
        int diff = x - arr[i];
        int idxTarget = -1;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == diff && i < j)
            {
                idxTarget = j;
                flag = true;
            }
        }
        if (idxTarget != -1 )
        {
            cout << arr[i] << " " << arr[idxTarget]<<endl;
        }
    }

    if (!flag)
    {
        cout << -1 <<endl;
    }

    return 0;
}