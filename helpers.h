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

char *inverterCaracteres(char *binario)
{
  char *binarioInvertido = (char *)malloc((strlen(binario) + 1) * sizeof(char));
  int umCont = 0;

  for (int i = strlen(binario) - 1; i >= 0; i--)
  {
    if (!umCont)
    {
      if (binario[i] == '1')
      {
        umCont = 1;
      }
      binarioInvertido[strlen(binario) - 1 - i] = binario[i];
    }
    else
    {
      binarioInvertido[strlen(binario) - 1 - i] = binario[i] == '1' ? '0' : '1';
    }
  }

  return binarioInvertido;
}

char *converterDecimalParaBinario(int decimal)
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

  return binario;
}

char *converterDecimalParaOctal(int decimal)
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

  return octal;
}

char *converterDecimalParaHexa(int decimal)
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

  return hexa;
}

char **converterDecimalParaBCD(int decimal)
{
  char **bcdConvertido = (char **)malloc(60 * sizeof(char *));
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

  return bcdConvertido;
}