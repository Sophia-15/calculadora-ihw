#include "helpers.h"

void converterRealFloat(double real);
char *converterRealDouble(double real);

int main()
{
  converterRealFloat(100.09375);
  return 0;
}

void converterRealFloat(double real)
{
  int parteInteira = (int)real;
  double parteFracionada = real - parteInteira;
  int expoente = 8, fracao = 23;
  char binarioSinalExpoente[9];
  char binarioFracionado[24];
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
  while (parteFracionada != 1 && contFracao < 23)
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
  binarioFracionado[23] = '\0';

  printf("%s.", binarioSinalExpoente);
  printf("%s\n", binarioFracionado);
};

char *converterRealDouble(double real) {

};