#include <cs50.h>
#include <stdio.h>

void printPyramid(int n);
int main(void)
{

    // Initialize height
    int height;

    // make a loop for height that must be between 1 and 8
    // use do while for at least one answer
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // print pyramid
    printPyramid(height);
}

void printPyramid(int n)
{

    // loop for pyramid height
    for (int i = 0; i < n; i++)
    {

        // loop for empty space
        for (int j = n - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // loop for block
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}