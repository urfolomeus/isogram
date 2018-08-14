#include "isogram.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define LOWER_CASE_LETTERS 26
#define OFFSET 'a'

bool is_isogram(const char phrase[])
{
  // If we have an array large enough to hold the lower case chars
  // from the ANSII chart then we can use that to check whether or
  // not we've seen a char before.
  char charset[LOWER_CASE_LETTERS] = {0};

  for (int i = 0; phrase[i]; i++)
  {
    int code = tolower(phrase[i]);
    int index = code - OFFSET;

    if (charset[index] > 0)
    {
      return false;
    }

    // Count any seen alpha chars so that the next time we see them
    // we can prove that this is not an isogram.
    if (isalpha(code))
    {
      charset[index]++;
    }
  }

  return true;
}
