#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Program which ciphers text.
int main(int argc, string argv[])
{   
    // Check for number of arguments:
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    } 
    
    // Check that each character of string is a decimal digit:
    string s = argv[1];
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;            
        }
    }
    
    // Check the key falls within acceptable range:
    int k = atoi(argv[1]);
    if (k < 0 || k > 100)
    {
        printf("Usage: ./caesar key\n");
        return 1;        
    }
    
    // Ask user for input:
    string plainText = get_string("plaintext: ");
    printf("\n");
    
    string cipherText = plainText;
    printf("Plain Text: %s\n", plainText);    
    
    for (int i = 0, n = strlen(cipherText); i < n; i++)
    {
        if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
        {
            cipherText[i] = (((cipherText[i] - 96) + k) % 26) + 96;
        }
        else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
        {
            cipherText[i] = (((cipherText[i] - 64) + k) % 26) + 64;
        }
        else
        {
            cipherText[i] = cipherText[i];
        }
    }
    
    
    // Print checks:
    printf("ciphertext: %s\n", cipherText);
}
