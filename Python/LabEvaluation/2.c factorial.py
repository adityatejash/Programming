def factorial (num):
    if num == 1:
        return 1
    return num*factorial(num-1)
print(f"Factorial of 5 is {factorial(5)}")