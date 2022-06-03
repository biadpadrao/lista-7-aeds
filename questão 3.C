/* Um provedor de acesso à Internet mantém o seguinte cadastro de clientes: código do cliente, e-mail,
número de horas de acesso, página (S-sim ou N-não). Elaborar um algoritmo que calcule e mostre um relatório contendo o
valor a pagar por cada cliente, sabendo-se que as primeiras 20 horas de acesso é R$35,00 e as horas que
excederam tem o custo de R$2,50 por hora.Para os clientes que têm página, adicionar R$40,00. Inserir um conjunto de registros (máximo 500). */

#include <stdio.h>

int n = 3;

typedef struct Cadastro {
  int codigo;
  char email[50];
  int horas;
  char pag[1];
  float valor;
} Cadastro;

void pagar(Cadastro *c) {
  for (int i = 0; i < n; i++) {
    if (c[i].pag == 'S') {
      if (c[i].horas > 20)
        c[i].valor = (2.5 * (c[i].horas - 20)) + 75; // 2,50 por hora excedida das 20 primeiras + 35 + 40
      else
        c[i].valor = 75; // 35 das 20 horas + 40 da pagina
    }
    if (c[i].pag == 'N') {
      if (c[i].horas > 20)
        c[i].valor = (2.5 * (c[i].horas - 20)) + 35;
      else
        c[i].valor = 35;
    }
  }
}

void registro(Cadastro c[n]) {
  printf("\nValores a serem pagos:");
  for (int i = 0; i < n; i++)
    printf("\n%dº cliente (código %d) = %1.f", i + 1, c[i].codigo, c[i].valor);
}

int main(void) {
  Cadastro v[n];
  for (int i = 0; i < n; i++) {
    printf("\nDigite o código do cliente: ");
    scanf("%d", &v[n].codigo);
    getchar();
    printf("Digite o email: ");
    scanf("%s", v[n].email);
    getchar();
    printf("Digite se possui página (S ou N): ");
    scanf("%s", v[n].pag);
    getchar();
    printf("Digite o número de horas de acesso: ");
    scanf("%d", &v[n].horas);
    getchar();
    v[i].valor = 0;
    pagar(v);
  }
  registro(v);
}
