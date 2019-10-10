# include <stdio.h>
# include <cs50.h>
# include <math.h>

int count(long input);
int cctype(long input, int* ptr0);

int main(void)
{
    // Get user input
    long number = get_long("Number: ");
    
    // Count number of digits
    int nDigits = count(number);
    
    // Check for first two digits
    int* ptr0 = &nDigits;
    int twoDigits = cctype(number, ptr0); 

    // Extract digits into array
    int digitArray[16] = {0};
    long n = number;
    int count = 0;
    
    while (n != 0)
    {
        digitArray[count] = n % 10;
        n /= 10;
        count++;
    }
    
    // Digits to be doubled and summed
    int tempVal = 0;
    int checksum = 0;
    for (int i = 1; i <= nDigits - 1; i+=2)
    {
        tempVal = digitArray[i];
        switch (tempVal)
        {
            case 5:
                tempVal = 1;
                break;
            case 6:
                tempVal = 3;
                break;
            case 7:
                tempVal = 5;
                break;
            case 8:
                tempVal = 7;
                break;
            case 9:
                tempVal = 9;
                break;
            default:
                tempVal *= 2;
        }
        checksum += tempVal;
    }
    
    // Remaining digits to be summed
    for (int i = 0; i <= nDigits - 1; i+=2) 
    {
        checksum += digitArray[i];
    }
    
    // Visa
    if(nDigits == 13 || nDigits == 16)
    
    // Print checks
    printf("Number of digits: %i\n", nDigits);
    printf("First 2 digits: %i\n", twoDigits);
    for (int i = 0; i < nDigits; i++)
    {
        printf("Digit %i: %d\n", i + 1, digitArray[i]);    
    }
    printf("Checksum: %i\n", checksum);
} 







// Function to count number of digits
int count(long input)
{
    int output = 0;
    while (input != 0)
    {
        input /= 10;
        output++;
    }
    return output;
}

// Function to get first two digits
int cctype(long input, int* ptr)
{
    int power = *ptr - 2;
    int output = input/pow(10, *ptr - 2);
    return output;
}
