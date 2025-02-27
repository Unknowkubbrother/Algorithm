#include <bits/stdc++.h>
using namespace std;
int offsetRow[] = {0, 0, 1, -1};
int offsetCol[] = {1, -1, 0, 0};

void Dijkstra(vector<vector<int>> &adjMatrix, vector<vector<int>> &dist, pair<int, int> &start, pair<int, int> &end)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int n = adjMatrix.size();
    int m = adjMatrix[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));

    pq.push({0, start});
    dist[start.first][start.second] = 0;
    while (!pq.empty())
    {
        pair<int,int> u = pq.top().second;
        pq.pop();

        int row = u.first;
        int col = u.second;
        if (visit[row][col]) continue;
        visit[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + offsetRow[i];
            int newCol = col + offsetCol[i];

            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || (char)adjMatrix[newRow][newCol] == 'X')
            {
                continue;
            }

            int newDist = dist[row][col] + adjMatrix[newRow][newCol];
            if (newDist < dist[newRow][newCol])
            {
                dist[newRow][newCol] = newDist;
                pq.push({newDist, {newRow, newCol}});
            }
        }
    }
    cout << dist[end.first][end.second] - adjMatrix[end.first][end.second];
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> end;
    vector<vector<int>> adjMatrix(n, vector<int>(m,(int)'X'));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char charator;
            cin>>charator;
            if (charator == 'S')
            {
                adjMatrix[i][j] = (int)charator;
                start.first = i;
                start.second = j;
            }
            else if (charator == 'D')
            {
                adjMatrix[i][j] = (int)charator;
                end.first = i;
                end.second = j;
            }
            else if (charator >= '0' && charator <= '9')
            {
                adjMatrix[i][j] = (int)(charator - '0');
            }
            else
            {
                adjMatrix[i][j] = (int)charator;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    Dijkstra(adjMatrix, dist, start, end);
    return 0;
}

// 3 4
// X1S3
// 42X4
// X1D2