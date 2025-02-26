#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>
using namespace std;

void Dijkstra(vector< vector< pair<int, int> > > &adjList, vector<int> &dist, int start) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

    int size = adjList.size();
    vector<bool> visit(size, false);

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int temp = pq.top().second;
        pq.pop();
        visit[temp] = true;

        for (int i = 0;i<adjList[temp].size();i++) {
            int nextVertex = adjList[temp][i].first;
            int weight = adjList[temp][i].second;

            if (!visit[nextVertex] && dist[temp] + weight < dist[nextVertex]) {
                dist[nextVertex] = dist[temp] + weight;
                pq.push(make_pair(dist[nextVertex], nextVertex));
            }
        }
    }
}

int main() {
    vector< vector< pair<int, int> > > adjList(10000);

    int maxSize = INT_MIN;
    int src, dest;
    do {
        cin >> src >> dest;
        if (src == 0 && dest == 0) {
            break;
        }
        maxSize = max(maxSize, max(src, dest));
        adjList[src].push_back(make_pair(dest, 1));
    } while (src != 0 && dest != 0);

    adjList.resize(maxSize + 1);

    int size = adjList.size();

    int count = 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        vector<int> dist(size, INT_MAX);
        Dijkstra(adjList, dist, i);
        for (int j = 0; j < size; j++) {
            if (dist[j] != INT_MAX && j != i) {
                sum += dist[j];
                count++;
            }
        }
    }

    cout << fixed << setprecision(3) << sum / (double)count;
    return 0;
}
// 1 2  2 4  1 3  3 1  4 3  0 0