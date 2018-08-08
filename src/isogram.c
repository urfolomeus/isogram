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

  char *sortable_phrase = malloc(strlen(phrase) + 1);

  int sortable_phrase_index = 0;

  for (int i = 0; phrase[i]; i++)
  {
    sortable_phrase[sortable_phrase_index] = phrase[i];
    ++sortable_phrase_index;
  }

  qsort(sortable_phrase, strlen(sortable_phrase), 1, compare);

  for (int j = 1; sortable_phrase[j]; j++)
  {
    if (sortable_phrase[j] == sortable_phrase[j - 1])
    {
      free(sortable_phrase);
      return false;
    }
  }

  free(sortable_phrase);

  return true;
}
