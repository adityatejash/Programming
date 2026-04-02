#include <stdio.h>

int main(){
    unsigned int x[4][3] = {
                            {1,2,31},
                            {4,5,6},
                            {7,8,91},
                            {10,11,12}
                        };
    printf("%u, %u, %u",**x+3, **(x+3), **(x+2)+3);
}