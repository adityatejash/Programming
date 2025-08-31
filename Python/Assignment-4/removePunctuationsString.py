# Remove Punctuations from a String
text = input("Enter String: ")
punctuations = f"+_)(*&^%$#@!~=-`:;<>,./?][)"
for i in punctuations:
    text = text.replace(i,"")
print(f"Without Punctuations: {text}")
print("Aditya Prakash -- BTCS24O1013")