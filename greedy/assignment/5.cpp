#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct
{
    int start;
    int end;
} list;

bool compare(list a, list b)
{
    return (a.end - a.start) > (b.end - b.start);
}

void printArr(vector<list> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<"("<<arr[i].start<<","<<arr[i].end<<") ";
    }
}

void ManageRoom(vector<list> &timeLine, queue<list> room[], int k)
{
    int Activity = 0;
    for (int i = 0; i < timeLine.size(); i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (room[j].empty() || room[j].back().end <= timeLine[i].start)
            {
                room[j].push(timeLine[i]);
                Activity++;
                break;
            }
        }
    }

    cout << Activity << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<list> timeLine(n);
    queue<list> room[k];
    for (int i = 0; i < n; i++)
    {
        cin >> timeLine[i].start >> timeLine[i].end;
    }

    sort(timeLine.begin(), timeLine.end(), compare);


    ManageRoom(timeLine, room, k);

    return 0;
}

// 10 3 
// 1 4 
// 3 5 
// 0 6 
// 5 7 
// 3 8 
// 5 9 
// 6 10 
// 8 11 
// 8 12 
// 2 13