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

    if (charset[index] == code)
    {
      return false;
    }

    // Log any seen alpha chars so that the next time we see them
    // we can prove that this is not an isogram. Ignore spaces and
    // hyphens though as you can have multiple of them.
    if (isalpha(code))
    {
      charset[index] = code;
    }
  }

  return true;
}
