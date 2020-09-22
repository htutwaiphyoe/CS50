#include <cs50.h>
#include <stdio.h>

void printSpace(int n);
void printBlock(int n);
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

    // print pyramids
    printPyramid(height);
}
void printSpace(int n)
{
    for (int i = n; i > 0; i--)
    {
        printf(" ");
    }
}
void printBlock(int n)
{
    for (int l = 0; l <= n; l++)
    {
        printf("#");
    }
};
void printPyramid(int n)
{

    // loop for pyramid height
    for (int i = 0; i < n; i++)
    {

        // loop for empty space
        printSpace(n - i - 1);

        // loop for block
        printBlock(i);

        // loop for middlespace
        printSpace(2);

        // loop for block
        printBlock(i);


        printf("\n");
    }
}