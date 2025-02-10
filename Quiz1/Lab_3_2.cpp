#include <iostream>
using namespace std;

long power(long x,long n,int &count){
    if (n==0) return 1;
    if (n==1) return x;
    if (n%2==0){
        count++;
        return power(x*x,n/2,count);
    }else{
        count+=2;
        return power(x*x,n/2,count) * x;
    }
}

int main(){
    int a,n;
    cin>>a>>n;
    int count = 0;
    cout<<power(a,n,count)<<" "<<count;
    return 0;
}