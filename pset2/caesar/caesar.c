//CS50 Problem Set 2 (edx 2020): Caesar
//Author: @dan_marius

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i])) //check for all digit argument
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        int key = atoi(argv[1]);
        string plain = get_string("plaintext: ");

        for (int i = 0, n = strlen(plain); i < n; i++) //recursive cypher
        {
            int c = plain[i];

            if (c >= 65 && c <= 90) //for A-Z
            {
                for (int j = 0; j < key; j++)
                {
                    if (c == 90)
                    {
                        c = 64;
                    }
                    c++;
                }
            }

            if (c >= 97 && c <= 122) //for a-z
            {
                for (int j = 0; j < key; j++)
                {
                    if (c == 122)
                    {
                        c = 96;
                    }
                    c++;
                }
            }
            plain[i] = c;
        }
        printf("ciphertext: %s\n", plain);
        return 0;
    }
}