#include <stdio.h>
#include <stdlib.h>
// Recursion
int m (int a, int b){
    if (b > 1){
        return a + m(a,b-1);
    }
}

int main(){
    int a = m(5,3);
    printf("%d",a);
}