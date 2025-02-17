#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;

    int count = 0;
    while (m > 0 && n > 0) {
        if (m < n) {
            swap(m, n);
        }
        count += m / n;
        m %= n;
    }

    cout << count << endl;
    return 0;
}