# Program that prints out a half-pyramid of the specified height (1-8)

# Importing get_int function from cs50 library
from cs50 import get_int

# Creating a list of allowed height values
list = [1, 2, 3, 4, 5, 6, 7, 8]

# Getting input of pyramid height (reprompting when height is out of allowed list)
while True:
    height = get_int("Please input height of the pyramid between 1 and 8:\n")
    if height in list:
        break

# Introducing helper variables for printing hashes and spaces
h = height - 1
l = 0

# Printing the pyramid of the desired height
for i in range(height):
    print(" " * (height - 1) + "#" * (height - h + l))
    height -= 1
    h -= 1
    l += 1