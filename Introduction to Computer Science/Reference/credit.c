#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card_number;
    int count = 0;
    int type = 0;

    card_number = get_long("Number: ");

    long card_number_copy = card_number;

    // counts number of digits
    while (card_number_copy > 0)
    {
        count++;
        card_number_copy /= 10;
    }

    if (count == 13)
    {

        if (card_number / 1000000000000 == 4)
        {
            type = 1;
        }
    }

    else if (count == 15)
    {
        int am15 = card_number / 10000000000000;
        if (am15 == 34 || am15 == 37)
        {
            type = 2;
        }
    }

    else if (count == 16)
    {
        int mc16 = card_number / 100000000000000;
        int visa16 = card_number / 1000000000000000;

        if (visa16 == 4)
        {
            type = 1;
        }
        else if (mc16 == 51 || mc16 == 52 || mc16 == 53 || mc16 == 54 || mc16 == 55)
        {
            type = 3;
        }
    }

    if (type > 0)
    {
        int last = 0, secToLast = 0, x;

        while (card_number > 0)
        {
            last += card_number % 10;

            card_number /= 10;

            x = (card_number % 10) * 2;

            if (x > 9)
            {
                int quotient = x / 10;
                int remainder = x % 10;
                secToLast += (quotient + remainder);
            }
            else
            {
                secToLast += x;
            }

            card_number /= 10;
        }
        if (((last + secToLast) % 10) == 0)
        {
            if (type == 1)
            {
                printf("VISA\n");
            }
            else if (type == 2)
            {
                printf("AMEX\n");
            }
            else if (type == 3)
            {
                printf("MASTERCARD\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}