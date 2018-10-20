#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change = 0; // define local variables
    int cents = 0;
    int quarter = 25;
    int dime = 10;
    int nickle = 5;
    int penny = 1;
    int count = 0;

    printf("O hai! How much change is owed?: "); // getinput from user
    change = get_float();

    while (change < 0)
    {
        printf("How much change is owed?: "); // check if input is valid (i.e. input cannot be less than 0)
        change = get_float();
    }

    printf("%.2f \n", change); // print user output

    change = change * 100;
    cents = round(change);                        // convert floating point amount to cents for calculation

        while (cents >= quarter)          // Begin the greedy cashier process
        {
            count++;
            cents = cents - quarter;
        }
        while (cents >= dime)
        {
            count++;
            cents = cents - dime;
        }
        while (cents >= nickle)
        {
            count++;
            cents = cents - nickle;
        }
        while (cents >= penny)
        {
            count++;
            cents = cents - penny;
        }

    printf("%i \n", count); // print number of coins used
}