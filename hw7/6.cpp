#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void bfs(int root, const vector< vector<int> > &adjList, vector<int> &dist) {
    vector<bool> visit(adjList.size(), false);
    queue<int> q;
    q.push(root);
    visit[root] = true;
    dist[root] = 0;
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < adjList[temp].size(); i++) {
            if (!visit[adjList[temp][i]]) {
                q.push(adjList[temp][i]);
                visit[adjList[temp][i]] = true;
                dist[adjList[temp][i]] = dist[temp] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > adjList(n);

    for (int i = 0; i < m; i++) {
        int src, dest;
        cin >> src >> dest;
        // if (src != dest) {
            adjList[src - 1].push_back(dest - 1);
            adjList[dest - 1].push_back(src - 1);
        // }
    }

    int shortest = INT_MAX;
    int result = -1;

    for (int i = 0; i < n; i++) {
        vector<int> dist(n, 0);
        bfs(i, adjList, dist);
        int sum = 0;
        for (int j = 0; j < dist.size(); j++) {
            sum += dist[j];
        }
        
        if (sum < shortest) {
            shortest = sum;
            result = i + 1;
        }
    }

    cout << result << endl;

    return 0;
}
