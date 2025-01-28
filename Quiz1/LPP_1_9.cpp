#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    int count = 0;

    while(n > 0){
        int temp = n%2;
        if (temp == 1){
            count++;
        }
        n/=2;
    }


    cout<<count<<endl;




    return 0;
}