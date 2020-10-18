//CS50 Problem Set 1 (edx 2020): Hello
//Author: @dan_marius

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("hello, %s!\n", name);
}