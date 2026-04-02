# Convert Decimal to Binary Using Recursion
def decToBinary(number):
    if number == 0:
        return 0
    return (number % 2) + 10 * decToBinary(number // 2)
print(decToBinary(13))
print("Aditya Prakash -- BTCS24O1013")