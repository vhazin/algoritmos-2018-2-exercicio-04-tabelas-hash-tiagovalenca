#include <stdio.h>
#include <stdlib.h>

int dispersao(int valor, int hash) {
    int i = valor % hash;
    return i;
}

typedef struct Node 
{
    int valor;
    struct Node *next;
} Node;

void adicionar(Node *tabela[], Node *node, int pos){
  if(tabela[pos] == NULL){
    tabela[pos] = node;
  }else{
    Node *temp;
    temp = malloc(sizeof(Node));
    temp = tabela[pos];
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = node;
  }
  return;
}

void printTabela(Node *tabela[], int tamanho){
  for(int i = 0; i < tamanho; i++){
    Node *temp = tabela[i];
    printf("%d -> ", i);;
    while (temp != NULL){
        printf("%d -> ", temp->valor);
        temp = temp -> next;
    };
    printf("\\\n");
  }
  return;
}


int main(void) {
  int iteracoes;
  scanf("%d", &iteracoes);

  while(iteracoes--){
    int tamanho, chaves;
    scanf("%d %d", &tamanho, &chaves);

    Node *tabelaHash[tamanho];
    for (int i = 0; i < tamanho; i++)
      tabelaHash[i] = NULL;

    while(chaves--){
      Node *node;
      node = malloc(sizeof(Node));
      int valor;

      scanf("%d", &valor);
      node->valor = valor;
      node->next = NULL;

      int chave = dispersao(valor, tamanho);
      adicionar(tabelaHash, node, chave);
    }

    printTabela(tabelaHash, tamanho);

    if(iteracoes){
      printf("\n");
    }
  }
  return 0;
}
