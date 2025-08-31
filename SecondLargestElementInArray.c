#include <stdio.h>

int main(){
    int max, secondMax;
    int a[] = {0,3,11,14,-2};
    
    if (a[0] > a[1]){
        max = a[0];
        secondMax = a[1];
    } else {
        max = a[1];
        secondMax = a[0];
    }

    for (int i=2; i<5; i++){
        if (a[i] > max){
            secondMax = max;
            max = a[i];
        } else if (a[i] != max && a[i] > secondMax){
            secondMax = a[i];
        }
    }
    printf("Second Largest Number is %d\n",secondMax);
}
