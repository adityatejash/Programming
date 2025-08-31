// Q5. Write a C program to find mean, median, mode.
#include <stdio.h>

float mean(float A[], int x)
{
    float s = 0;
    for (int i = 0; i < x; i++)
        s += A[i];
    return s / x;
}

float median(float A[], int x)
{
    if (x % 2 == 0)
        return (A[x / 2] + A[x / 2 - 1]) / 2;
    else
        return A[x / 2];
}

void sort_array_increasing(float A[], int x)
{
    float t;
    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < x; j++)
        {
            if (A[i] > A[j])
            {
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
}

float mode(float A[], int x)
{
    int max_count = 0, count;
    float mode_value = A[0];
    for (int i = 0; i < x; i++)
    {
        count = 1; // Count occurrences of A[i]
        for (int j = i + 1; j < x; j++)
        {
            if (A[i] == A[j])
                count++;
        }

        if (count > max_count)
        {
            max_count = count;
            mode_value = A[i];
        }
    }
    if (max_count == 1)
    {
        printf("No mode exists (all values are unique).\n");
        return -1;
    }

    return mode_value;
}

int main()
{
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    float Element[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%f", &Element[i]);
    }
    sort_array_increasing(Element, n);
    printf("Elements in increasing order are: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", Element[i]);
    printf("\n");
    printf("Mean: %.2f\n", mean(Element, n));
    printf("Median: %.2f\n", median(Element, n));
    float mode_result = mode(Element, n);
    if (mode_result != -1)
        printf("Mode: %.2f\n", mode_result);
    return 0;
}
