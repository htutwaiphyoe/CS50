#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check argument count
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int n = strlen(argv[1]);

    // check key length
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // declare array for valid key
    char k[26];
    // loop for each character of key
    for (int i = 0; i < n; i++)
    {
        // check non-alphabetic character
        if (!isalpha(argv[1][i]))
        {

            printf("Usage: ./substitution key\n");
            return 1;
        }

        char c = argv[1][i];
        // check repeated character
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (c == argv[1][j])
            {
                printf("Key must not contain repeated character\n");
                return 1;
            }
        }
        // store in key array
        k[i] = argv[1][i];
    }

    // get plain text
    string plain = get_string("plaintext: ");

    // loop for each character in plaintext
    for (int i = 0, l = strlen(plain); i < l; i++)
    {
        // check lower upper
        if (isupper(plain[i]))
        {
            int index = plain[i] - 65;

            plain[i] = toupper(k[index]);
        }
        // check for lower
        if (islower(plain[i]))
        {
            int index = plain[i] - 97;

            plain[i] = tolower(k[index]);
        }

    }

    // print ciphertext
    printf("ciphertext: %s\n", plain);

}