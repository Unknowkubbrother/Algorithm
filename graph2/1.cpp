#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void Prim( vector< vector< pair<int,int> > > &adjList,vector<int> &dist,vector<int> &parent,int start){
    priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;

    int size = adjList.size();
    vector<bool> visit(size,false);

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty()){
        int temp = pq.top().second;
        pq.pop();
        visit[temp] = true;

        for(int i=0;i<adjList[temp].size();i++){
            int nextVertex = adjList[temp][i].second;
            int weight = adjList[temp][i].first;

            if (!visit[nextVertex] && weight < dist[nextVertex]){
                dist[nextVertex] = weight;
                pq.push({weight,nextVertex});
                parent[nextVertex] = temp;
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int >>> adjList(n+1);

    int size = adjList.size();

    for(int i=0;i<m;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjList[src].push_back({weight,dest});
        adjList[dest].push_back({weight,src});
    }

    int start;
    cin>>start;

    vector<int> parent(size,-1);
    vector<int> dist(size,INT_MAX);
    Prim(adjList,dist,parent,start);


    int sum = 0;
    for(int i=0;i<dist.size();i++){
        if (dist[i] != INT_MAX){
            sum += dist[i];
        }
    }

    cout<<sum;

    return 0;
}

// 4 5 
// 1 2 2 
// 1 3 1 
// 1 4 4 
// 2 3 3 
// 3 4 5 
// 1

// 6 8
// 1 2 3
// 1 5 5
// 2 3 5
// 2 5 6
// 3 4 9
// 3 6 3
// 4 6 7
// 5 6 2
// 1