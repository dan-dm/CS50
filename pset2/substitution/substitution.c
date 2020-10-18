//CS50 Problem Set 2 (edx 2020): Substitution (more comfortable)
//Author: @dan_marius

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
// Check for argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
// Check for complete (26 char) argument
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
// Check for all alphabetical argument
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: Key is not alphabetical\n");
            return 1;
        }
    }
// Check for uniqueness in argument
    int matches = 0;

    for (char x = 'a'; x <= 'z'; x++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (tolower(argv[1][i]) == x)
            {
                matches++;
                break;
            }
        }
    }
    if (matches != 26)
    {
        printf("Key must contain characters from a-Z (case insensitive) EXACTLY ONCE\n");
        return 1;
    }
// MAIN PROGRAM
    else if (argc == 2)
    {
        string key = argv[1];
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string text = get_string("Plaintext: ");
        string cyphertext = text;

        for (int i = 0, n = strlen(text); i < n; i++)
        {
            for (int k = 0, l = strlen(alphabet); k < l; k++)
            {
                if (toupper(text[i]) == alphabet[k])
                {
                    if (islower(text[i]))
                    {
                        cyphertext[i] = tolower(key[k]);
                    }
                    else
                    {
                        cyphertext[i] = toupper(key[k]);
                    }
                    break;
                }
            }
        }
        printf("ciphertext: %s\n", cyphertext);
        return 0;
    }
}