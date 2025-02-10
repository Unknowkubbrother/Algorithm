#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int roundCount = 0;

void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int l, int m, int r)
{
    int nL = m - l + 1;
    int nR = r - m;
    vector<int> L(nL);
    vector<int> R(nR);

    for (int i = 0; i < nL; i++)
    {
        L[i] = arr[l + i];
    }

    for (int i = 0; i < nR; i++)
    {
        R[i] = arr[m + i + 1];
    }

    int i, j;
    i = j = 0;
    int k = l;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
        k++;
    }

    while (i < nL || j < nR)
    {
        if (i < nL)
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int bts(vector<int> &arr, int l, int r, int target)
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    roundCount++;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] > target)
    {
        return bts(arr, l, mid - 1, target);
    }
    else
    {
        return bts(arr, mid + 1, r, target);
    }
}

int duplicate(vector<int> &arr,int target,int start)
{
    int idx = bts(arr, start, arr.size() - 1, target);
    if (idx == -1)
    {
        return -1;
    }

    int first, last, current;
    first = last = current = idx;
    while (current != -1)
    {
        first = current;
        current = bts(arr, start, current - 1, target);
    }

    current = idx;

    while (current != -1)
    {
        last = current;
        current = bts(arr, current + 1, arr.size() - 1, target);
    }

    return last-first+1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    int maxCount = INT_MIN;
    int value = arr[0];
    for(int i=0;i<n;){
        int target = arr[i];
        int step = duplicate(arr, target, i);
        if (step > maxCount && step != -1){
            maxCount = step;
            value = arr[i];
        }
        i += step;
    }

    cout << value << " " << maxCount << " " << roundCount;
    return 0;
}