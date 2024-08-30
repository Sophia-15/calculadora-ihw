/**
 * Calculadora de Conversão Didática
 * Author: Sophia de Araújo Gallindo Pinto - 3° B
 * Created on Aug, 27th 2024
 *
 * Questão 1 - 27/08/2024
 * Questão 2 - 27/08/2024
 * Questão 3 - 28/08/2024
 *
 * Version: 0.0
 *
 */

#include <stdio.h>
#include <string.h>
#include "helpers.h"

int main()
{
  char *binario, *octal, *hexa, **bcd;

  binario = converterDecimalParaBinario(100);
  octal = converterDecimalParaOctal(100);
  hexa = converterDecimalParaHexa(300);
  bcd = converterDecimalParaBCD(300);

  printf("\nBinário: %s\n", binario);
  printf("Octal: %s\n", octal);
  printf("Hexadecimal: %s\n", hexa);
  printf("BCD: ");

  for (int i = strlen(*bcd) - 1; i >= 0; i--)
  {
    if (bcd[i] != NULL)
    {
      printf("%s ", bcd[i]);
    }
  }

  printf("\n");

  free(binario);
  free(octal);
  free(hexa);
  free(bcd);

  return 0;
}
