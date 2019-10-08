#include <cs50.h>
#include <stdio.h>

// Program to build half pyramid
int main(void)
{
    // Define height
    int height;
    
    // Ensure height is in range
    do
    {
        height = get_int("Height: ");  
    }
    while ((height <= 0) || (height > 8));
    
    // Draw graphics
    for (int i = 0; i < height; i++)
    {
        for (int j = i; j <= height - 2; j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }            
        printf("  ");
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
