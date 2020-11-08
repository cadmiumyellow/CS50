# Program that prints out list of selected Hogwarts house students

from sys import argv, exit
from cs50 import SQL

# checking for the correct number of command-line arguments (1)
if len(argv) != 2:
    print("Please run program with 1 command-line argument")
    exit(1)

# getting access to Hogwarts' students database
db = SQL("sqlite:///students.db")

# making up a list of Hogwarts houses
list = ["Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw"]

# printing each house roster
if argv[1] in list:

    # executing a query on the database
    res = db.execute(f"SELECT first, middle, last, birth FROM students WHERE house = '{argv[1]}' ORDER BY last, first")

    # looping through the list of return dictionaries
    for x in res:

        # printing output taking care of absent middle names
        if x["middle"] == None:
            print(x["first"] + " " + str(x["last"]) + ", born " + str(x["birth"]))
            
        else:
            print(x["first"] + " " + str(x["middle"]) + " " + str(x["last"]) + ", born " + str(x["birth"]))

# error message if user entered a wrong house name
else:
    print("No such house in Hogwarts, man")