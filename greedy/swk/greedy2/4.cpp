#include <iostream>
#include <vector>
using namespace std;

bool comparePlus(int a,int b){
    return a >= b;
}

int main(){
    int n;
    cin>>n;
    vector< vector<int> > arr1(n);
    vector< vector<int> > arr2(n);
    vector<int> K(n);

    for(int i=0;i<n;i++){
        int size;
        cin>>size;
        arr1[i].resize(size);
        arr2[i].resize(size);

        for(int j=0;j<size;j++){
            cin>>arr1[i][j];
        }

        for(int j=0;j<size;j++){
            cin>>arr2[i][j];
        }

        cin>>K[i];

        sort(arr1[i].begin(),arr1[i].end());
        sort(arr2[i].begin(),arr2[i].end(),comparePlus);
    }

    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<arr1[i].size();j++){
            if (arr1[i][j] + arr2[i][j] < K[i]){
                flag = true;
                break;
            }
        }
        if (!flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}