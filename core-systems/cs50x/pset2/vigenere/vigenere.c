#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  // Error handling for multiple arguments.
  if (argc != 2)
  {
    printf("Invalid argument. Please enter a one word keyphrase!\n");
    return 1;
  }

  // Declare for efficiency later on. Keylength is used twice.
  // Keyshift is to track the k^j part of the equation.

  int keylength = strlen(argv[1]);
  int keyshift = 0;

  for (int i = 0, n = keylength; i < n; i++)
  {

    // Error handling for digits in arguments.

    if (!isalpha(argv[1][i]))
    {
      printf("Invalid characters in keyphrase! Please try again. \n");
      return 1;
    }
    else
    {
      // Convert the character to the 0-25 register here.
      if (isupper(argv[1][i]))
      {
        argv[1][i] = argv[1][i] - 65;
      }
      else if (islower(argv[1][i]))
      {
        argv[1][i] = argv[1][i] - 97;
      }
    }
  }

  // Get user input

  printf("plaintext: ");
  string restext = get_string();

  for (int i = 0, o = strlen(restext); i < o; i++)
  {
    // Check if it is alphabetical.
    if (isalpha(restext[i]))
    {
      if (isupper(restext[i]))
      {
        // Do your magic
        restext[i] = (((restext[i] - 65) + argv[1][keyshift]) % 26) + 65;
        keyshift++;
      }
      else if (islower(restext[i]))
      {
        restext[i] = (((restext[i] - 97) + argv[1][keyshift]) % 26) + 97;
        keyshift++;
      }
    }

    // If you're at the end of the key, send it back to the start.
    if (keyshift == keylength)
    {
      keyshift = 0;
    }
  }

  // Return to user.
  printf("ciphertext: %s", restext);
  printf("\n");
  return 0;
}