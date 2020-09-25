from cs50 import get_float

cash = get_float("Changed owed: ")

while cash <= 0:
    cash = get_float("Changed owed: ")

cash = round(cash * 100)
coins = 0

while cash > 0:
    if cash >= 25:
        cash -= 25
        coins += 1
    elif cash >= 10:
        cash -= 10
        coins += 1
    elif cash >= 5:
        cash -= 5
        coins += 1
    else:
        cash -= 1
        coins += 1

print(f"{coins}")