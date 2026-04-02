#  Find the Factorial of Number Using Recursion
def factorial (number):
    if number == 0 or number == 1:
        return 1
    return number * factorial(number-1)
print(factorial(4))
print("Aditya Prakash -- BTCS24O1013")