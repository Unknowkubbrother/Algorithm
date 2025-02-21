#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int root,vector< vector<int> > &adjList,vector<int> &parent){
    vector<bool> visit(adjList.size(),false);
    queue<int> q;
    q.push(root-1);
    visit[root-1] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i < adjList[temp].size(); i++){
            if (!visit[adjList[temp][i]]){
                q.push(adjList[temp][i]);
                visit[adjList[temp][i]] = true;
                parent[adjList[temp][i]] = temp;
            }
        }
    }
}

int SortedPath(vector<int> &parent,int find,int path){
    if (parent[find] == -1){
        return path;
    }
    return SortedPath(parent,parent[find],path+1);
}

int main(){
    int n;
    cin>>n;
    vector< vector<int> > adjList(n);
    vector<int> parent(n,-1);
    
    for(int i=0;i<n;i++){
        int num = -1;
        int idx;
        bool first = false;
        do{
            if (!first){
                int temp;
                cin>>temp;
                idx = temp-1;
                first = true;
            }else{
                cin>>num;
                if (num <= 0){
                    break;
                }
                adjList[idx].push_back(num-1); 
            }
        }while(num!=0);
    }

    int start,end;
    cin>>start>>end;

    bfs(start,adjList,parent);

    cout<<SortedPath(parent,end-1,0)<<endl;
}