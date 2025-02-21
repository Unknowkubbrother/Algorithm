#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector< vector<int> > &adjList, vector<bool> &visit, int startVertex, bool &cycle, int parent){
    visit[startVertex] = true;

    for(int i = 0; i < adjList[startVertex].size(); i++){
        int nextVertex = adjList[startVertex][i];
        if (!visit[nextVertex]){
            dfs(adjList, visit, nextVertex, cycle, startVertex);
        } else if (nextVertex != parent){
            cycle = true;
        }
    }
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

        sort(adjList[i].begin(),adjList[i].end());
    }

    bool cycle = false;
    vector<bool> visit(adjList.size(), false);
    dfs(adjList,visit,0,cycle,0);
    cout<<cycle<<endl;
}