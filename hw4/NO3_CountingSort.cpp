#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void CountingSort(vector<int> &arr){

    int max = INT_MIN;
    for(int i=0;i<arr.size();i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    vector<int> count(max+1, 0);

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }

    int k = 0;

    for(int i=0;i<count.size();i++){
        for(int j=0;j<count[i];j++){
            arr[k++] = i;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    CountingSort(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

// 9
// 551 220 551 912 81 32 745 613 109