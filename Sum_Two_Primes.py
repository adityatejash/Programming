# Sum of two prime number

class sumOfPrime_Structure :
    def __init__ (self, a, b):
        self.a = a
        self.b = b

def isPrime(number):
    if number <= 1:
        return 0
    for i in range(2,number):
        if number%i == 0:
            return 0
    return number

def sumOfPrime (sumOfPrime_Vector):
    number = int(input("Enter Number: "))
    flag = False
    for i in range (2, number//2 + 1):
        if isPrime(i) + isPrime(number-i) == number :
            print(f"{i} + {number-i} = {number}")
            sumOfPrime_Vector.append(sumOfPrime_Structure(i, number-i))
            flag = True
    if not flag:
        print("No prime sum found!!")
    return

def Count (sumOfPrime_Vector):
    count = len(sumOfPrime_Vector)
    return count

sumOfPrime_Vector = []
sumOfPrime(sumOfPrime_Vector)
print(f"Count: {Count(sumOfPrime_Vector)}")