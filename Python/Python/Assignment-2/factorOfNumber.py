# write a program to find factors of a number
number = int(input("Enter Number: "))
print("The facors are: ",end=" ")
for i in range(1,number+1):
    if number%i == 0:
        print(f"{i}",end = ", ")
print("Aditya Prakash -- BTCS24o1013")