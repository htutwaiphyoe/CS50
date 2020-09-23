#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, string argv[])
{
    // if user does not give key, exit the program
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // if key is less than 0, exit the program
    if (argv[1] < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // loop for each character in input to check is digt
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // make digit from string
    int k = atoi(argv[1]);

    // if key is greater than 26, take the remainer
    if (k >= 26)
    {
        k %= 26;
    }

    // get plain text
    string plain = get_string("plaintext: ");

    // loop for each character of plain text
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        // if upper, encrypt it
        if (isupper(plain[i]))
        {

            plain[i] -= 65;
            plain[i] += k;
            if (plain[i] >= 26)
            {
                plain[i] %= 26;
            }

            plain[i] += 65;

        }

        // if lower, encrypt it
        else if (islower(plain[i]))
        {

            plain[i] -= 97;
            plain[i] += k;

            if (plain[i] >= 26)
            {
                plain[i] %= 26;
            }

            plain[i] += 97;

        }

    }

    // print cipher text
    printf("ciphertext: %s\n", plain);

}