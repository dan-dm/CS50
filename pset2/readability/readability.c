//CS50 Problem Set 2 (edx 2020): Readability
//Author: @dan_marius

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    string s = get_string("Text: ");

    for (int i = 0, textLength = strlen(s); i < textLength; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letters++;
        }

        if (s[i] == ' ')
        {
            words++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
        if (i == textLength - 1)    //count last word
        {
            words++;
        }
    }

    float averageLettersPerHundredWords = (letters * 100.0) / words;
    float averageSentencesPerHundredWords = (sentences * 100.0) / words;

    float index = (0.0588 * averageLettersPerHundredWords - 0.296 * averageSentencesPerHundredWords -
                   15.8);    // The Coleman-Liau index

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}