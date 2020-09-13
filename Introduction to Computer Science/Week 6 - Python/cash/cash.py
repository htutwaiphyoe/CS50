from cs50 import get_float

dollars = get_float("Change owed: ")

while dollars <= 0:
    dollars = get_float("Change owed: ")

cents = round(dollars * 100)

numOfCoins = 0

while cents > 0:
    if cents >= 25:
        cents -= 25
        numOfCoins += 1
    elif cents >= 10:
        cents -= 10
        numOfCoins += 1
    elif cents >= 5:
        cents -= 5
        numOfCoins += 1
    else:
        cents -= 1
        numOfCoins += 1
print(numOfCoins)