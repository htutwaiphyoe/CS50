#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //this takes input
    string name = get_string("What is your name?\n");
    //show output
    printf("hello, %s\n", name);
}