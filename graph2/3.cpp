#include <bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<pair<int, int>>> &adjList, vector<int> &dist, int start)
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

            if (!visit[nextVertex] && dist[temp] + weight < dist[nextVertex])
            {
                dist[nextVertex] = dist[temp] + weight;
                pq.push({dist[nextVertex], nextVertex});
            }
        }
    }
}


typedef struct
{
    int m;
    int s;
    int t;
} network;

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

        adjList[i].resize(n);

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
        int start = sendList[i].s;
        int end = sendList[i].t;
        if (sendList[i].m > 0){
            vector<int> dist(size, INT_MAX);
            Dijkstra(adjList[i], dist, start);
            cout<<dist[end]<<"\n";
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}