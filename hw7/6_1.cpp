#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void bfs(int root, const vector< vector<int> > &adjList, vector<int> &parent) {
    vector<bool> visit(adjList.size(), false);
    queue<int> q;
    q.push(root);
    visit[root] = true;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < adjList[temp].size(); i++) {
            if (!visit[adjList[temp][i]]) {
                q.push(adjList[temp][i]);
                visit[adjList[temp][i]] = true;
                parent[adjList[temp][i]] = temp;
            }
        }
    }
}

int SortedPath(vector<int> &parent,int find,int path){
    if (parent[find] == -1){
        return path;
    }
    return SortedPath(parent,parent[find],path+1);
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

    for(int i=0;i<n;i++){
        vector<int> parent(n,-1);
        bfs(i, adjList, parent);
        int sum = 0;
        for(int j=0;j<n;j++){
            int sorted = SortedPath(parent,j,0);
            sum+=sorted;
        }
        if (sum < shortest) {
            shortest = sum;
            result = i + 1;
        }
    }

    cout << result << endl;

    return 0;
}
