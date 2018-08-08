#include "isogram.h"
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return *(const char *)a - *(const char *)b;
}

bool is_isogram(const char phrase[])
{
  if (phrase[0] == '\0')
  {
    return true;
  }

  // ASCII char codes, which C uses to represent chars, run from 0 - 127.
  // This means that we would need an array of 128 chars length to cover all
  // possible codes.
  char charset[128];

  for (int i = 0; phrase[i]; i++)
  {
    char code = phrase[i];
    int dec = (int)code;

    if (charset[dec] == code)
    {
      return false;
    }

    // ignore spaces and hyphens as you can have multiple of them
    if (code != ' ' && code != '-')
    {
      charset[dec] = code;
    }
  }

  return true;
}
