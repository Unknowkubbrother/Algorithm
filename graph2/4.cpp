#include <bits/stdc++.h>
using namespace std;

void Prim(vector<vector<pair<int, int>>> &adjList, vector<int> &dist, int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int size = adjList.size();
    vector<bool> visit(size, false);

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int temp = pq.top().second;
        pq.pop();
        visit[temp] = true;

        for (int i = 0; i < adjList[temp].size(); i++)
        {
            int nextVertex = adjList[temp][i].second;
            int weight = adjList[temp][i].first;

            if (!visit[nextVertex] && weight-1 < dist[nextVertex])
            {
                dist[nextVertex] = weight-1;
                pq.push({weight, nextVertex});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adjList(n + 1);

    int start = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int src, dest, weight;

        cin >> src >> dest >> weight;
        adjList[src].push_back({weight, dest});
        adjList[dest].push_back({weight, src});
        start = min(src, start);
    }

    int size = adjList.size();
    
    vector<int> dist(size, INT_MAX);
    Prim(adjList, dist, start);
    int sumFlag = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] != INT_MAX){
            sumFlag += dist[i];
        }
        
    }

    cout<<sumFlag;

    return 0;
}