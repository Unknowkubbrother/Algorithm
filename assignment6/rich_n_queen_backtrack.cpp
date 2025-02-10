#include <iostream>
#include <cmath>

using namespace std;
int solutionCount=0;
void permute(int arr[],int s,int e){
    int check=0;
    for(int j=0;j<s-1;j++){
        if(abs((s-1)-j)==abs(arr[(s-1)]-arr[j])||arr[(s-1)]==arr[j]){
            check=1;
        }
    }
    if(check==1){
        return;
    }
    
    if(s==e){
        int check=0;
        for(int j=0;j<s;j++){
            if(abs(s-j)==abs(arr[s]-arr[j])||arr[s]==arr[j]){
                check=1;
            }
        }
        if(check==1){
            return;
        }
        for(int i=0;i<=e;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=s;i<=e;i++){
        swap(arr[s],arr[i]);
        solutionCount++;
        permute(arr,s+1,e);
        swap(arr[s],arr[i]);
    }
    
}

int main(){
    int n=16;
    int arr[] = {0, 1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15};
    permute(arr,0,n-1);
    cout<<solutionCount<<endl;
}