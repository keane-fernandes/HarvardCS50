#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int a , b;
    a = 10;
    b = 2;

    a = (a << 1) + b;

    printf("The answer is: %i", a);
}