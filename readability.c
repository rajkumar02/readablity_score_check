#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //Get the input values
    string s = get_string("Text: ");

    //Declear variable
    int n_words, n_sentances, n_letters;
    n_words = n_sentances = n_letters = 0;

    //Count the lenth of sentance
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isalpha(s[i]))
        {
            n_letters++;
        }
        if ((i == ' ' && s[i] != ' ') || (i != len - 1 && s[i] == ' ' && s[i + 1] != ' '))
        {
            n_words++;
        }
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            n_sentances++;
        }
    }

    float L = (n_letters / (float) n_words) * 100;
    float S = (n_sentances / (float) n_words) * 100;

    //Initialize Coleman-Liau formula to calculate the readablitity score!
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //Print the final score!!
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
        printf("Grade %i\n", index);
    }

}