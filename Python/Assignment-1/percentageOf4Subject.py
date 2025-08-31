# write a program to find percentage of four subject of 80 marks each
s1 = int(input("Enter marks of subject 1 (out of 80): "))
s2 = int(input("Enter marks of subject 2 (out of 80): "))
s3 = int(input("Enter marks of subject 3 (out of 80): "))
s4 = int(input("Enter marks of subject 4 (out of 80): "))
totalMarks = s1 + s2 + s3 + s4
maxMarks = 80*4
print(f"The percentage is {totalMarks/maxMarks*100}")
print("Aditya Prakash--BTCS24O1013")