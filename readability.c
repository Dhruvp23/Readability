#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);     // count letters
int count_word(string text);        // count word
int count_sentences(string text);   // count sentences

int main(void)
{
    float index;
    string text = get_string("Text : ");        // user input

    int letcount = count_letters(text);
    int wordcount = count_word(text);
    int senscount = count_sentences(text);


    float L = (float)letcount / wordcount * 100;
    float S = (float)senscount / wordcount * 100;
    index = (0.0588 * L - 0.296 * S - 15.8);        //calculate index
    int x = round(index);

    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", x);
    }
}

int count_letters(string text)
{
    int n = strlen(text);
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            j = j + 1;
        }
        else
        {

        }
    }
    return j;
}

int count_word(string text)
{
    int n = strlen(text);
    int j = 0;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            j = j + 1;
        }
        else
        {
            k = k + 1;
        }
    }
    return j + 1;
}

int count_sentences(string text)
{
    int n = strlen(text);
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (text[i] == 46 || text[i] == 63 || text[i] == 33)
        {
            j = j + 1;
        }
        else
        {

        }
    }
    return j;
}