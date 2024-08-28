/**
 * Calculadora de Conversão Didática
 * Author: Sophia de Araújo Gallindo Pinto - 3° B
 * Created on Aug, 27th 2024
 *
 * Questão 1 - 27/08/2024
 * Questão 2 - 27/08/2024
 * Questão 2 - 28/08/2024
 *
 * Version: 0.0
 *
 */

#include "helpers.h"

enum bits
{
  flutuante = 24,
  duplo = 53
};

void converterRealPF(double real, enum bits bitsFracao);

int main()
{
  converterRealPF(100.09375, flutuante);
  converterRealPF(100.09375, duplo);
  return 0;
}

void converterRealPF(double real, enum bits bitsFracao)
{
  int parteInteira = (int)real;
  double parteFracionada = real - parteInteira;
  char binarioSinalExpoente[9];
  char binarioFracionado[bitsFracao];
  char *binario = converterDecimalParaBinario(parteInteira);

  binarioSinalExpoente[0] = real > 0 ? '0' : '1';

  // parte inteira
  int contExpoente = 0;
  for (int i = 1; i < 9; i++)
  {
    if (i <= (8 - (strlen(binario))))
    {
      binarioSinalExpoente[i] = '0';
    }
    else
    {
      binarioSinalExpoente[i] = binario[contExpoente];
      contExpoente++;
    }
  }
  binarioSinalExpoente[8] = '\0';

  // parte fracionada
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

  printf("%s.", binarioSinalExpoente);
  printf("%s\n", binarioFracionado);
};
