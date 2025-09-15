#include <stdio.h>
// Division using Recursion
int d (int a,int b){
    if (a < b)
        return 0;
    return 1 + d(a-b,b);
}
int main(){
    int a=d(12,3);
    printf("%d",a);
}