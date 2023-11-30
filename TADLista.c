#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TIPO PRODUTO
typedef struct {
  int codigo;
  char nome[20];
  float preco;
  char descricao[100];
  int quantidade;
} TProduto;

// TIPO CÉLULA
typedef struct celula{
  TProduto item;
  struct celula* prox;
} TCelula;

// TIPO LISTA
typedef struct {
  TCelula* primeiro;
  TCelula* ultimo;
  int tamanho;
} TLista;

// MÉTODOS
void FLVazia(TLista* Lista);
int verificaVazia(TLista Lista);

void lerProduto(TProduto* produto);
void inserir(TProduto x, TLista* Lista);
void excluir(TLista* Lista, TProduto* Produto);
void imprimir(TLista Lista);
void imprimirProduto(TProduto x);
TCelula* pesquisar(TLista Lista, TProduto x);
TCelula* pesquisarPorNome(TLista Lista, TProduto Produto);

int main() {
  TLista lista1, lista2;
  TProduto produto;

  // criando as listas vazias
  FLVazia(&lista1);
  FLVazia(&lista2);

  // verificando se a lista está vazia
  if (!verificaVazia(lista1) && !verificaVazia(lista2)){
    printf("ERRO!\n\n");
    return 0;
  }

  for (int i = 1; i <= 10; i++){
    printf("\nLISTA 1");
    lerProduto(&produto);
    inserir(produto, &lista1);

    printf("\nLISTA 2");
    lerProduto(&produto);
    inserir(produto, &lista2);
  }

  printf("\nLISTA 1:");
  imprimir(lista1);

  printf("\nLISTA 2:");
  imprimir(lista2);

  produto = lista1.primeiro->prox->prox->prox->item;
  excluir(&lista1, &produto);
  produto = lista1.primeiro->prox->item;
  excluir(&lista1, &produto);
  produto = lista1.primeiro->prox->prox->item;
  excluir(&lista1, &produto);
  produto = lista1.primeiro->prox->item;
  excluir(&lista1, &produto);

  printf("\nLISTA 1:");
  imprimir(lista1);

  printf("\nLISTA 2:");
  imprimir(lista2);

  printf("\n=========== Pesquisar produto ===========");
  getchar();
  printf("\nNome: ");
  fflush(stdin);
  fgets(produto.nome, 20, stdin);
  printf("=========================================\n");

  TCelula *pesquisa = pesquisarPorNome(lista1, produto);
  if (pesquisa != NULL)
    imprimirProduto(pesquisa -> prox -> item);
  else
    printf("\nProduto nao cadastrado");
}

void lerProduto(TProduto* produto){
  printf("\n=========== Cadastrar produto ===========");
  printf("\nCodigo: ");
  fflush(stdin);
  scanf("%d", &produto -> codigo);
  getchar();
          
  printf("Nome: ");
  fflush(stdin);
  fgets(produto -> nome, 20, stdin);
          
  printf("Descricao: ");
  fflush(stdin);
  fgets(produto -> descricao, 100, stdin);

  printf("Preco: ");
  fflush(stdin);
  scanf("%f", &produto -> preco);

  printf("Quantidade: ");
  fflush(stdin);
  scanf("%d", &produto -> quantidade);
  printf("=========================================\n");
}

// CRIAR A CÉLULA CABEÇA
void FLVazia(TLista* Lista){
  Lista -> primeiro = (TCelula*) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
  Lista -> tamanho = 0;
}

int verificaVazia(TLista Lista){
  return (Lista.primeiro == Lista.ultimo);
}

void inserir(TProduto x, TLista* Lista){
  Lista -> ultimo -> prox = (TCelula*) malloc(sizeof(TCelula));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> item = x;
  Lista -> ultimo -> prox = NULL;
  Lista -> tamanho++;
}

void excluir(TLista* Lista, TProduto* Produto){
  TCelula *aux1, *aux2;
  aux1 = pesquisar(*Lista, *Produto);
  if (aux1 != NULL){
    aux2 = aux1 -> prox;
    aux1 -> prox = aux2 -> prox;
    *Produto = aux2 -> item;
    if (aux1 == NULL)
      Lista -> ultimo = aux1;
    free(aux2);
    Lista -> tamanho--;
  }
}

void imprimir(TLista Lista){
  TCelula* aux;
  aux = Lista.primeiro -> prox;
  printf("\n----------------------------------------\n");
  while (aux != NULL){
    printf("Codigo: %d\n", aux -> item.codigo);
    printf("Nome: %s", aux -> item.nome);
    printf("Descricao: %s", aux -> item.descricao);
    printf("Preço: %.2f\n", aux -> item.preco);
    printf("Quantidade: %d\n", aux -> item.quantidade);
    printf("----------------------------------------\n");

    aux = aux -> prox;
  }
}

void imprimirProduto(TProduto x){
  printf("\n----------------------------------------\n");
  printf("Codigo: %d\n", x.codigo);
  printf("Nome: %s", x.nome);
  printf("Descricao: %s", x.descricao);
  printf("Preço: %.2f\n", x.preco);
  printf("Quantidade: %d\n", x.quantidade);
  printf("----------------------------------------\n");
}

TCelula* pesquisar(TLista Lista, TProduto x){
  TCelula* aux = Lista.primeiro;
  while (aux -> prox != NULL){
    if (aux -> prox -> item.codigo == x.codigo)
      return aux;
    aux = aux -> prox;
  }
  return NULL;
}

TCelula* pesquisarPorNome(TLista Lista, TProduto x){
  TCelula* aux = Lista.primeiro;
  while (aux -> prox != NULL){
    if (strcmp(aux -> prox -> item.nome, x.nome) == 0)
      return aux;
    aux = aux -> prox;
  }
  return NULL;
}
