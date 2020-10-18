//CS50 Problem Set 1 (edx 2020): Cash
//Author: @dan_marius

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //declare vars
    float dollars;
    int cents;
    int numCoins = 0;

    //get dollars owned
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    //transform dollars to cents
    cents = round(dollars * 100);

    //countdown coins

    while (cents >= 25)
    {
        cents = cents - 25;
        numCoins++;
    }

    while (cents >= 10)
    {
        cents = cents - 10;
        numCoins++;
    }

    while (cents >= 5)
    {
        cents = cents - 5;
        numCoins++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        numCoins++;
    }

    //print total coins given
    printf("%i\n", numCoins);


}
