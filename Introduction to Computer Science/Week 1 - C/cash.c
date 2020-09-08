#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    //declare dollars
    float dollars;

    // get input until input is greater than 0
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    // chage dollars to cents
    int cents = round(dollars * 100);

    // initialize number of coins
    int numOfCoins = 0;


    // loop until cents equal or less than 0
    while (cents > 0)
    {

        // substract conditionally
        if (cents >= 25)
        {
            cents -= 25;
            numOfCoins++;
        }
        else if (cents >= 10)
        {
            cents -= 10;
            numOfCoins++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            numOfCoins++;
        }
        else
        {
            cents -= 1;
            numOfCoins++;
        }
    }

    // print number of coins
    printf("%i\n", numOfCoins);
}