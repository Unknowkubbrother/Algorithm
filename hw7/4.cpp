#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector< vector<int> > &adjList, vector<bool> &visit, int startVertex, int m, int &count){
    if (m < 0) return;

    visit[startVertex] = true;
    count++;

    for(int i = 0; i < adjList[startVertex].size(); i++){
        int nextVertex = adjList[startVertex][i];
        if (!visit[nextVertex]){
            dfs(adjList, visit, nextVertex, m - 1, count);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > adjList(n);

    int src, dest;
    while (true) {
        cin >> src >> dest;
        if (src == 0 && dest == 0) {
            break;
        }
        adjList[src - 1].push_back(dest - 1);
    }

    for(int i = 0; i < adjList.size(); i++){
        sort(adjList[i].begin(), adjList[i].end());
    }

    int k, m;
    cin >> k >> m;
    int count = 0;

    vector<bool> visit(adjList.size(), false);
    dfs(adjList, visit, k - 1, m, count);

    cout << n - count;

    return 0;
}

// 7 
// 1 2  
// 1 4  
// 1 5  
// 2 3 
// 2 5 
// 3 1 
// 3 6 
// 3 7 
// 4 5 
// 5 4 
// 6 5 
// 6 7
// 0 0 
// 1 2