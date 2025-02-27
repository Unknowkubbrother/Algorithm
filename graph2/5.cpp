#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        dist[src - 1][dest - 1] = weight;
        dist[dest - 1][src - 1] = weight;
    }

    int size = dist.size();

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// 7 10
// 1 2 30
// 1 3 15
// 1 4 10
// 2 4 25
// 2 5 60
// 3 4 40
// 4 7 35
// 3 6 20
// 5 7 20
// 7 6 30
// 1 7 99