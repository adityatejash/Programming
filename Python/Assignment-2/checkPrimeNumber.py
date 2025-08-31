# write a program to check weather a given number is prime or not
number = int(input("Enter Number: "))
flag = True
for i in range(2,number):
    if number%i == 0:
        flag = False
        break
if flag:
    print("Prime")
else:
    print("NOT Prime")
print("Aditya Prakash -- BTCS24o1013")
