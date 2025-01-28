#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    int maxTime = 100000;
    vector<int> timeLine(maxTime + 1, 0);

    for(int i = 0; i < n; i++){
        timeLine[arr[i][0]]++;
        timeLine[arr[i][1] + 1]--;
    }

    int currentPeople = 0;
    int maxPeople = 0;
    int start = -1, end = -1;

    for(int time = 0; time <= maxTime; time++){
        currentPeople += timeLine[time];

        if (currentPeople > maxPeople){
            maxPeople = currentPeople;
            start = time;
            end = time;
        } else if (currentPeople == maxPeople && (end == -1 || time == end + 1)){
            end = time;
        }
    }

    cout << start << " " << end << " " << maxPeople << endl;

    return 0;
}
