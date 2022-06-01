/* Escreva um programa para cadastrar dois clientes de uma loja. As informações necessárias são:
nome, endereço e telefone. Deve ser usada uma estrutura de registro para a construção deste cadastro */

#include <stdio.h>

int n = 2;

typedef struct Cadastro {
char nome [50];
char endereco [200];
int telefone;
} Cadastro;

int main(void) {
  Cadastro V[n];
  for (int i = 0; i < n; i++) {
    printf ("\nNome do cliente: ");
    fgets (V[i].nome,50,stdin);
    printf ("Endereço do cliente: ");
    fgets (V[i].endereco,200,stdin);
    printf ("Telefone do cliente: ");
    scanf ("%d", &V[i].telefone);
    getchar();
  }
  printf ("\n\nInformações dos cadastrados:\n");
  for (int i = 0; i < n; i++) {
    printf ("\n%d° cliente:\n Nome: %s Endereço: %s Telefone: %d\n", i+1, V[i].nome, V[i].endereco, V[i].telefone);
  }
}
