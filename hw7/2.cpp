#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

int main(){
    int n;
    cin>>n;
    vector< vector<int> > adjList(n);
    
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

        sort(adjList[i].begin(),adjList[i].end());
    }

    int k;
    cin>>k;
    vector<int> path(k);
    for(int i=0;i<k;i++){
        cin>>path[i];
    }

    for(int i=0;i<path.size();i++){
        vector<int> parent(n,-1);
        bfs(path[i],adjList,parent);
        bool flag = false;
        for(int j=0;j<parent.size();j++){
            if (path[i]-1 != j && parent[j] == -1){
                cout<<j+1<<" ";
                flag = true;
            }
        }
        if (!flag){
            cout<<"0";
        }
        cout<<endl;
    }
}