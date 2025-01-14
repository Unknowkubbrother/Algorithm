#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];
    int down = l - 1;
    int up = r;
    while(true){
        do{
            ++down;
        }while(arr[down]< pivot);
        do{
            --up;
        }while(up >= 0 && arr[up]>pivot);
        if (down >= up){
            break;
        }
        swap(arr[down], arr[up]);
    }
    swap(arr[down], arr[r]);
    return down;
}

double quickselect(vector<int> &arr, int l, int r, int k){
    if (l > r){
        return -1;
    }else{
        int p = partition(arr, l, r);
        if (p == k){
            int temp = k;
            int sum = 0;
            while (temp < arr.size()){
                sum+=arr[temp];
                temp++;
            }
            double avg = sum/(double)(arr.size()-k);
            return avg;
        }else{
            if (p > k){
                return quickselect(arr, l, p-1, k);
            }else{
                return quickselect(arr, p+1, r, k);
            }
        }
    }
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    double avg = quickselect(arr, 0, arr.size()-1, arr.size() -k);
    cout<<fixed<<setprecision(2)<<avg;
    return 0;
}