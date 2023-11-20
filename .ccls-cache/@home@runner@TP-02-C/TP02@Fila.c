#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  Aluno *aluno;
  struct node *proximo;
};

typedef struct node No;

struct fila {
  No *primeiro;
};

/* Aloca espaço em memória e retorna uma fila */
Fila *fila_cria() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->primeiro = NULL;
  return fila;
  
}

/* Libera a memória de uma fila previamente criada e atribui NULL ao ponteiro
 * fila. Retorna 1 caso seja possível fazer a liberação e 0 caso a fila
 * informada seja NULL. */
int fila_libera(Fila **fila) {
  if (fila != NULL) {
    if ((*fila)->primeiro != NULL) {
      No *aux = (*fila)->primeiro;
      do {
        alu_libera(&aux->aluno);
        aux = aux->proximo;
      } while (aux != NULL);
    }
    free(*fila);
    *fila = NULL;
    return 1;
  }
  return 0;
}

/* Insere um aluno na fila. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a fila ou aluno sejam NULL
 */
int fila_insere(Fila *fila, Aluno *aluno) {
  if(fila == NULL || aluno == NULL){
    return -1;
  }
  int matricula_base;
  int matricula;
  char nome[50];
  char curso[30];
  alu_acessa(aluno, &matricula_base, nome, curso);
  
  if (fila->primeiro == NULL){
    No *n_no = (No*) malloc(sizeof(No));
    n_no -> aluno = aluno;
    n_no->proximo = NULL;
    No **aux = &(fila->primeiro);
    *aux = n_no;
    return 1;
  }
  
  No *no_aux = fila->primeiro;
  No *no_aux_anterior = no_aux;
  while(no_aux != NULL){
    alu_acessa(no_aux->aluno, &matricula, nome, curso);
    if (matricula_base == matricula){
      return 0;
    }
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  No *n_no = (No*) malloc(sizeof(No));
  n_no -> aluno = aluno;
  n_no->proximo = NULL;
  
  No **aux = &(no_aux_anterior->proximo);
  *aux = n_no;
  return 1;
}

/* Remove um aluno na fila. Retorna o aluno ou NULL caso a fila esteja vazia ou
 * seja NULL */
Aluno *fila_retira(Fila *fila) {
  if(fila == NULL){
    return NULL;
  }
  Aluno * aluno_aux = fila->primeiro->aluno;
  No ** aux = &(fila->primeiro);
  *aux = fila->primeiro->proximo;
  return aluno_aux;
}

/* Recupera o primeiro aluno da fila. Retorna o aluno ou NULL caso a fila esteja
 * vazia ou seja NULL */
Aluno *fila_primeiro(Fila *fila) {
  if (fila == NULL || fila->primeiro == 0) {
    return NULL;
  }
  Aluno * aluno_aux = fila->primeiro->aluno;
  return aluno_aux;
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) fila vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a fila seja NULL */
Aluno *fila_busca(Fila *fila, int matricula) {
  if (fila == NULL || fila->primeiro == 0) {
    return NULL;
  }
  
  No *n_aux = fila->primeiro;
  int matricula_comparada;
  char nome[50];
  char curso[30];
  
  do{
    alu_acessa(n_aux->aluno, &matricula_comparada, nome,curso);
    
    if(matricula_comparada == matricula){
      return n_aux->aluno;
    }
    
    n_aux = n_aux->proximo;
    
  }while(n_aux != NULL);
  
  return NULL;
}

/* Verifica se a fila está vazia. Retorna 1 se a fila estiver vazia, 0 caso não
 * esteja vazia e -1 se a fila for NULL
 */
int fila_vazia(Fila *fila) {
  if(fila->primeiro == 0){
    return 1;
  }
  if(fila == NULL){
    return -1;
  }
  return 0;
}

/* Computa a quantidade de alunos alunos na fila. Retorna a quantidade de alunos
 * ou -1, caso a fila for NULL.
 */
int fila_quantidade(Fila *fila) {
  if (fila == NULL) {
    return -1;
  }
  No * no_aux = fila->primeiro;
  No *no_aux_anterior = no_aux;
  int total = 0;
  while(no_aux != NULL){
    total ++;
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  return total;
}