#include <bits/stdc++.h>
using namespace std;

int main(){
    int f, n;
    cin >> f >> n;
    
    vector<bool> existHospital(n, false);
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < f; i++)
    {
        int exist;
        cin >> exist;
        existHospital[exist-1] = true;
    }

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        dist[src-1][dest-1] = weight;
        dist[dest-1][src-1] = weight;
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
        if (existHospital[i])
        {
            continue;
        }

        int minDist = INT_MAX;
        for (int j = 0; j < size; j++)
        {
            if (existHospital[j] && dist[i][j] != INT_MAX)
            {
                minDist = min(minDist, dist[i][j]);
            }
        }

        if (minDist > maxMinDist)
        {
            maxMinDist = minDist;
            bestPosition = i+1;
        }
    }

    cout << maxMinDist <<" "<<bestPosition;

    return 0;
}