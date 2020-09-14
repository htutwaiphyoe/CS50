from cs50 import SQL
from csv import reader
from sys import argv

if len(argv) < 2:
    print("Usage: import.py data.csv")
    exit(1)
db = SQL("sqlite:///students.db")
with open(argv[1], 'r') as inputFile:
    data = reader(inputFile)
    for row in data:
        if (row[0] == 'name'):
            continue
        first = None
        middle = None
        last = None
        nameArr = row[0].split()
        if len(nameArr) == 3:
            first = nameArr[0]
            middle = nameArr[1]
            last = nameArr[2]
        elif len(nameArr) == 2:
            first = nameArr[0]
            last = nameArr[1]
        db.execute('INSERT INTO students(first, middle, last, house, birth) VALUES (?,?,?,?,?)',
                   first, middle, last, row[1], row[2])

