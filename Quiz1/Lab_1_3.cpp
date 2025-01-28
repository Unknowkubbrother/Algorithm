#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> in(n);
    vector<int> out(n);

    for(int i=0;i<n;i++){
        cin>>in[i];
    }

    for(int i=0;i<n;i++){
        cin>>out[i];
    }

    int maxTime = 1000;
    vector<int> timeLine(maxTime + 1,0);

    for(int i=0;i<n;i++){
        timeLine[in[i]]++;
        timeLine[out[i] + 1]--;
    }

    int currentStudent = 0;
    int maxStudent = 0;
    int startTime,endTime;
    startTime = endTime = -1;

    for(int time = 0;time<=maxTime;time++){
        currentStudent += timeLine[time];

        if (currentStudent > maxStudent){
            maxStudent = currentStudent;
            startTime = time;
            endTime = time;
        }else if (currentStudent == maxStudent && (endTime == -1 || time == endTime + 1)){
            endTime = time;
        }

    }

    cout << startTime << " " << endTime << " " << maxStudent << endl;

    return 0;
}

