#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    // declare program variables
    double letters = 0, words = 0, sentences = 0;

    // get input
    string inputText = get_string("Text: ");

    //loop for counting letters, words and sentences
    for (int i = 0, n = strlen(inputText); i < n; i++)
    {
        if ((inputText[i] >= 'A' && inputText[i] <= 'Z') || (inputText[i] >= 'a' && inputText[i] <= 'z'))
        {
            letters++;
        }
        else if (inputText[i] == ' ' && ((inputText[i - 1] != '!' && inputText[i - 1] != '.' && inputText[i - 1] != '?')))
        {
            words++;
        }
        else if (inputText[i] == '!' || inputText[i] == '.' || inputText[i] == '?')
        {
            words++;
            sentences++;
        }
    }

    // calcutate average
    double L = letters * 100 / words;
    double S = sentences * 100 / words;

    // calculate Coleman-Liau index
    double index = 0.0588 * L - 0.296 * S - 15.8;


    // conditional outputs
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
        printf("Grade %i\n", (int)round(index));
    }
}