#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of wires needed
void findMinimumWires(int targetLength, const vector<int>& wireLengths) {
    int minWires = INT_MAX;

    // Loop through all possible combinations
    for (int i = 0; i <= targetLength / wireLengths[0]; ++i) {
        for (int j = 0; j <= targetLength / wireLengths[1]; ++j) {
            for (int k = 0; k <= targetLength / wireLengths[2]; ++k) {
                int totalLength = i * wireLengths[0] + j * wireLengths[1] + k * wireLengths[2];
                if (totalLength == targetLength) {
                    int totalWires = i + j + k;
                    minWires = min(minWires, totalWires);
                }
            }
        }
    }

    if (minWires == INT_MAX) {
        cout << "ไม่สามารถสร้างความยาวที่ต้องการได้" << endl;
    } else {
        cout << "จำนวนสายไฟที่น้อยที่สุดคือ: " << minWires << endl;
    }
}

int main() {
    // Input data
    int targetLength = 10;
    vector<int> wireLengths = {1, 3, 5};

    // Find the minimum number of wires
    findMinimumWires(targetLength, wireLengths);

    return 0;
}
