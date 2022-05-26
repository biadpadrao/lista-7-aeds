/* Uma pessoa cadastrou um conjunto de 15 registros contendo o nome da loja, telefone e preço de um eletrodoméstico.
Desenvolver um algoritmo que permita exibir qual foi a média dos preços cadastrados e uma relação contendo o nome e
o telefone das lojas cujo preço estava abaixo da média. */

#include <stdio.h> 

int n = 15;

typedef struct Loja {
  char nome[100];
  int telefone;
  int preco;
} Loja;

void media(Loja l[n]) {
  int soma = 0, media = 0;
  for (int i = 0; i < n; i++) {
    soma += l[i].preco;
  }
  media = soma / n;
  printf("\nMédia dos preços: %d reais\n", media);
  printf("\nDados dos que estão abaixo da média:\n\n");
  for (int i = 0; i < n; i++) {
    if (media > l[i].preco)
      printf("Nome: %s\nTelefone: %d\n\n", l[i].nome, l[i].telefone);
  }
}

int main(void) {
  Loja v[n];
  for (int i = 0; i < n; i++) {
    printf("\nDigite o nome da sua loja: ");
    scanf("%s", v[i].nome);
    printf("Digite o telefone da sua loja: ");
    scanf("%d", &v[i].telefone);
    printf("Digite o preco do eletrodomestico da sua loja: ");
    scanf("%d", &v[i].preco);
  }
  media(v);
}
