#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f, n;
    cin >> f >> n;
    vector<int> existHospital(f);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < f; i++)
    {
        cin >> existHospital[i];
    }

    for (int i = 0; i < n; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        dist[src][dest] = weight;
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

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if (dist[i][j] != INT_MAX && i != ){
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}