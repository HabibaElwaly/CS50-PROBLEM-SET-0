#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    int sum1 = 0;
    int sum2 = 0;
    int counter = 0;
    long temp = number;
    int start = 0;

    while (temp > 0)
    {
        counter++;
        int digit = temp % 10;
        if (counter % 2 == 0)
        {
            int product = digit * 2;
            sum2 += (product % 10) + (product / 10);
        }
        else
        {
            sum1 += digit;
        }
        if (temp >= 10 && temp <= 99)
        {
            start = temp;
        }
        temp = temp / 10;
    }
    int total_sum = sum1 + sum2;
    if (total_sum % 10 == 0)
    {
        if (counter == 15 && (start == 34 || start == 37))
        {
            printf("AMEX\n");
        }
        else if (counter == 16 && (start >= 51 && start <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((counter == 16 || counter == 13) && (start / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
