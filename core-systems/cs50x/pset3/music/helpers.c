// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
  int x = atoi(&fraction[0]);
  int y = atoi(&fraction[2]);
  return ((x * 8) / y);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
  // Get current octave from end of string.

  int octave = note[strlen(note) - 1];
  int n;
  float freq;
  int basefreq = 440;

  // n is the number of keys away from A.
  // initialize base frequency to 440Hz
  // freq is defined as (2 * n / 12) * 440 where n is the number of keys +/- away from A440.
  // freq needs to be a float otherwise theres some quirky rounding stuff in the third octave.

  if ((int)note[0] == 65)
  {
    n = 0;
  }
  else if ((int)note[0] == 66)
  {
    n = 2;
  }
  else if ((int)note[0] == 67)
  {
    n = -9;
  }
  else if ((int)note[0] == 68)
  {
    n = -7;
  }
  else if ((int)note[0] == 69)
  {
    n = -5;
  }
  else if ((int)note[0] == 70)
  {
    n = -4;
  }
  else if ((int)note[0] == 71)
  {
    n = -2;
  }

  // Account for sharps and flats. Sharps are +1, flats are -1 semitone.

  if ((int)note[1] == 35)
  {
    n = n + 1;
  }
  else if ((int)note[1] == 98)
  {
    n = n + -1;
  }

  // Depending on the octave, adjust n by how far away it is from the 4th octave. It's done in sets of 12 keys.

  if ((int)octave == 48)
  {
    n = n + -48;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 49)
  {
    n = n + -36;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 50)
  {
    n = n + -24;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 51)
  {
    n += -12;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 52)
  {
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 53)
  {
    n = n + 12;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 54)
  {
    n = n + 24;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 55)
  {
    n = n + 36;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  else if ((int)octave == 56)
  {
    n = n + 48;
    freq = (pow(2.00, n / 12.00)) * basefreq;
    return round(freq);
  }
  return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
  if (s[0] == '\0')
  {
    return true;
  }
  else
  {
    return false;
  }
  return 1;
}
