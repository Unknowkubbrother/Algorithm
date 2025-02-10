#include <iostream>
using namespace std;

void printArr(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool check(int arr[],int k)
{
    for (int i = 0; i < k; i++)
    {
        if ((abs(i - k) == abs(arr[i] - arr[k])) || arr[i] == arr[k])
        {
            return false;
        }
    }
    return true;
}

void n_queen(int arr[],int k,int n,int &coutSol)
{

    if (k == n)
    {
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    for (int row = 0; row < n; row++)
    {
        arr[k] = row;
        
        if (check(arr,k))
        {
            coutSol++;
            n_queen(arr,k + 1,n,coutSol);
        }
    }
}

int main()
{
    int X[4], n = 4;
    int arr[n];
    int coutSol = 0;
    n_queen(arr,0,n,coutSol);
    cout << coutSol;
    return 0;
}