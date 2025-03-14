#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int idx;
    int W;
    int V;
} inventory;

bool compare(inventory a, inventory b)
{
    return (double)a.V / a.W > (double)b.V / b.W;
}

int main()
{
    int n;
    double k;
    cin >> n >> k;
    vector<inventory> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].idx = i;
        cin >> arr[i].W;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].V;
    }

    sort(arr.begin(), arr.end(), compare);

    vector<double> result(n, 0.00);
    double sum = 0;
    int i = 0;
    while (i < n && arr[i].W <= k)
    {
        k -= arr[i].W;
        result[arr[i].idx] = 1.00;
        sum += arr[i].V;
        i++;
    }

    double fraction = k / arr[i].W;
    result[arr[i].idx] = fraction;
    sum += fraction * arr[i].V;

    for (int i = 0; i < result.size(); i++)
    {
        cout << fixed << setprecision(2) << result[i] << " ";
    }

    cout << endl;

    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}