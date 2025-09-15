#include <stdio.h>
// power using Recursion
int p(int a, int b){
    if (b == 0){
        return 0;
    }
    return a * p(a,b-1);
    
}
int main(){
    int a = p(2,0);
    printf("%d",a);
}