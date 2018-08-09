#include "isogram.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

bool is_isogram(const char phrase[])
{
  if (isblank(phrase[0]))
  {
    return true;
  }

  // If we have an array large enough to hold all possible chars
  // from the ANSII chart then we can use that to check whether or
  // not we've seen a char before.
  char charset[CHAR_MAX];

  for (int i = 0; phrase[i]; i++)
  {
    char code = phrase[i];
    int dec = (int)code;

    if (charset[dec] == code)
    {
      return false;
    }

    // ignore spaces and hyphens as you can have multiple of them
    if (isalpha(code))
    {
      charset[dec] = code;
    }
  }

  return true;
}
