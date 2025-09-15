#include <stdio.h>
// tower of hanoi 
void toh (int n, char a, char b, char c){
    if (n == 0){
        return;
    }
    toh(n-1, a, c, b);
    printf("Disk %d from %c --> %c\n ",n,a,c);
    toh(n-1, b, a, c);
}
int main(){
    toh(3,'A','B','C');
}