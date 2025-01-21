#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> AddMatrix(vector<vector<int>> matrixA, vector<vector<int>> matrixB){
    int n = matrixA.size();
    vector<vector<int>> matrixC(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return matrixC;
}

vector<vector<int>> SubtractMartix(vector<vector<int>> matrixA, vector<vector<int>> matrixB){
    int n = matrixA.size();
    vector<vector<int>> matrixC(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return matrixC;
}

vector<vector<int>> MultiplyMatrix(vector<vector<int>> matrixA, vector<vector<int>> matrixB){
    int n = matrixA.size();
    vector<vector<int>> matrixC(n, vector<int>(n));
    if (n == 1){
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return matrixC;
    }
    int m=n/2;
    vector<vector<int>> A11(m, vector<int>(m)), A12(m, vector<int>(m)), A21(m, vector<int>(m)), A22(m, vector<int>(m));
    vector<vector<int>> B11(m, vector<int>(m)), B12(m, vector<int>(m)), B21(m, vector<int>(m)), B22(m, vector<int>(m));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            A11[i][j] = matrixA[i][j];
            A12[i][j] = matrixA[i][j+m];
            A21[i][j] = matrixA[i+m][j];
            A22[i][j] = matrixA[i+m][j+m];
            B11[i][j] = matrixB[i][j];
            B12[i][j] = matrixB[i][j+m];
            B21[i][j] = matrixB[i+m][j];
            B22[i][j] = matrixB[i+m][j+m];
        }
    }
    vector<vector<int>> M1 = MultiplyMatrix(AddMatrix(A11, A22), AddMatrix(B11, B22));
    vector<vector<int>> M2 = MultiplyMatrix(AddMatrix(A21, A22), B11);
    vector<vector<int>> M3 = MultiplyMatrix(A11, SubtractMartix(B12, B22));
    vector<vector<int>> M4 = MultiplyMatrix(A22, SubtractMartix(B21, B11));
    vector<vector<int>> M5 = MultiplyMatrix(AddMatrix(A11, A12), B22);
    vector<vector<int>> M6 = MultiplyMatrix(SubtractMartix(A21, A11), AddMatrix(B11, B12));
    vector<vector<int>> M7 = MultiplyMatrix(SubtractMartix(A12, A22), AddMatrix(B21, B22));

    vector<vector<int>> C11 = AddMatrix(SubtractMartix(AddMatrix(M1, M4), M5), M7);
    vector<vector<int>> C12 = AddMatrix(M3, M5);
    vector<vector<int>> C21 = AddMatrix(M2, M4);
    vector<vector<int>> C22 = AddMatrix(SubtractMartix(AddMatrix(M1, M3), M2), M6);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            matrixC[i][j] = C11[i][j];
            matrixC[i][j+m] = C12[i][j];
            matrixC[i+m][j] = C21[i][j];
            matrixC[i+m][j+m] = C22[i][j];
        }
    }

    return matrixC;
}

void InputMatrix(vector<vector<int>> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cin >> arr[i][j];
        }
    }
}

void printMatrix(vector<vector<int>> arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrixA(n, vector<int>(n)), matrixB(n, vector<int>(n));
    InputMatrix(matrixA);
    InputMatrix(matrixB);

    vector<vector<int>> matrixC(n, vector<int>(n));
    matrixC = MultiplyMatrix(matrixA, matrixB);
    printMatrix(matrixC);
    return 0;
}