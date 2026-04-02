#include <stdio.h>


void merge(int a[], int lb, int mid, int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;

    int b[100];

    while (i<=mid && j<=ub){
        if (a[i] <= a[j]){
            b[k] = a[i];
            i++;
            k++;
        } else {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub){
        b[k] = a[j];
        j++;
        k++;
    }

    for (int z=lb; z<=ub; z++){
        a[z] = b[z];
    }
}

void mergeSort(int a[], int lb, int ub){
    if (lb < ub){
        int mid = (lb+ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main(){
    int a[100] = {
        8, 9, 4, -5, 3, 84, 15, -75, 
        27, -13, 56, 91, -42, 67, 33, -10,
        2, 14, -31, 79, 60, -23, 7, -90,
        18, 45, -67, 39, -8, 22, 51, 11,
        -19, 73, -2, 5, 88, -45, 64, -36,
        99, -55, 12, 37, -6, 85, 41, -77,
        23, 59, -33, 26, 44, -20, 70, -18,
        35, -48, 62, -28, 94, -15, 10, 80,
        -50, 46, -3, 58, -25, 29, 92, -9,
        53, -60, 19, 76, -12, 31, 43, -17,
        68, -40, 32, 21, -61, 6, 66, -27,
        90, -84, 28, 13, -72, 54, -35, 97,
        17, -58, 30, 42
    };

    int s = sizeof(a)/sizeof(a[0]);

    mergeSort(a,0,s-1);
    printf("MergeSort: ");
    for (int i=0; i<s; i++){
        printf("%d ",a[i]);
    }
}