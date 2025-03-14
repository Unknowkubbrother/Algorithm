#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent,int find){
    if (parent[find] == -1){
        return find;
    }
    return findParent(parent,parent[find]);
}

bool is_cycle(vector<int> &parent,int u,int v){
    int x = findParent(parent,u);
    int y = findParent(parent,v);
    return x == y;
}

void union1(vector<int> &parent,int u,int v){
    int x = findParent(parent,u);
    int y = findParent(parent,v);
    parent[x] = y;
}


void kurskal(vector<vector<pair<int,int>>> &adjList){
    int size = adjList.size();
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    for(int i=0;i<size;i++){
        for(int j=0;j<adjList[i].size();j++){
            pq.push({adjList[i][j].first,{i,adjList[i][j].second}});
        }    
    }

    vector<int> parent(size,-1);
    int flag = 0;
    int j = 0;
    while(j < size-2){
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();

        if (!is_cycle(parent,u,v)){
            union1(parent,u,v);
            j++;
            flag += weight-1;
        }
    }

    cout<<flag;
}


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adjList(n+1);

    for(int i=0;i<m;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        adjList[src].push_back({weight,dest});
        adjList[dest].push_back({weight,src});
    }


    kurskal(adjList);
    return 0;
}

// 6 9 
// 1 2 8 
// 1 6 6 
// 2 6 6 
// 2 3 6 
// 2 4 9 
// 2 5 7 
// 3 4 5 
// 4 5 5 
// 5 6 8