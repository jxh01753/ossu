#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("How many minutes do you spend in the shower?: ");
    int minutes = get_int(); // Take input from the user

    int bottles = minutes * 12; // Multiply input by number of bottles equivalent to a minutes usage

    printf("Minutes: %i\n", minutes); // Print results
    printf("Bottles: %i\n", bottles);
}