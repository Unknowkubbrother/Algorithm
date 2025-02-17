#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector< vector<int> > &adjMatrix,vector<int> &parent){
    int root;
    cin>>root;
    vector<bool> visit(adjMatrix.size(),false);
    queue<int> q;
    q.push(root);
    visit[root] = true;
    while(!q.empty()){
        int temp = q.front();
        // cout<<temp<<endl;
        q.pop();
        for(int i=0; i < adjMatrix[temp].size(); i++){
            if (adjMatrix[temp][i] && !visit[i]){
                q.push(i);
                visit[i] = true;
                parent[i] = temp;
            }
        }
    }
}

void DFS(vector< vector<int > > &adjMatrix, vector<bool> &visit,int startVertex){
    cout<<startVertex<<" ";
    visit[startVertex] = true;

    for(int i=0;i<adjMatrix.size();i++){
        if (adjMatrix[startVertex][i] && !visit[i]){
            DFS(adjMatrix,visit,i);
        }
    }

}


int SortedPath(vector<int> &parent,int find,int path){
    if (find == -1){
        return path-1;
    }
    return SortedPath(parent,parent[find],path+1);
}


int main(){
    int n = 6;
    vector< vector<int> > adjMatrix(n,vector<int>(n,0));
    vector<int> parent(n,-1);

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][0] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[2][0] = 1;
    adjMatrix[2][3] = 1;
    adjMatrix[3][1] = 1;
    adjMatrix[3][2] = 1;
    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;
    adjMatrix[4][5] = 1;
    adjMatrix[5][4] = 1;

    // for(int i=0;i<adjMatrix.size();i++){
    //     cout<<"i : "<<i<<" => ";
    //     for(int j=0;j<adjMatrix[i].size();j++){
    //         cout<<adjMatrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    bfs(adjMatrix,parent);
    cout<<SortedPath(parent,5,0);

    // vector<bool> visit(n,false);
    // DFS(adjMatrix,visit,2);

}