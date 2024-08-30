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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum bits
{
  flutuante = 24,
  duplo = 53
};

char *reverterString(char *string)
{
  printf("Revertendo a string...\n");
  sleep(1);
  char *stringReversa = (char *)malloc((strlen(string) + 1) * sizeof(char));

  for (int i = strlen(string) - 1; i >= 0; i--)
  {
    stringReversa[strlen(string) - 1 - i] = string[i];
  }

  return stringReversa;
}

char coverterHexaEquivalente(int num)
{
  printf("Convertendo valor decimal >= 10 para hexadecimal...\n");
  sleep(1);
  char hexa = 'A' + (num - 10);

  return hexa;
}

char *inverterCaracteres(char *binario)
{
  printf("Invertendo bits do binário (complemento de 1)...\n");
  sleep(1);
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
  printf("Convertendo decimal %d para binário...\n", decimal);
  sleep(1);
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
  printf("Convertendo decimal %d para octal...\n", decimal);
  sleep(1);
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
  printf("Convertendo decimal %d para hexadecimal...\n", decimal);
  sleep(1);
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
  printf("Convertendo decimal %d para BCD...\n", decimal);
  sleep(1);
  char **bcdConvertido = (char **)malloc(60 * sizeof(char *));
  int resto;
  int cont = 0;

  char *bcd[] = {
      "0000",
      "0001",
      "0010",
      "0011",
      "0100",
      "0101",
      "0110",
      "0111",
      "1000",
      "1009"};

  while (decimal > 0)
  {
    resto = decimal % 10;
    decimal = decimal / 10;

    bcdConvertido[cont] = bcd[resto];
    printf("Dígito %d convertido para BCD: %s\n", resto, bcdConvertido[cont]);
    sleep(1);
    cont++;
  }

  return bcdConvertido;
}

// corrigir
char *converterRealPF(double real, enum bits bitsFracao)
{
  printf("Iniciando conversão de número real (%f) para ponto flutuante...\n", real);
  sleep(1);

  int parteInteira = (int)real;
  double parteFracionada = real - parteInteira;

  char binarioSinalExpoente[9];
  char binarioFracionado[bitsFracao + 1];
  char *binario = converterDecimalParaBinario(parteInteira);
  printf("Converterndo parte inteira em binário...\n");
  sleep(1);

  char *numCompletoNaoFormatado = (char *)malloc(sizeof(char) * bitsFracao + 10);

  binarioSinalExpoente[0] = real > 0 ? '0' : '1';
  printf("Adicionando bit de sinal...\n");
  sleep(1);

  int contExpoente = 0;
  int contUm = 0;
  for (int i = 1; i < 9; i++)
  {
    if (i <= (8 - (strlen(binario))))
    {
      binarioSinalExpoente[i] = '0';
    }
    else
    {

      if (binarioSinalExpoente[i] == '.')
      {
        binarioSinalExpoente[i + 1] = binario[contExpoente];
      }
      else
      {
        binarioSinalExpoente[i] = binario[contExpoente];
      }

      contExpoente++;
    }
  }
  binarioSinalExpoente[8] = '\0';
  printf("Expoente em binário...\n");
  sleep(1);

  int contFracao = 0;
  while (parteFracionada != 1 && contFracao < bitsFracao - 1)
  {
    parteFracionada = parteFracionada * 2;

    if (parteFracionada >= 1)
    {
      binarioFracionado[contFracao] = '1';
      parteFracionada = parteFracionada - 1;
    }
    else
    {
      binarioFracionado[contFracao] = '0';
    }

    contFracao++;
  }
  binarioFracionado[bitsFracao - 1] = '\0';
  printf("Parte fracionada em binário...\n");
  sleep(1);

  strcpy(numCompletoNaoFormatado, binarioSinalExpoente);
  strcat(numCompletoNaoFormatado, binarioFracionado);

  char *numCompletoFormatado = (char *)malloc(strlen(numCompletoNaoFormatado) + 2);

  int pontoInserido = 0;

  printf("Transformando em notação científica...\n");
  for (int i = 0; i < strlen(numCompletoNaoFormatado); i++)
  {
    numCompletoFormatado[i + pontoInserido] = numCompletoNaoFormatado[i];
    if (numCompletoNaoFormatado[i] == '1' && !pontoInserido)
    {
      numCompletoFormatado[i + 1] = '.';
      pontoInserido = 1;
    }
  }
  numCompletoFormatado[strlen(numCompletoNaoFormatado) + pontoInserido] = '\0';

  return numCompletoFormatado;
}
