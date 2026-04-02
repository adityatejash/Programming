# Check Whether a String is Palindrome or Not 
def isPalindrome(s):
    s = s.lower()
    s = s.replace(" ","")
    return s == s[::-1]
string = input("Enter a string: ")
if isPalindrome(string):
    print("Palindrome")
else:
    print("Not Palindrome")
print("Aditya Prakash -- BTCS24O1013")