from cs50 import get_int

import math


def main():
    # get input
    card = get_int("Number: ")

    result = 0
    type = ""

    # check master
    if (card >= 1000000000000000):
        if math.floor(card / 100000000000000) == 51 or math.floor(card / 100000000000000) == 52 or math.floor(card / 100000000000000) == 53 or math.floor(card / 100000000000000) == 54 or math.floor(card / 100000000000000) == 55:
            type = "MASTERCARD"
            result = checkSum(16, card)

        elif (math.floor(card / 1000000000000000) == 4):
            type = "VISA"
            result = checkSum(16, card)

    # check amex
    elif (card >= 100000000000000):

        if (math.floor(card / 10000000000000) == 34 or math.floor(card / 10000000000000) == 37):
            type = "AMEX"
            result = checkSum(15, card)

    # check visa
    elif (card >= 1000000000000):
        if (math.floor(card / 1000000000000) == 4):
            type = "VISA"
            result = checkSum(13, card)

    # check invalid
    else:
        type = "INVALID"

    # check card number is valid
    if (result == 1):
        print(type)
    else:
        type = "INVALID"
        print(type)


def checkSum(length, card):

    # declare program variables
    sec_to_last = 0
    last = 0
    divider = 1
    turn = 0

    # loop for length
    for i in range(length):
        c = math.floor(card / divider)
        remainder = c % 10

        if (turn == 0):
            last += remainder
            turn = 1

        elif (turn == 1):
            remainder = remainder * 2
            if (remainder < 10):
                sec_to_last += remainder
            else:
                sec_to_last += math.floor(remainder / 10)
                sec_to_last += remainder % 10

            turn = 0
        divider *= 10

    # check valid checksum
    if ((sec_to_last + last) % 10 == 0):
        return 1
    else:
        return 0


main()