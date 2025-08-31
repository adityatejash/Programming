# factorial function
def factorial (number):
    f = 1
    for i in range (2,number+1):
        f *= i
    return f
print(factorial(4))
print("Aditya Prakash -- BTCS24O1013")