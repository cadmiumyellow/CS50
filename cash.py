# Program that calculates how many coins should be given as change

from cs50 import get_float

# Getting non-negative change input from user
while True:
    sum = get_float("How much do we owe you?\n")
    if sum > 0:
        break

# Calculating sum in cents
sum *= 100

# Calculating number of quarters, dimes, nickels and pennies
quarters = int(sum / 25)
dimes = int((sum - (quarters * 25)) / 10)
nickels = int((sum - (quarters * 25) - (dimes * 10)) / 5)
pennies = int(sum - (quarters * 25) - (dimes * 10) - (nickels * 5))

# Printing the total number of coins to be given as change
print(quarters + dimes + nickels + pennies)