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

int main()
{
  char *fl = converterRealPF(63.09375, flutuante);
  char *db = converterRealPF(63.09375, duplo);

  printf("%s\n", fl);
  printf("%s\n", db);

  free(fl);
  free(db);

  return 0;
}
