# List Operations
print("=== LIST OPERATIONS ===")

fruits = ["apple", "banana", "cherry"]
print("Original List:", fruits)

fruits.append("orange")       
fruits.insert(1, "grape")     
print("After Adding:", fruits)
fruits.remove("banana")       
popped_item = fruits.pop()    

print("After Removing:", fruits)
print("Popped Item:", popped_item)
print("Sliced List (first 2):", fruits[:2])
for fruit in fruits:
    print("Fruit:", fruit)
print("Aditya Prakash-- BTCS24O1013")
print("\n")


# Tuple Operations
print("=== TUPLE OPERATIONS ===")

numbers = (10, 20, 30, 40, 20)
print("Original Tuple:", numbers)
print("First element:", numbers[0])
print("Last element:", numbers[-1])
print("Count of 20:", numbers.count(20))
print("Index of 30:", numbers.index(30))
print("Aditya Prakash-- BTCS24O1013")
print("\n")

# Set Operations
print("=== SET OPERATIONS ===")

set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}
print("Set1:", set1)
print("Set2:", set2)

print("Union:", set1 | set2)
print("Intersection:", set1 & set2)
print("Difference (Set1 - Set2):", set1 - set2)
set1.add(7)
set1.discard(2)
print("After Add/Remove in Set1:", set1)
print("Aditya Prakash-- BTCS24O1013")