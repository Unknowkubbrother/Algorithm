#include <iostream>
using namespace std;

// ฟังก์ชันคำนวณ a^n และนับจำนวนการคูณ
long long power(int a, int n, int &count) {
    if (n == 0) {
        return 1; // a^0 = 1
    }
    
    long long half = power(a, n / 2, count); // คำนวณ a^(n/2)
    count++; // นับการคูณ
    
    if (n % 2 == 0) {
        return half * half; // ถ้า n เป็นเลขคู่
    } else {
        return a * half * half; // ถ้า n เป็นเลขคี่
    }
}

int main() {
    int a, n;
    cin >> a >> n;
    
    int count = 0; // ตัวแปรนับจำนวนการคูณ
    long long result = power(a, n, count); // คำนวณ a^n
    
    cout << result << " " << count << endl;
    return 0;
}