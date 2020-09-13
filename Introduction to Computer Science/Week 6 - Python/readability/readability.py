from cs50 import get_string

letters = 0
words = 0
sentences = 0
count = 0

text = get_string("Text: ")

for c in text:
    count += 1

for i in range(count):
    if (text[i] >= 'A' and text[i] <= 'Z') or (text[i] >= 'a' and text[i] <= 'z'):
        letters += 1
    elif (text[i] == ' ' and (text[i - 1]) != '!' and text[i - 1] != '?' and text[i - 1] != '.'):
        words += 1
    elif (text[i] == '!' or text[i] == '?' or text[i] == '.'):
        sentences += 1
        words += 1

L = letters * 100 / words
S = sentences * 100 / words

index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")