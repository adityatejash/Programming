def Length(n):
    count = 0
    while n > 0:
        count += 1
        n /= 10
    return count

def armstrong(a):
    n = a
    power = Length(n)
    Sum = 0
    while n > 0:
        r = n%10
        Sum += pow(r,power)
        n /= 10

    if n == a:
        return "Armstrong"

    return "Not Armstrong" 

print()
print(armstrong(153))