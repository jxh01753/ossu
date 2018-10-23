// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
  return (int)fraction[0] / fraction[2] * 8;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
  return 1;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
  if ((int)s == 13)
  {
    return true;
  }
  else
  {
    return false;
  }
  return 1;
}
