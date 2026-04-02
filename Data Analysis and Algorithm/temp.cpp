#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int winner (vector<char>& vec){
    if ((vec[0] == vec[1] == vec[2]) ||
        (vec[3] == vec[4] == vec[5]) || 
        (vec[6] == vec[7] == vec[8]) ||
        (vec[0] == vec[4] == vec[8]) ||
        (vec[2] == vec[4] == vec[6]) ||
        (vec[0] == vec[3] == vec[6]) ||
        (vec[1] == vec[4] == vec[7]) ||
        (vec[2] == vec[5] == vec[8])) {
        return 1;
    }
    return 0;
}

void input (vector<char>& vec, int index) {
    cin >> vec[index];
}

int main(){
    char player1 = 'X', player2 = 'O';
    
    
    vector<char>& vec;
    while (winner(vec)){

    }
}





// 0 1 2
// 3 4 5
// 6 7 8