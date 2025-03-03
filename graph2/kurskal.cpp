#include <bits/stdc++.h>
using namespace std;

int findParent(vector<int> &parent,int i){
    if (parent[i] == -1){
        return i;
    }
    return findParent(parent,parent[i]);
}

bool is_cycle(vector<int> &parent,int u,int v){
    int root1 = findParent(parent,u);
    int root2 = findParent(parent,v);

    return root1 == root2;
}

void union1(vector<int> &parent,int u,int v){
    int root1 = findParent(parent,u);
    int root2 = findParent(parent,v);
    parent[root1] = root2;
}

void kurskal(vector<vector<pair<int,int>>> &adjList){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>  pq;
    
    int size = adjList.size();

    for(int i=0;i<size;i++){
        for(int j=0;j<adjList[i].size();j++){
            pq.push({adjList[i][j].first,{i,adjList[i][j].second}});
        }
    }

    vector<int> parent(size,-1);

    int i=0;
    while(i < size-2){
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();

        if (!is_cycle(parent,u,v)){
            union1(parent,u,v);
            i++;
            cout<<"("<<u<<","<<v<<") "<<endl;
        }
    }
    
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

// 4 5 
// 1 2 2 
// 1 3 1 
// 1 4 4 
// 2 3 3 
// 3 4 5 

// 6 8
// 5 6 2
// 1 2 3
// 3 6 3
// 1 5 5
// 2 3 5
// 2 5 6
// 4 6 7
// 3 4 9