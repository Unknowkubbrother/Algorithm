#include <iostream>
using namespace std;

int countSolution = 0;

int gcdcon(int x,int y){
    if(y==0){
        return x;
    }
    return gcdcon(y,x%y);
}

int gcd(int arr[],int l,int r){
    if(l>=r){
        return arr[l];
    }
    int m=(l+r)/2;
    // countSolution++;
    countSolution++;
    int r1=gcd(arr,l,m);
    int r2=gcd(arr,m+1,r);
    return gcdcon(r1,r2);
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = gcd(arr, 0, n-1);
    cout << "GCD of the array is: " << result << endl;
    cout << "Number of solutions: " << countSolution << endl;
    return 0;
}