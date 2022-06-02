/* Uma determinada biblioteca possui obras de ciências exatas, humanas e biológicas, totalizando 1500 volumes, distribuídos em cada uma das áreas.
O proprietário resolveu agrupar as informações de cada livro no seguinte registro:
- Código de catalogação
- Doação (S/N)
- Nome da obra
- Nome do autor
- Editora
- Área
Construir um algoritmo que:
a) cadastre todos os volumes de cada uma das áreas em três vetores distintos
b) permita ao usuário fazer consulta às informações cadastradas fornecendo o código de catalogação e a área. 
Existindo tal livro as informações são exibidas, caso contrário enviar mensagem de aviso. A consulta se repete até que o usuário digite código finalizador -1. */

#include <stdio.h>

typedef struct Livros {
  int codigo;
  char nome[50];
} Livro;

int n = 3;

void cadastrar(Livro L[], int p) {
  printf("Código e nome:\n");
  scanf("%d", &L[p].codigo);
  scanf("%s", L[p].nome);
  getchar();
}

void imprimir(Livro *L, int cd) {
  for (int i = 0; i < n; i++) {
    if (L[i].codigo == cd)
      printf("%d - %s\n", L[i].codigo, L[i].nome);
  }
}

int main(void) {
  Livro B[n], H[n], E[n];
  int b = 0, h = 0, e = 0;
  char area;
  while (b < n && e < n && h < n) {
    printf("Area:\n");
    scanf("%c", &area);
    getchar();
    switch (area) {
    case 'b':
      cadastrar(B, b++);
      break;
    case 'e':
      cadastrar(E, e++);
      break;
    case 'h':
      cadastrar(H, h++);
      break;
    default:
      printf("Área inválida\n");
      break;
    }
  }
  printf("Pesquisa area");
  scanf("%c", &area);
  int codigo;
  printf("Pesquisa codigo");
  scanf("%d", &codigo);
  getchar();
  switch (area) {
  case 'b':
    imprimir(B, codigo);
    break;
  case 'e':
    imprimir(E, codigo);
    break;
  case 'h':
    imprimir(H, codigo);
    break;
  default:
    printf("Área inválida\n");
    break;
  }
}
