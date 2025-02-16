#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

typedef struct{
    int start;
    int end;
} line;

bool compare(line a,line b){
    return a.start <= b.start && a.end <= b.end;    
}

void printArr(vector<line> arr){
    for(int i=0;i<arr.size();i++){
        cout<<"("<<arr[i].start<< ","<<arr[i].end<<"),";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<line> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
    }
    int finalStart,finalEnd;
    cin>>finalStart>>finalEnd;

    sort(arr.begin(),arr.end(),compare);

    // printArr(arr);

    int countLine = 0;

    vector<line> result;

    int i = 0;

    while(i<n){
        int TempMin = arr[i].end;
        int Longest = 0;
        int idx = -1;
        for(int j=i;j<n;j++){
            if (arr[j].end <= finalEnd){
                int diff = abs(arr[j].start - finalStart);
                int difflong = abs(arr[j].end - arr[j].start);

                if (diff < arr[i].end && diff <= TempMin && difflong > Longest){
                    Longest = difflong;
                    TempMin = diff;
                    idx = j;
                }
            }
        }

        
        if (idx != -1){
            result.push_back(arr[idx]);
            countLine++;
            i = idx + 1;
            finalStart = arr[idx].end;
        }else{
            i++;
        }
    }

    cout<<countLine<<endl;

    for(int i=0;i<countLine;i++){
        cout<<result[i].start<<" "<<result[i].end<<endl;
    }

    return 0;
}