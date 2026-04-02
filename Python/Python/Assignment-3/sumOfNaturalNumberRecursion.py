# find the sum of n natural number using Recursion
def sum(number):
    if number == 1:
        return 1
    return number + sum(number-1)
print(sum(13))
print("Aditya Prakash -- BTCS24O1013")