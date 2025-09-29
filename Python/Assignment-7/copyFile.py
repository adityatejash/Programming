# Python Program to Copy a File
with open ("Python/Assignment-7/pythonfile.txt", "r") as file:
    copyContent = file.readlines()
    print(f"----Source File Content----\n{copyContent}")
with open ("Python/Assignment-7/NewPythonFile.txt", "a") as file:
    file.writelines(copyContent)
print("Aditya Prakash -- BTCS24O1013")