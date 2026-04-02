# Finding Grades
totalMarks = int(input("Enter total marks (<=500): "))
if totalMarks > 500:
    print("Invalid! Marks greater than 500.")
elif totalMarks > 450:
    print("The grade is A.")
elif totalMarks > 350 and totalMarks <= 450:
    print("The grade is B.")
elif totalMarks > 250 and totalMarks<=350:
    print("The grade is C.")
else :
    print("Fail")
print("Aditya Prakash -- BTCS24O1013")