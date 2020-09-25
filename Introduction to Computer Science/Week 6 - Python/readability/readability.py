from cs50 import get_string


# get input text
text = get_string("Text: ")

# declare program variables
letters = 0
words = 0
sentences = 0
count = True

# loop for each character in text
for i in text:

    # check for letter
    if i.isalpha():
        letters += 1

    # check for words
    if i != " ":
        if count:
            words += 1
            count = False

    # if character is space, count again
    else:
        count = True

    # check for sentences
    if i == "." or i == "!" or i == "?":
        sentences += 1


# calculating average letters per 100 words
L = letters * 100 / words

# calculating average sentences per 100 words
S = sentences * 100 / words

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# output grade depend on index
if (index < 1):
    print("Before Grade 1")

elif (index >= 16):
    print("Grade 16+")

else:
    print(f"Grade {index}")