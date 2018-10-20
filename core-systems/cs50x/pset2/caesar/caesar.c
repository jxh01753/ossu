#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
  // Error handling for invalid arguments.
  if (argc != 2)
  {
    printf("Invalid argument.\n");
    exit(1);
  }

  // Convert key string to key integer
  int key = atoi(argv[1]);

  // Collect user input
  printf("plaintext: ");
  string restext = get_string();

  // Loop over the string
  for (int i = 0, n = strlen(restext); i < n; i++)
  {
    // if the character is a valid letter..
    if (isalpha(restext[i]))
    {
      // Check if the character is uppercase here. If so..
      if (restext[i] >= 65 && restext[i] <= 90)
      {
        // Reset it so the scale goes from 0 - 25. Then implement caesar forumlae where c = p + k % 26. Add 65 to bring it back to uppercase ASCII register.
        restext[i] = (((restext[i] - 65) + key) % 26) + 65;
      }
      else if (restext[i] >= 97 && restext[i] <= 122)
      {
        // Same for lower case!
        restext[i] = (((restext[i] - 97) + key) % 26) + 97;
      }
    }
  }
  // Send it back to user.
  printf("ciphertext: %s\n", restext);
  printf("\n");
  return 0;
}