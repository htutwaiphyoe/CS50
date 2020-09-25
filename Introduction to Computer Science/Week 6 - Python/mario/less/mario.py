from cs50 import get_int

h = get_int("Height: ")

while h <= 0 or h > 8:
    h = get_int("Height: ")
for i in range(h):
    print(" " * (h - i - 1), end="")
    print("#" * (i + 1))