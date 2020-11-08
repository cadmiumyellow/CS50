// Program that calculates how many coins are needed to give change

#include <cs50.h>
#include <stdio.h>

float get_positive_float(string prompt);

int main(void)
{
    float change = get_positive_float("type change amount:\n");
    printf("%.2f\n", change);

    // calculating change in cents
    int coins = change * 100;

    // calculating qtys of each coin denomination
    int quarters = coins / 25;
    int dimes = (coins - (25 * quarters)) / 10;
    int nickels = (coins - (25 * quarters) - (10 * dimes)) / 5;
    int pennies = (coins - (25 * quarters) - (10 * dimes) - (5 * nickels));

    // printing the optimal number of coins needed for change 
    printf("%i\n", quarters + dimes + nickels + pennies);
}

// get positive change from user
float get_positive_float(string prompt)
{
    float a;
    do
    {
        a = get_float("%s", prompt);
    }
    while (a <= 0);
    return a;
}