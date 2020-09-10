#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // initialize key
    int key = 0;

    // if user add key, convert to int
    if (argc == 2)
    {
        key = atoi(argv[1]);
    }

    // if key is greater than 26, take remainder of dividing by 26

    if (key >= 26)
    {
        key %= 26;
    }

    // if user doesn't add key, show the format

    if (argc != 2 || key <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // handling non-numberic characters
    int k = 0, x = strlen(argv[1]);
    while (k < x)
    {
        if (isalpha(argv[1][k]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        k++;
    }

    // get plain text from user

    string inputText = get_string("plaintext: ");

    // loop for each character

    for (int i = 0, n = strlen(inputText); i < n; i++)
    {
        // for uppercase letters
        if (inputText[i] >= 65 && inputText[i] <= 90)
        {
            if (inputText[i] + key > 90)
            {
                inputText[i] -= 26;
            }

            inputText[i] += key;
        }

        // for lowercase letters
        else if (inputText[i] >= 97 && inputText[i] <= 121)
        {
            if (inputText[i] + key > 121)
            {
                inputText[i] -= 26;
            }

            inputText[i] += key;
        }
    }

    // print ciphertext
    printf("ciphertext: %s\n", inputText);

    return 0;

}