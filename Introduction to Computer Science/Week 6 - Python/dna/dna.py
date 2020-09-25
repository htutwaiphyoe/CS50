from csv import reader
from sys import argv


# checking argument counts
if (len(argv) != 3):
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

people_dna = []
# open csv file
try:
    with open(argv[1], "r") as database_file:
        if (database_file == None):
            print("Can't open file")
            exit(1)
        data = reader(database_file)
        for row in data:
            people_dna.append(row)
except FileNotFoundError:
    print("Could not open file!")

# open sequence file
try:
    with open(argv[2], "r") as sequence_file:
        if (sequence_file == None):
            print("Can't open file")
            exit(1)
        sequences = sequence_file.read()

except FileNotFoundError:
    print("Could not open file!")

# search STR sequence
dna = people_dna[0]
# remove first row
dna.pop(0)
people_dna.pop(0)

# find dna sequences from sequence file
person_dna = []
for i in dna:
    j = i
    count = 0
    while (i in sequences):
        count += 1
        i += j
    person_dna.append(f"{count}")

# check dna sequneces in database file
is_found = False
for i in people_dna:
    d = []
    for j in range(len(i)):
        if (j == 0):
            continue
        d.append(i[j])
    if (person_dna == d):
        print(i[0])
        is_found = True
        break

if (is_found == False):
    print("No match")