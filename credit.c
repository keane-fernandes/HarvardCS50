# include <stdio.h>
# include <cs50.h>
# include <math.h>

int count(long input);
int cctype(long input, int *ptr0);

int main(void)
{
    // Get user input
    int nDigits = 0;
    long number = 0;
    
    // Count number of digits
    do
    {
        number = get_long("Number: ");
        nDigits = count(number);
    }
    while (nDigits > 16);
    
    // Check for first two digits
    int *ptr0 = &nDigits;
    int twoDigits = cctype(number, ptr0); 

    // Extract digits into array
    int digitArray[20] = {0};
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
    for (int i = 1; i <= nDigits - 1; i += 2)
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
    for (int i = 0; i <= nDigits - 1; i += 2) 
    {
        checksum += digitArray[i];
    }
    
    // Number of digits check:
    // 1 --> Visa, Amex or Mastercard
    // 0 --> Invalid
     
    int digitCheck = 0;
    if (nDigits == 13 || nDigits == 15 || nDigits == 16) 
    {
        digitCheck = 1;
    }
    else
    {
        digitCheck = 0;
    }
    
    // First two digits check:
    // 1 --> Amex
    // 2 --> Mastercard
    // 3 --> Visa
    // 0 --> Invalid
    
    int typeCheck = 0;
    if (twoDigits == 34 || twoDigits == 37)
    {
        typeCheck = 1;
    }
    else if (twoDigits >= 51 && twoDigits <= 55)
    {
        typeCheck = 2;
    }
    else if (twoDigits >= 40 && twoDigits <= 49)
    {
        typeCheck = 3;
    }
    else
    {
        typeCheck = 0;
    }  
    
    // Checksum check:
    // 1 --> true
    // 0 --> false
    
    int checkChecksum = (checksum % 10 == 0) ? 1 : 0;
    
    // Preliminary Checks:
    if (digitCheck == 0)
    {
        printf("INVALID\n");
    } 
    
    if (typeCheck == 0)
    {
        printf("INVALID\n");        
    }
    
    // Check for AMEX: 
    if (digitCheck == 1)
    {
        if (typeCheck == 1)
        {
            if (checkChecksum == 1)
            {
                printf("AMEX\n");    
            }
            else
            {
                printf("INVALID\n");
            }            
        }
    }
    
    // Check for MASTERCARD
    if (digitCheck == 1)
    {
        if (typeCheck == 2)
        {
            if (checkChecksum == 1)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");    
            }
        }
    }
            
    // Check for Visa        
    if (digitCheck == 1)
    {
        if (typeCheck == 3)
        {
            if (checkChecksum == 1)
            {
                printf("VISA\n");                 
            }
            else
            {
                printf("INVALID\n");    
            }
        }
    }
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
int cctype(long input, int *ptr0)
{
    int output = input / pow(10, *ptr0 - 2);
    return output;
}
