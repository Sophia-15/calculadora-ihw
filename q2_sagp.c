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

#include "helpers.h"

void complementoADois(int decimal);

int main()
{
  complementoADois(100);
  return 0;
}

void complementoADois(int decimal)
{
  char *binario = converterDecimalParaBinario(decimal);
  char *binarioInvertido = inverterCaracteres(binario);
  char sinalBits[16];

  for (int i = 0; i < 16; i++)
  {
    if (i == 0)
    {
      sinalBits[i] = decimal < 0 ? '1' : '0';
    }
    else if (i < strlen(binarioInvertido) + 1)
    {
      sinalBits[i] = binarioInvertido[i - 1];
    }
    else
    {
      sinalBits[i] = '0';
    }
  }

  printf("%s\n", sinalBits);
}