def decimalToBinary (num):
    if num == 0:
        return 0
    return 10*decimalToBinary(num//2) + num%2
print(f"Decimal to Binary of 13 is {decimalToBinary(13)}")