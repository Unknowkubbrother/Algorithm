#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int solutionCount = 0;

void permute(int arr[], int start, int end)
{
    if (start == end)
    {
        bool flag = false;

        for (int i = 1; i <= end; i++)
        {
            for (int p = 1; p < i; p++)
            {
                if (
                    (abs(p - i) == abs(arr[p] - arr[i])) ||
                    (arr[i] == arr[p]))
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
            return;

        for (int i = 1; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    for (int i = start; i <= end; i++)
    {
        solutionCount++;
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n = 16;
    int arr[] = {-1, 0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15};

    permute(arr, 1, n);
    cout<<solutionCount<<endl;

    return 0;
}
