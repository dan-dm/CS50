#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    int spaces;
    int hashesLeft;
    int hashesRight;

    //get height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //set spaces and hashes
    spaces = n - 1;
    hashesLeft = 1;
    hashesRight = 1;

    do
    {
        //print spaces
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }

        //print left piramid hashes
        for (int j = 0; j < hashesLeft; j++)
        {
            printf("#");
        }

        //print spaces between piramids
        printf("  ");
        
        //print right piramid hashes
        for (int j = 0; j < hashesRight; j++)
        {
            printf("#");
        }
        //new line
        printf("\n");

        //decrease spaces & increase hashes
        spaces = spaces - 1;
        hashesLeft++;
        hashesRight++;

    }
    while (spaces >= 0); //end when there are no more spaces.
}