import random
house = ["Clubs","Diamonds","Spades","Hearts"]
card = ["A",2,3,4,5,6,7,8,9,10,"J","Q","K"]
deck = []
for i in house:
    for j in card:
        deck.append(f"{j} of {i}")
random.shuffle(deck)
for i in deck:
    print(i,)