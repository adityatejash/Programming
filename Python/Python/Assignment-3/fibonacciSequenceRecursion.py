# Display the Fibonacci Sequence Using Recursion
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
terms = 13
for i in range(terms):
    print(fibonacci(i), end=" ")
print("\nAditya Prakash -- BTCS24O1013")