# Sort Words in Alphabetic Order
text = input("Enter Sentence: ")
text = text.lower()
words = text.split()   
words.sort()           
print("Sorted words:")
for word in words:
    print(word)
print("Aditya Prakash -- BTCS24O1013")