#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int down = l - 1;
    int up = r;
    while (true)
    {
        do
        {
            down++;
        } while (arr[down] < pivot);
        do
        {
            up--;
        } while (arr[up] > pivot);
        if (up <= down)
        {
            break;
        }
        swap(arr[down], arr[up]);
    }
    swap(arr[down], arr[r]);
    return down;
}

int quickSelect(vector<int> &arr, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }else{
        int p = partition(arr, l, r);
        if (p - l == k-1)
        {
            return p;
        }
        else if (p - l > k-1)
        {
            return quickSelect(arr, l, p - 1, k);
        }
        else
        {
            k = k - (p + 1);
            return quickSelect(arr, p + 1, r, k);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target = quickSelect(arr, 0, arr.size() - 1, arr.size()-k+1);
    int sum = 0;
    for(int i=target;i<arr.size();i++){
        sum+=arr[i];
    }
    cout<<fixed<<setprecision(2)<<(sum/(double)(arr.size()-target));
    return 0;
}

// 7 3
// 1 5 10 4 8 2 6