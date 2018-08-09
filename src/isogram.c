#include "isogram.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
  if (isblank(phrase[0]))
  {
    return true;
  }

  // If we have an array large enough to hold all possible chars
  // from the ANSII chart then we can use that to check whether or
  // not we've seen a char before.
  char charset[CHAR_MAX] = {0};

  for (int i = 0; phrase[i]; i++)
  {
    int code = phrase[i];

    if (charset[code] == code)
    {
      return false;
    }

    // Log any seen alpha chars so that the next time we see them
    // we can prove that this is not an isogram. Store both lower
    // and upper case versions so that we can recognise the same
    // char in either case. Ignore spaces and hyphens though as
    // you can have multiple of them.
    if (isalpha(code))
    {
      int lower = tolower(code);
      int upper = toupper(code);

      charset[lower] = lower;
      charset[upper] = upper;
    }
  }

  return true;
}
