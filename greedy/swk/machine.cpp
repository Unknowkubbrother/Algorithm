#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int in;
    int out;
} room;

bool compare(room a,room b){
    return a.in <= b.in;
}

void printArr(room arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i].in<<" "<<arr[i].out<<endl;
    }
}

int main(){
    room arr[] = {
        {1,4},
        {3,5},
        {0,6},
        {5,7},
        {3,8},
        {5,9},
        {6,10},
        {8,11},
        {8,12},
        {2,13}
    };
    queue<room> q;

    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr,arr+n,compare);

    // printArr(arr,n);

    int machine = 0;

    q.push(arr[0]);
    machine++;
    for(int i=1;i<n;i++){
        while(!q.empty() && q.back().out <= arr[i].in){
            q.pop();
        }
        q.push(arr[i]);
        machine = max(machine,(int)q.size());
    }

    cout<<machine;
    


    return 0;
}