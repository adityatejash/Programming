// Transpose of Matrix

#include <iostream>
using namespace std;

void insertingvalues(int r, int c, int Matrix[][10]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << "Enter Element Number " << i << j << ": " ;
            cin >> Matrix[i][j];
        }
    }
}

void printingmatrix(int r, int c, int Matrix[][10]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << Matrix[i][j] << " " ;
        }
        cout << "\n" ;
    }
}

void Transpose(int r, int c, int Matrix[][10]){
    for (int i=0; i<c; i++){
        for (int j=0; j<r; j++){
            cout << Matrix[j][i] << " ";
        }
        cout << "\n" ;
    }
}

int main(){
    int r, c;
    
    cout << "Enter Rows and Columns of a Matrix: " ;
    cin >> r >> c;

    int Matrix[10][10] ;

    insertingvalues(r, c, Matrix);
    printingmatrix(r, c, Matrix);

    cout << "Transpose of Matrix is:- " << endl;
    Transpose(r, c, Matrix);
}