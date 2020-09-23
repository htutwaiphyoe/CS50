#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    // get input text
    string text = get_string("Text: ");

    // declare progarm variables
    int letters = 0;
    int words = 0;
    bool counting = true;
    int sentences = 0;

    // loop for each character in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // check for letter
        if (isalpha(text[i]))
        {
            letters++;
        }

        // check for words
        if (text[i] != 32)
        {
            if (counting)
            {
                words++;
                counting = false;
            }
        }
        // if character is space, count again
        else
        {
            counting = true;
        }
        // check for sentences
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    // calculating average letters per 100 words
    float L = (float)letters * 100 / (float) words;
    // calculating average sentences per 100 words
    float S = (float)sentences * 100 / (float) words;

    // Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // output grade depend on index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}