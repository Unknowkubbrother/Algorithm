#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char> > &arr,int r,int c,int &sum){
    sum++;
    char oldColor = arr[r][c];
    arr[r][c]= (arr[r][c] == 'L') ? 'W' : 'L';
    if(r-1>=0 && arr[r-1][c]== oldColor){
        dfs(arr,r-1,c,sum);
    }
    if(r+1<arr.size()&&arr[r+1][c] == oldColor){
        dfs(arr,r+1,c,sum);
    }
    if(c-1 >=0 &&arr[r][c-1] == oldColor){
        dfs(arr,r,c-1,sum);
    }
    if(c+1 < arr[r].size()&&arr[r][c+1] == oldColor){
        dfs(arr,r,c+1,sum);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > arr(n,vector<char>(m,'L'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int r,c;
    cin>>r>>c;
    int sum=0;
    dfs(arr,r-1,c-1,sum);
    cout<<sum<<endl;
}