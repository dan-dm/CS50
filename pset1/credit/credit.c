//CS50 Problem Set 1 (edx 2020): Credit (more comfortable)
//Author: @dan_marius

#include <stdio.h>
#include <cs50.h>
#include <math.h>

long getdigit(long num, int n)
{
    long r;
    r = num / pow(10, n);
    r = r % 10;
    return r;
}

int main(void)
{

    long cardNumber;

    do
    {
        cardNumber = get_long("Card number: ");
    }
    while (cardNumber <= 0);


    int cardDigits = 0;
    long n = cardNumber;

    while (n != 0)
    {
        n = n / 10;
        ++cardDigits;
    }

    if (cardDigits != 13 && cardDigits != 15 && cardDigits != 16)
    {
        printf("INVALID\n");
    }
    else
    {

        int sumMultipliedByTwo = 0;
        int sumNotMultipliedByTwo = 0;

        for (int i = 0; i < cardDigits ; i++)
        {
            int k = getdigit(cardNumber, i);
            if (i % 2 != 0)
            {

                k = k * 2;
                if (k > 9)
                {
                    k = (k % 10) + 1;
                }

                sumMultipliedByTwo += k;
            }
            else if (i % 2 == 0)
            {
                sumNotMultipliedByTwo += k;
            }
        }
        if ((sumMultipliedByTwo + sumNotMultipliedByTwo) % 10 == 0)
        {
            if ((getdigit(cardNumber, cardDigits - 1)) == 4)
            {
                printf("VISA\n");

            }
            else if ((getdigit(cardNumber, cardDigits - 1)) == 5)
            {
                if (((getdigit(cardNumber, cardDigits - 2)) == 1) ||
                    ((getdigit(cardNumber, cardDigits - 2)) == 2) ||
                    ((getdigit(cardNumber, cardDigits - 2)) == 3) ||
                    ((getdigit(cardNumber, cardDigits - 2)) == 4) ||
                    ((getdigit(cardNumber, cardDigits - 2)) == 5))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if ((getdigit(cardNumber, cardDigits - 1)) == 3)
            {
                if (((getdigit(cardNumber, cardDigits - 2)) == 4) ||
                    ((getdigit(cardNumber, cardDigits - 2)) == 7))
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}