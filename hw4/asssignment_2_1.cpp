#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool prime(int n){
    if(n == 1){
        return true;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


void ShellSort(vector<int> &arr){
    vector<int> primeNumbers;
    for(int i=1;i<=arr.size();i++){
        if(prime(i)){
            primeNumbers.push_back(i);
        }
    }
    int kIndex = primeNumbers.size()-1;
    while(kIndex >= 0){
        int k = primeNumbers[kIndex];
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
    ShellSort(arr);
    return 0;
}