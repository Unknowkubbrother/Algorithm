#include <bits/stdc++.h>
using namespace std;

void Prim(vector<vector<pair<int,int>>> &adjList,vector<int> &dist,vector<int> &parent,int startVertex){
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;

    int size = adjList.size();
    vector<bool> visit(size,false);

    pq.push({0,startVertex});
    dist[startVertex] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visit[u] = true;

        for(int i=0;i<adjList[u].size();i++){
            int weight = adjList[u][i].first;
            int nextVertex = adjList[u][i].second;

            if (!visit[nextVertex] && weight > dist[nextVertex]){
                dist[nextVertex] = weight;
                pq.push({dist[nextVertex],nextVertex});
                parent[nextVertex] = u;
            }
        }
    }


}

int findminDistancePath(vector<int> &parent,vector<int> &dist,int find,int minPath = INT_MAX){
    if (parent[find] == -1){
        return minPath;
    }
    return findminDistancePath(parent,dist,parent[find],dist[find]<minPath?dist[find]:minPath);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adjList(n+1);

    for (int i = 0; i < m; i++)
    {
        int src, dest, weight;
        cin>>src>>dest>>weight;
        adjList[src].push_back({weight,dest});
        adjList[dest].push_back({weight,src});
    }

    int size = adjList.size();

    int start,end,people;
    cin>>start>>end>>people;

    vector<int> dist(size,0);
    vector<int> parent(size,-1);

    Prim(adjList,dist,parent,start);

    int numberpossibleGo = findminDistancePath(parent,dist,end);

    int round = 0;
    while(people>0){
        people++;
        round++;
        people-=numberpossibleGo;
    }

    cout<<round;

    return 0;
}

// 7 10
// 1 2 30
// 1 3 15
// 1 4 10
// 2 4 25
// 2 5 60
// 3 4 40
// 4 7 35
// 3 6 20
// 5 7 20
// 7 6 30
// 1 7 99

// 7 10 
// 1 2 30 
// 1 3 15 
// 1 4 10 
// 2 4 25 
// 2 5 60 
// 3 4 40 
// 4 7 35 
// 3 6 20 
// 5 7 20 
// 7 6 30
// 1 4 8