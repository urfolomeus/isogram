#include "isogram.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET 26
#define OFFSET 'a'

bool is_isogram(const char phrase[])
{
  // If we have an array large enough to hold the lower case chars
  // from the ANSII chart then we can use that to check whether or
  // not we've seen a char before.
  int charset[ALPHABET] = {0};

  for (int i = 0; phrase[i]; i++)
  {
    if (!isalpha(phrase[i]))
    {
      continue;
    }

    int code = tolower(phrase[i]);
    int index = code - OFFSET;

    if (charset[index] > 0)
    {
      return false;
    }

    charset[index]++;
  }

  return true;
}
