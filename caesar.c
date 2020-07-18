// Caesar cypher

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include<ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // checking if user provides 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        // checking if the provided argument consists of digits only
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < strlen(argv[i]); j++)
            {
                if (argv[i][j] < '0' || argv[i][j] > '9')
                {
                    printf("Usage: %s key\n", argv[0]);
                    return 1;
                }
            }

            // converting provided string argument to number
            int key = atoi(argv[i]);
            printf("%i\n", key);

            // prompting user for text to be encyphered
            string s = get_string("plaintext: ");

            // rotating string characters
            printf("cyphertext: ");
            for (int k = 0; k < strlen(s); k++)
            {
                if (s[k] >= 65 && s[k] <= 90)
                {
                    int l = s[k] - 65;
                    int m = (l + key) % 26;
                    printf("%c", m + 65);
                }

                else if (s[k] >= 97 && s[k] <= 122)
                {
                    int n = s[k] - 97;
                    int o = (n + key) % 26;
                    printf("%c", o + 97);
                }

                else
                {
                    printf("%c", s[k]);
                }
            }
            printf("\n");
            return 0;
        }
    }

}