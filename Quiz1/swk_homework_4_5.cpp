#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<int> intersec;
    vector<int> Union;
    int unionIdx = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n; j++)
        {
            if (B[j] == A[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {   
            flag = false;
            intersec.push_back(A[i]);
        }
        
        Union.push_back(A[i]);
        unionIdx++;
    }

    for(int i=0;i<n;i++){
        bool flag = false;
        for (int k = 0; k < unionIdx; k++)
        {
            if (B[i] == Union[k]){
                flag = true;
            }

        }

        if (!flag){
            Union.push_back(B[i]);
            unionIdx++;
        }
    }

    printArr(intersec);
    printArr(Union);

    return 0;
}