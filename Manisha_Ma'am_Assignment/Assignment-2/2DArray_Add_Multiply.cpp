// Addition and Multiplication of 2d Array. 

#include <iostream>
using namespace std;

void insertingvalues(int Matrix[2][2]){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            Matrix[i][j] = 0;
            cout << "Enter element number " << i << j << ": ";
            cin >> Matrix[i][j] ;
        }
    }
}
void addMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[2][2], B[2][2];
    int result[2][2];
    
    cout << "Matrix A:" << endl;
    insertingvalues(A);
    cout << "Matrix B:" << endl;
    insertingvalues(B);

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "Matrix B:" << endl;
    printMatrix(B);

    addMatrices(A, B, result);
    cout << "Sum of matrices A and B:" << endl;
    printMatrix(result);

    multiplyMatrices(A, B, result);
    cout << "Product of matrices A and B:" << endl;
    printMatrix(result);

    return 0;
}
