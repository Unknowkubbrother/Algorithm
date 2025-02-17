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

int main(){
    int n,m;
    cin>>n>>m;

    vector< vector<int> > adjList(n);

    for(int i=0;i<m;i++){
        int src,dest;
        cin>>src>>dest;
        adjList[src-1].push_back(dest-1);
    }

    for(int i=0;i<n;i++){
        cout<<"i : "<<i+1<<" => ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]+1<<" ";
        }
        cout<<endl;
    }
    bfs(adjList);


}