#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime(int n){
    if (n == 1) return true;
    for(int i=2;i<=sqrt(n);i++){
        if (n%i == 0) return false;
    }
    return true;
}

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void ShellSort(vector<int> &arr)
{
    vector<int> primeNumber;
    for(int i=1;i<=arr.size();i++){
        if (prime(i)){
            primeNumber.push_back(i);
        }
    }

    int kIndex = primeNumber.size()-1;
    while (kIndex >= 0)
    {
        int k = primeNumber[kIndex];
        for (int i = k; i < arr.size(); i++)
        {
            int after = arr[i];
            int before = i - k;

            while (before >= 0 && arr[before] > after)
            {
                arr[before + k] = arr[before];
                before -= k;
            }

            arr[before + k] = after;
        }
        kIndex--;
        printArray(arr);
    }
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

    ShellSort(arr);
    return 0;
}