#include <stdio.h>
#include <time.h>

int anoBissexto(int validarAno)
{
  return ((validarAno % 4 == 0 && validarAno % 100 != 0) ||
          (validarAno % 400 == 0));
}

void idadeUsuario(int diaNasc, int mesNasc, int anoNasc)
{
  // capturando data atual
  int diaAtual, mesAtual, anoAtual;
  struct tm *data_atual;
  time_t tempo;
  time(&tempo);
  data_atual = localtime(&tempo);

  diaAtual = data_atual->tm_mday;
  mesAtual = data_atual->tm_mon + 1;
  anoAtual = data_atual->tm_year + 1900;

  int day, month, year;
  day = diaAtual - diaNasc;
  month = mesAtual - mesNasc;
  year = anoAtual - anoNasc;

  if (day < 0)
  {
    day = 30 + day; // deveria ser o fim do mes + (- dias)
    month--;
  }

  if (month < 0)
  {
    month = 12 + month;
    year--;
  }

  printf("Você tem %d anos, %d meses e %d dias de vida.", year, month, day);
}

int main()
{
  int dia, mes, ano;

  do
  {
    printf("Digite a sua data de nascimento\n(DATA / MES / ANO):");
    scanf("%d %d %d", &dia, &mes, &ano);

    if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12))
    {
      printf("[ERRO] Data inválida, insira novamente!\n");
    }
  } while ((dia < 1 || dia > 31) || (mes < 1 || mes > 12));

  if ((dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)))
  {
    printf("O mês %d não pode ter mais de 30 dias\n", mes);
    return 0;
  }

  if (mes == 2)
  {
    if ((dia > 29 && anoBissexto(ano)))
    {
      printf("[ERRO] Fevereiro não pode ter mais de 29 dias em anos bissextos.");
      return 0;
    }
    else if ((!anoBissexto(ano) && dia > 28))
    {
      printf("[ERRO] Fevereiro tem apenas 28 dias em anos não bissextos.");
      return 0;
    }
  }
  idadeUsuario(dia, mes, ano);
  return 0;
}