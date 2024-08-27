// 27/08

#include <stdio.h>
#include <string.h>
#include "helpers.h"

void converterDecimalParaBinario(int decimal);
void converterDecimalParaOctal(int decimal);
void converterDecimalParaHexa(int decimal);
void converterDecimalParaBCD(int decimal);

int main()
{
  // converterDecimalParaBinario(100);
  // converterDecimalParaOctal(100);
  // converterDecimalParaHexa(300);
  converterDecimalParaBCD(300);
  return 0;
}

void converterDecimalParaBinario(int decimal)
{
  int resto;
  int quociente = decimal;
  char binarioContrario[100] = "", *binario, strResto[100];

  while (quociente != 0)
  {
    resto = quociente % 2;
    quociente = quociente / 2;

    sprintf(strResto, "%d", resto);
    strcat(binarioContrario, strResto);
  }

  binario = reverterString(binarioContrario);

  printf("%s\n", binario);
}

void converterDecimalParaOctal(int decimal)
{
  int resto;
  int quociente = decimal;
  char octalContrario[100] = "", *octal, strResto[100];

  while (quociente != 0)
  {
    resto = quociente % 8;
    quociente = quociente / 8;

    sprintf(strResto, "%d", resto);
    strcat(octalContrario, strResto);
  }

  octal = reverterString(octalContrario);

  printf("%s\n", octal);
}

void converterDecimalParaHexa(int decimal)
{
  int resto;
  int quociente = decimal;
  char hexaContrario[100] = "", *hexa, strResto[100];

  while (quociente != 0)
  {
    resto = quociente % 16;
    quociente = quociente / 16;

    if (resto >= 10 && resto <= 15)
    {
      char hexaEquivalente = coverterHexaEquivalente(resto);
      char hexaEquivalenteStr[2] = {hexaEquivalente, '\0'};
      strcat(hexaContrario, hexaEquivalenteStr);
    }
    else
    {
      sprintf(strResto, "%d", resto);
      strcat(hexaContrario, strResto);
    }
  }

  hexa = reverterString(hexaContrario);

  printf("%s\n", hexa);
}

void converterDecimalParaBCD(int decimal)
{
  char *bcdConvertido[100];
  int resto;
  int cont = 0;

  char *bcd[] = {
      "0000\t",
      "0001\t",
      "0010\t",
      "0011\t",
      "0100\t",
      "0101\t",
      "0110\t",
      "0111\t",
      "1000\t",
      "1001\t"};

  while (decimal > 0)
  {
    resto = decimal % 10;
    decimal = decimal / 10;

    bcdConvertido[cont] = bcd[resto];
    cont++;
  }

  for (int i = cont - 1; i >= 0; i--)
  {
    printf("%s", bcdConvertido[i]);
  }

  printf("\n");
}