#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverterString(char *string)
{
  char *stringReversa = (char *)malloc((strlen(string) + 1) * sizeof(char));

  for (int i = strlen(string) - 1; i >= 0; i--)
  {
    stringReversa[strlen(string) - 1 - i] = string[i];
  }

  return stringReversa;
}

char coverterHexaEquivalente(int num)
{
  return 'A' + (num - 10);
}