#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

long Multiple(long A, long B){
    long tempA = A;
    long tempB = B;
    long maxRangeDigit = max(to_string(A).size(), to_string(B).size());
    if (maxRangeDigit <= 1){
        return A * B;
    }
    if (maxRangeDigit % 2 != 0){
        maxRangeDigit++;
    }
    long m = maxRangeDigit / 2;
    long a, b, c, d;
    a=b=c=d=0;
    for(int i = 0; i < m; i++){
        b+=A%10*pow(10, i);
        d+=B%10*pow(10, i);
        A/=10;
        B/=10;
    }
    for(int i = m; i < maxRangeDigit; i++){
        a+=A%10*pow(10, i-m);
        c+=B%10*pow(10, i-m);
        A/=10;
        B/=10;
    }
    long ac = Multiple(a, c);
    long bd = Multiple(b, d);
    long Muladbc = Multiple(a+b, c+d);
    cout<<tempA<<"*"<<tempB<<"=";
    cout<<ac<<"10^"<<maxRangeDigit<<"+("<<Muladbc<<"-"<<ac<<"-"<<bd<<")*10^"<<m<<"+"<<bd<<endl;
    return ac*pow(10, maxRangeDigit)+((Muladbc-ac-bd)*pow(10, m))+bd;
}

int main(){
    long a = 4568;
    long b = 3275;
    cout << Multiple(a, b) << endl;
    return 0;
}