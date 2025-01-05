#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<pair<int , int>> v;
    for(int i = 0; i < n; i++){
        int in , out;
        cin >> in >> out ;
        v.push_back({in , 1});
        v.push_back({out , -1});
    }
    sort(v.begin(), v.end());
    int count = 0 , max = 0 , first = 0 , second = 0;
    for(auto e : v){
        if(e.second == 1){
            count++;
            if(max < count){
                max = count;
                first = e.first;
            }
        }else{
            count--;
            if(max - 1 == count){
                second = e.first;
            }
        }
    }
    cout << first << " " << second << " " <<  max;
}