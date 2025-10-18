def fabonacci (terms):
    if (terms == 0):
        return 0
    elif (terms == 1):
        return 1
    return fabonacci(terms-1) + fabonacci(terms-2)
terms = int(input("Enter number of terms: "))
for i in range(terms):
    print(fabonacci(i),end=", ")