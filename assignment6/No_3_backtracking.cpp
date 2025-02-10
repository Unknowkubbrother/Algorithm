#include <iostream>
#include <vector>
using namespace std;

int V[] = {1, 2, 3, 4};
int p = 2;

void subset1(int x[], int l, int r, int sumV, int &countSol, int &countRe)
{
    if (sumV > p)
    {
        return;
    }
    countRe++;


    if (l == r)
    {
        countSol++;
        if (sumV != p)
        {
            return;
        }

        for (int i = 1; i <= r; i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
        return;
    }

    x[l + 1] = 1;
    sumV += V[l];
    subset1(x, l + 1, r, sumV, countSol, countRe);
    x[l + 1] = 0;
    sumV -= V[l];
    subset1(x, l + 1, r, sumV, countSol, countRe);
}

int main()
{
    int n = 4;
    int x[n + 1];
    int countSol = 0;
    int countRe = 0;
    subset1(x, 0, n, 0, countSol, countRe);
    cout << countSol << " " << countRe << endl;
    return 0;
}