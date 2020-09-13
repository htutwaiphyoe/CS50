from sys import argv
from csv import reader, DictReader

# exit input is invalid
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
# read database file
with open(argv[1], "r") as dataFile:
    data = list(reader(dataFile))
# read input file
with open(argv[2], "r") as searchFile:
    searchData = searchFile.read()

# remove name
data[0].remove("name")
# get sequence
sequences = data[0]

sequencesCount = []
# loop for each sequence
for i in range(len(sequences)):
    # setting sequence position
    currPos = 0
    # setting sequence count
    count = 0
    # setting prev sequence position
    prevPos = 0
    # setting maximum count
    maxCount = 0
    # loop for searching sequence
    while currPos < len(searchData):
        # finding sequence position
        currPos = searchData.find(sequences[i], currPos)
        # no sequence found
        if (currPos == -1):
            count = 0
            break
        # sequence found
        elif (currPos != -1 and prevPos == 0):
            count += 1
            prevPos = currPos
            maxCount = count
        # checking sequence is contiguous
        elif (currPos != -1 and currPos - prevPos == len(sequences[i])):
            count += 1
            prevPos = currPos
            if maxCount < count:
                maxCount = count
        # new sequence found
        elif (currPos != 1 and currPos - prevPos != len(sequences[i])):
            count = 1
            prevPos = currPos
            if maxCount < count:
                maxCount = count
        # incement position
        currPos += 1
    # save maxcount
    sequencesCount.append(maxCount)

# remove element 0 which is sequence
data.pop(0)
# initialze name
name = False
# sequence max count value
value = []
# loop for each row in data.csv
for i in range(len(data)):
    # get one row
    values = data[i]
    # clean value
    value = []
    # loop for rwo
    for v in range(len(values)):
        # skip name
        if v == 0:
            continue
        # add value
        value.append(int(values[v]))
    # checking value is equal to sequencecount
    if value == sequencesCount:
        # set name
        name = values[0]
        # exit the loop
        break
# print answer
if name:
    print(name)
else:
    print("No match")

