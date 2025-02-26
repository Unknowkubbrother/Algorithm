#include <iostream>
#include <vector>
using namespace std;

void bfs(vector< vector<int> > &adjList){
    int root;
    cin>>root;
    vector<bool> visit(adjList.size(),false);
    queue<int> q;
    q.push(root-1);
    visit[root-1] = true;
    while(!q.empty()){
        int temp = q.front();
        cout<<temp+1<<endl;
        q.pop();
        for(int i=0; i < adjList[temp].size(); i++){
            if (!visit[adjList[temp][i]]){
                q.push(adjList[temp][i]);
                visit[adjList[temp][i]] = true;
            }
        }
    }
}

void dfs(vector< vector<int> > &adjList, vector<bool> &visit, int startVertex){
    visit[startVertex] = true;
    cout<<startVertex<<" ";

    for(int i = 0; i < adjList[startVertex].size(); i++){
        int nextVertex = adjList[startVertex][i];
        if (!visit[nextVertex]){
            dfs(adjList, visit, nextVertex);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector< vector<int> > adjList(n);

    for(int i=0;i<m;i++){
        int src,dest;
        cin>>src>>dest;
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    // for(int i=0;i<n;i++){
    //     cout<<"i : "<<i<<" => ";
    //     for(int j=0;j<adjList[i].size();j++){
    //         cout<<adjList[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // bfs(adjList);
    vector<bool> visit(n,false);
    dfs(adjList,visit,2);


}