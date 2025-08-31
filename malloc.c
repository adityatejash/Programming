#include <stdio.h>
#include <stdlib.h>

struct A {
    char *a;
    int *b;
};

int main() {
    struct A x;
    x.a = malloc(100); // allocate enough space for string
    x.b = malloc(sizeof(int));

    printf("Enter string: ");
    fgets(x.a, 100, stdin); // safer: limit to 99 chars

    printf("Enter integer: ");
    scanf("%d", x.b);

    printf("You entered: %s %d\n", x.a, *x.b);

    free(x.a);
    free(x.b);
    return 0;
}
