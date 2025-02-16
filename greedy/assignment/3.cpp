#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    double in;
    double out;
} train;

bool compare(train a, train b) {
    return a.in < b.in;
}

int main() {
    int n;
    cin >> n;
    vector<train> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].in >> arr[i].out;
    }

    sort(arr.begin(), arr.end(), compare);

    vector<double> v;
    int stationCount = 0;

    for (int i = 0; i < n; i++) {
        while (!v.empty() && v.front() <= arr[i].in) {
            v.erase(v.begin());
        }
        v.push_back(arr[i].out);
        sort(v.begin(), v.end());
        stationCount = max(stationCount, (int)v.size());
    }

    cout << stationCount << endl;

    return 0;
}
