#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));

    int MaxEnd = INT_MIN;

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        MaxEnd = max(max(arr[i][0],arr[i][1]),MaxEnd);
    }

    vector<int> timeLine(MaxEnd + 1,0);
    
    for(int i = 0;i<arr.size();i++){
        timeLine[arr[i][0]]++;
        timeLine[arr[i][1]+1]--;
    }

    int start,end,current,maxPeople;
    start = end = -1;
    current = maxPeople = 0;


    for(int time=0;time<timeLine.size();time++){
        current += timeLine[time];

        if (current > maxPeople){
            maxPeople = current;
            start = time;
            end = time;
        }else if (current == maxPeople && (end == -1 || time == end + 1)){
            end = time;
        }
    }

    cout<<start<<" "<<end<<" "<<maxPeople<<endl;



    return 0;
}
