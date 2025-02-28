#include <bits/stdc++.h>

using namespace std;

int offsetRow[] = {0, 0, 1, -1};
int offsetCol[] = {1, -1, 0, 0};

int bfs(vector<vector<char>> &adjMatrix,int startRow,int startCol){
    queue<pair<int,int>> q;

    int n = adjMatrix.size();
    int m = adjMatrix[0].size();

    char oldColor = adjMatrix[startRow][startCol];
    q.push({startRow,startCol});

    int count = 1;

    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();

        int row = u.first;
        int col = u.second;
        adjMatrix[startRow][startCol] = 'G';

        for(int i = 0;i<4;i++){
            int newRow = row + offsetRow[i];
            int newCol = col + offsetCol[i];
            
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)
            {
                continue;
            }
        
            char newColor = adjMatrix[newRow][newCol];
        
            if (newColor != oldColor)
            {
                continue;
            }
        
            count++;
            q.push({newRow,newCol});
        }
    }

    return count;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > adjMatrix(n,vector<char>(m,'L'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adjMatrix[i][j];
        }
    }
    int startRow,startCol;
    cin>>startRow>>startCol;
    cout<<bfs(adjMatrix,startRow-1,startCol-1);
}

// 6 6 
// LLWWLW 
// LLWWLL 
// WLLWWW 
// WWLWLL 
// WWLWLW 
// WLLWWW 
// 6 6
