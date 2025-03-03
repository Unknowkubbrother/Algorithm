#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int m;
    int s;
    int t;
} network;

void Dijkstra(vector<vector<pair<int, int>>> &adjList, vector<int> &dist, int startVertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int size = adjList.size();

    vector<bool> visit(size, false);

    pq.push({0, startVertex});
    dist[startVertex] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visit[u] = true;

        for (int i = 0; i < adjList[u].size(); i++)
        {
            int nextVertex = adjList[u][i].second;
            int weight = adjList[u][i].first;

            if (!visit[nextVertex] && dist[u] + weight < dist[nextVertex])
            {
                dist[nextVertex] = dist[u] + weight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
}

int main()
{

    int c;
    cin >> c;
    vector<vector<pair<int, int>>> adjList[c];
    vector<network> sendList(c);

    for (int i = 0; i < c; i++)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        sendList[i].s = s;
        sendList[i].t = t;
        sendList[i].m = m;

        adjList[i].resize(n+1);

        for (int j = 0; j < m; j++)
        {
            int src, dest, w;
            cin >> src >> dest >> w;
            adjList[i][src].push_back({w, dest});
            adjList[i][dest].push_back({w, src});
        }
    }

    for (int i = 0; i < c; i++)
    {
        int size = adjList[i].size();
        int m = sendList[i].m;
        if (m > 0)
        {
            int start = sendList[i].s;
            int end = sendList[i].t;
            vector<int> dist(size, INT_MAX);
            Dijkstra(adjList[i], dist, start);
            cout << dist[end] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

// 2
// 2 1 0 1
// 0 1 100
// 3 3 2 0
// 0 1 100
// 0 2 200
// 1 2 50