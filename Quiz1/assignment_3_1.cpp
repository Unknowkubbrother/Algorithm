#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime(int n){
    if (n == 1){
        return true;
    }
    for(int i=2;i<=sqrt(n);i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void shellSort(vector<int> &arr){
    vector<int> numberPrime;
    for(int i=1;i<=arr.size();i++){
        if(prime(i)){
            numberPrime.push_back(i);
        }
    }
    int kIndex = numberPrime.size()-1;
    while (kIndex >= 0)
    {
        int k = numberPrime[kIndex];
        for(int i=k;i<arr.size();i++){
            int after = arr[i];
            int before = i-k;
            while(before >= 0 && arr[before] > after){
                arr[before + k] = arr[before];
                before -= k;
            }
             arr[before + k] = after;
        }
        kIndex--;
        printArray(arr);
    }
    

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    shellSort(arr);
    return 0;
}