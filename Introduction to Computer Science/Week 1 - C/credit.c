#include <stdio.h>
#include <cs50.h>
#include <string.h>

int checkSum(int length, long c);
int main(void)
{
    // declare program variables
    long card;
    string type;
    int result = 0;

    // get inputs
    card = get_long("Numbers: ");

    // check master
    if (card >= 1000000000000000)
    {

        if (card / 100000000000000 == 51 ||
            card / 100000000000000 == 52 ||
            card / 100000000000000 == 53 ||
            card / 100000000000000 == 54 ||
            card / 100000000000000 == 55)

        {
            type = "MASTERCARD";
            result = checkSum(16, card);
        }

        else if (card / 1000000000000000 == 4)
        {
            type = "VISA";
            result = checkSum(16, card);
        }
    }

    // check amex
    else if (card >= 100000000000000)
    {
        if (card / 10000000000000 == 34 || card / 10000000000000 == 37)
        {
            type = "AMEX";

            result = checkSum(15, card);
        }
    }


    // check visa
    else if (card >= 1000000000000)
    {
        if (card / 1000000000000 == 4)
        {
            type = "VISA";
            result = checkSum(13, card);
        }
    }

    // check invalid
    else
    {
        type = "INVALID";
    }

    // check card number is valid
    if (result == 1)
    {
        printf("%s\n", type);
    }
    else
    {
        type = "INVALID";
        printf("%s\n", type);
    }
}

int checkSum(int length, long card)
{
    // declare program variables
    long sec_to_last = 0;
    long last = 0;
    long divider = 1;
    int turn = 0;

    // loop for length
    for (int i = 0; i < length; i++)
    {
        long c = card / divider;
        long remainder = c % 10;

        if (turn == 0)
        {
            last += remainder;
            turn = 1;
        }

        else if (turn == 1)
        {
            remainder = remainder * 2;
            if (remainder < 10)
            {
                sec_to_last += remainder;
            }
            else
            {
                sec_to_last += remainder / 10;
                sec_to_last += remainder % 10;
            }

            turn = 0;
        }
        divider *= 10;
    }

    // check valid checksum
    if ((sec_to_last + last) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}