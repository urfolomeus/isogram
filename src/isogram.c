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
    int code = phrase[i];

    if (charset[code] == code)
    {
      return false;
    }

    // Log any seen alpha chars as that way the next time we test
    // we can prove that this is not an isogram. Ignore spaces and
    // hyphens though as you can have multiple of them.
    if (isalpha(code))
    {
      charset[code] = code;
    }
  }

  return true;
}
