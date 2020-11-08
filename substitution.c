// Substitution cipher

#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checking if user provides exactly 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    //checking if the key contains exactly 26 characters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // setting alphabet to check against the provided key
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    //checking that the provided key contains chars only
    int n = strlen(argv[1]);

    for (int i = 0; i < n; i++)
    {
        argv[1][i] = toupper(argv[1][i]);

        if (argv[1][i] < 65 || argv[1][i] > 90)
        {
            printf("Key must only contain alpabetic characters\n");
            return 1;
        }

        //replacing letters in the alphabet array with spaces when such letters occur in the provided key
        for (int h = 0; h < n; h++)
        {
            if (argv[1][i] == alphabet[h])
            {
                alphabet[h] = ' ';
            }
        }
    }

    //checking the key for repeated characters using the alphabet array previously altered to spaces array 
    for (int j = 0; j < n; j++)
    {
        if (!isblank(alphabet[j]))
        {
            printf("Key must not contain repeated characters\n");
            return 1;
        }
    }

    // getting input from user
    string s = get_string("plaintext: ");

    // using alphabet string as sample for letter mapping against the provided key
    string sample = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // enciphering input and printing out the ciphertext
    printf("ciphertext: ");

    for (int l = 0; l < strlen(s); l++)
    {
        if (!isalpha(s[l]))
        {
            printf("%c", s[l]);
        }

        for (int m = 0; m < strlen(sample); m++)
        {

            if (s[l] == sample[m] && isupper(s[l]))
            {
                printf("%c", argv[1][m]);
            }

            else if (toupper(s[l]) == sample[m])
            {
                printf("%c", tolower(argv[1][m]));
            }
        }

    }

    printf("\n");
    return 0;

}