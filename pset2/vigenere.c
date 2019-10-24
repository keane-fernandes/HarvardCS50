#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int shift(char c, char k);

// Program which encrypts text according to Vigenere's cipher
int main(int argc, string argv[])
{   
    // Check for number of arguments
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    } 
    
    // Check that each character of string is an alphabet
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;            
        }
    }

    // Ask user for input
    string plainText = get_string("plaintext: ");
    string keyWord = argv[1];
    printf("ciphertext: ");
    // Loop to cipher each character of entered plain text
    for (int i = 0, j = 0, n = strlen(plainText), m = strlen(keyWord); i < n; i++)
    {
        if (j >= m)
        {
            j = 0;
        }
        
        if (isalpha(plainText[i]))
        {
            int key = shift(plainText[i], keyWord[j]);
            printf("%c", key);
            j++;
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}

// Returns shifted character
int shift(char c, char k)
{
    int cOffset = (isupper(c)) ? 65 : 97;
    int kOffset = (isupper(k)) ? 65 : 97;
    int output = ((c - cOffset) + (k - kOffset)) % 26 + cOffset;
    return output;
}
