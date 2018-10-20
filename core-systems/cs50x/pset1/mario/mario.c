#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, space, hash; // define local variables

    printf("Specify height in blocks: ");
    height = get_int(); // Takes input from the user to specify height of pyramid

    while (height > 23 || height < 0) // Check whether the user has input a value less than max height (Max is 23)
    {
        printf("That input is invalid (Min is 0, Max is 23) please retry: "); // Ask user for new input
        height = get_int();
    }

    printf("Height: %i\n", height);

    for (row = 0; row < height; row++) // Prints number of rows equal to height specified by user
    {
        for (space = height - 1; row < space; space--) // Pattern for this is spaces are equal to input minus 1 where number of spaces is less than row number
        {
            printf(" ");
        }

        for (hash = 0; hash < row + 2; hash++) // Prints number of hashes according to what row its on.
        {
            printf("#");
        }
        printf("\n"); // prints new line at end of iteration
    }
}
