#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)

{
    // Prompt user for text
    string s = get_string("Text: ");

    // Count letters, words and sentences
    int letters = 0;
    int words = 1;
    int sentences = 0;
    int q = strlen(s);

    for (int i = 0; i < q; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }

        else if (isblank(s[i]))
        {
            words++;
        }
        
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }

    // calculating L and S for the formula
    float avLetters = ((float) letters * 100) / (float) words;
    float avSentences = ((float) sentences * 100) / (float) words;

    // calculating the Index using the formula
    int index = round((0.0588 * avLetters) - (0.296 * avSentences) - 15.8);

    // printing out the result Grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }

}