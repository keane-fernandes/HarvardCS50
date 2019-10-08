#include <stdio.h>
#include <cs50.h>

// Says hello to the world
int main(void)
{ 
    // Ask user for input
    string name = get_string("What is your name?\n");    
    // Print output to screen
    printf("hello, %s\n", name);
}
