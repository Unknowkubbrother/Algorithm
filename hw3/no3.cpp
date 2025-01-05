#include <iostream>
using namespace std;

int sumPowerN(int n){
    if (n > 1){
        return (n*n*n) + sumPowerN(n-1);
    }else {
        return 1;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<sumPowerN(n)<<endl;
    return 0;
}