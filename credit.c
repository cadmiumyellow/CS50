#include <stdio.h>
#include <cs50.h>

long get_positive_long(string prompt);

int main(void)

{
    long z = get_positive_long("Please type card number:");

// taking separate digits from long
    int a = z % 10;
    int b = z / 10 % 10;
    int c = z / 100 % 10;
    int d = z / 1000 % 10;
    int e = z / 10000 % 10;
    int f = z / 100000 % 10;
    int g = z / 1000000 % 10;
    int h = z / 10000000 % 10;
    int i = z / 100000000 % 10;
    int j = z / 1000000000 % 10;
    int k = z / 10000000000 % 10;
    int l = z / 100000000000 % 10;
    int m = z / 1000000000000 % 10;
    int n = z / 10000000000000 % 10;
    int o = z / 100000000000000 % 10;
    int p = z / 1000000000000000 % 10;

// calculating checksum

    int y = (b * 2 % 10) + (b * 2 / 10) + (d * 2 % 10) + (d * 2 / 10) + (f * 2 % 10) + (f * 2 / 10) + (h * 2 % 10) + (h * 2 / 10) + (j * 2 % 10) + (j * 2 / 10) + (l * 2 % 10) + (l * 2 / 10) + (n * 2 % 10) + (n * 2 / 10) + (p * 2 % 10) + (p * 2 / 10);

    int w = y + a + c + e + g + i + k + m + o;

// printing the results of the check
    if (w % 10 == 0 && p == 5 && o >= 1 && o <= 5)
    {
        printf("MASTERCARD\n");
    }

    else if (w % 10 == 0 && p == 0 && o == 3 && (n == 4 || n == 7))
    {
        printf("AMEX\n");
    }

    else if (w % 10 == 0 && p == 4)
    {
        printf("VISA\n");
    }

    else if (w % 10 == 0 && p == 0 && o == 0 && n == 0 && m == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

}

// prompt user for positive long
long get_positive_long(string prompt) 
{
    long number;
    do
    {
        number = get_long("%s", prompt);
    }
    while (number < 1);
    return number;
}