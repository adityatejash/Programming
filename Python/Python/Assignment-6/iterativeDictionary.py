student = {
    "Name" : "Aditya Prakash",
    "Enrolment_No" : "BTCS24O1013"
}
for i in student: 
    print(i)
print()
for i in student.values():
    print(i)
print()
for i,j in student.items():
    print(f"{i} -- {j}")