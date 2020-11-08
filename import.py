from sys import argv, exit
import csv
from cs50 import SQL

# getting access to database
db = SQL("sqlite:///students.db")

# checking for correct number of command-line arguments
if len(argv) != 2:
    print("Please run program with 1 command-line argument being a csv file")
    exit(1)

# open a scv file
with open(argv[1], "r") as file:

    # create DictReader
    reader = csv.DictReader(file)

    # iterate over csv file
    for row in reader:

        # split names into first, middle(if any) and last and insert them into database
        x = row["name"].split()

        if len(x) == 2:
            first = x[0]
            #middle = None
            last = x[1]

            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, NULL, ?, ?, ?)",
                       first, last, row["house"], row["birth"])

        elif len(x) == 3:
            first = x[0]
            middle = x[1]
            last = x[2]

            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first, middle, last, row["house"], row["birth"])