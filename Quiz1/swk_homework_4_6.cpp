#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    string text;
    int countText = 0;

    for(int i=0;i<n;i++){
        text += to_string(arr[i]);
        countText++;
    }

    vector<char> result;
    vector<int> countingNumber(countText+1,1);
    result.push_back(text[0]);
    for(int i=1;i<text.size();i++){
        bool flag = false;
        if (text[i] != text[i-1]){
            flag = true;
            result.push_back(text[i]);
        }
        if (!flag){
            int num = (int)(text[i]-'0');
            countingNumber[num]++;
        }
    }

    int squenceMax = INT_MIN;
    vector<int> duplicateNumber;
    int duplicateIdx = 0;
    for(int i=0;i<countingNumber.size();i++){
        if (countingNumber[i] != 1){
           squenceMax =  max(countingNumber[i],squenceMax);
        }
    }

    for(int i=0;i<countingNumber.size();i++){
         if (countingNumber[i] == squenceMax && squenceMax != INT_MIN){
            duplicateNumber.push_back(i);
            duplicateIdx++;
        }
    }

    if (squenceMax == INT_MIN){
        for(int i=0;i<result.size();i++){
            bool flag = false;
            int num = ((int)result[i]-'0'); 
            for(int j=0;j<duplicateIdx;j++){
                if (num == duplicateNumber[j]){
                    flag = true;
                }
            }
            if (!flag){
                duplicateNumber.push_back(num);
                duplicateIdx++;
            }
        }    
    }

    sort(duplicateNumber.begin(),duplicateNumber.end());

    for(int i=0;i<text.size();i++){
        cout<<text[i];
    }
    cout<<endl;
    for(int i=0;i<duplicateNumber.size();i++){
        cout<<duplicateNumber[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }

    return 0;
}

// 7
// 3 2 10 12 15 22 23