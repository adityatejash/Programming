def Inserting_Values_in_Matrix(rows, column, Matrix):
    for i in range(rows):
        temp_list = []
        for j in range(column):
            element = int(input(f"Enter Element Number ({i+1},{j+1}): "))
            temp_list.append(element)
        Matrix.append(temp_list)

def Displaying_Matrix(rows, column, Matrix):
    for i in range (rows):
        for j in range (column):
            if j < column-1:
                print(Matrix[i][j], end= ", ")
            else:
                print(Matrix[i][j], end = "")
        print()

def Addition(rows, column, Matrix_1, Matrix_2, Matrix_3):
    for i in range(rows):
        temp = []
        for j in range(column):
            temp.append(Matrix_1[i][j] + Matrix_2[i][j])
        Matrix_3.append(temp)

def Subtraction(rows, column, Matrix_1, Matrix_2, Matrix_3):
    for i in range(rows):
        temp = []
        for j in range(column):
            temp.append(Matrix_1[i][j] - Matrix_2[i][j])
        Matrix_3.append(temp)

def Multiplication(rows, column, Matrix_1, Matrix_2, Matrix_3):
    for i in range(rows):
        temp_list = []
        for j in range(column):
            sum = 0
            for k in range(column):
                sum += Matrix_1[i][k] * Matrix_2[k][j]
            temp_list.append(sum)
        Matrix_3.append(temp_list)

Matrix_1 = []
Matrix_2 = []
Resultant_Matrix = []
rows = int(input("Enter Rows of Matrix: "))
column = int(input("Enter Column of Matrix: "))
print("\n")

print("Enter Elements of Matrix 1:")
Inserting_Values_in_Matrix(rows, column, Matrix_1)
print("\n")
print("Enter Elements of Matrix 2:")
Inserting_Values_in_Matrix(rows, column, Matrix_2)
print("\n")

print("Matrix 1:")
Displaying_Matrix(rows, column, Matrix_1)
print("\n")
print("Matrix 2:")
Displaying_Matrix(rows, column, Matrix_2)
print("\n")

print("Enter,\n1. for Addition, or\n2. for Subtraction, or\n 3. for Multiplication: ")
choice = int(input("Enter Choice: "))
if choice == 1:
    Addition(rows, column, Matrix_1, Matrix_2, Resultant_Matrix)
    print("The Addition of two Matrices is: \n")
    Displaying_Matrix(rows, column, Resultant_Matrix)
elif choice == 2:
    Subtraction(rows, column, Matrix_1, Matrix_2, Resultant_Matrix)
    print("The Subtraction of two Matrices is: \n")
    Displaying_Matrix(rows, column, Resultant_Matrix)
elif choice == 3:
    Multiplication(rows, column, Matrix_1, Matrix_2, Resultant_Matrix)
    print("The Multiplication of two Matrices is: \n")
    Displaying_Matrix(rows, column, Resultant_Matrix)
else:
    print("Enter from the above choices!!")

