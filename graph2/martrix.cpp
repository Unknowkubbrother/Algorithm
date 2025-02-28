#include <bits/stdc++.h>
using namespace std;

void Dijkstra(vector<vector<int>> &adjMatrix,vector<int> &dist,vector<int> &parent,int startVertex){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

    int size = adjMatrix.size();
    vector<bool> visit(size);
    pq.push({0, startVertex});
    dist[startVertex] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visit[u] = true;

        for(int i=0;i<adjMatrix[u].size();i++){
            int weight = adjMatrix[u][i];

            if (weight && !visit[i] && dist[u] + weight < dist[i]){
                dist[i] =  dist[u] + weight;
                pq.push({dist[i],i});
                parent[i] = u;
            }
        }

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjMartrix(n+1, vector<int>(n+1, 0));

    for(int i=0;i<m;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjMartrix[src][dest] = weight;
    }

    int size = adjMartrix.size();
    vector<int> dist(size,INT_MAX);
    vector<int> parent(size,-1);
    Dijkstra(adjMartrix,dist,parent,1);


    for(int i=0;i<parent.size();i++){
        if (dist[i] != INT_MAX){
            cout<<dist[i]<<" ";
        }else{
            cout<<"INF ";
        }
    }

    cout<<endl;

    for(int i=0;i<parent.size();i++){
        cout<<parent[i]<<" ";
    }



    return 0;
}

// 5 6
// 1 0 5
// 4 0 1
// 4 3 2
// 3 2 6
// 2 1 2
// 0 3 9

// 12 20
// 1 2 3
// 1 3 5
// 1 4 4
// 2 6 6
// 2 5 3
// 3 4 2
// 4 5 1
// 5 6 2
// 3 7 4
// 4 8 5
// 5 9 4
// 6 10 5
// 7 8 3
// 8 9 6
// 9 10 3
// 7 11 6
// 8 11 7
// 9 12 5
// 10 12 9
// 11 12 8