from cs50 import get_int

h = get_int("Height: ")

while h < 1 or h > 8:
    h = get_int("Height: ")

for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1), end="")
    print(" " * 2, end="")
    print("#" * (i + 1))