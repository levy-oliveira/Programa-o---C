#include "ListaP.h"
#include <stdio.h>
#include <stdlib.h>

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

Lista *lista_cria() {
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->primeiro = NULL;
  return lista;
}

int lista_libera(Lista **lista) {
  if (lista == NULL) {
    return 0;
  }
  free(*lista);
  *lista = NULL;
  return 1;
}

int lista_insere(Lista *lista, Passageiro *passageiro) {
  if(lista == NULL || passageiro == NULL){
    return -1;
  }
  int matricula_base;
  int matricula;
  char nome[50];
  char curso[30];
  alu_acessa(passageiro, &matricula_base, nome, curso);
  
  if (lista->primeiro == NULL){
    No *n_no = (No*) malloc(sizeof(No));
    n_no -> passageiro = passageiro;
    n_no->proximo = NULL;
    No **aux = &(lista->primeiro);
    *aux = n_no;
    return 1;
  }
  
  No *no_aux = lista->primeiro;
  No *no_aux_anterior = no_aux;
  while(no_aux != NULL){
    alu_acessa(no_aux->passageiro, &matricula, nome, curso);
    if (matricula_base == matricula){
      return 0;
    }
    no_aux_anterior = no_aux;
    no_aux = no_aux->proximo;
  }
  No *n_no = (No*) malloc(sizeof(No));
  n_no -> passageiro = passageiro;
  n_no->proximo = NULL;
  
  No **aux = &(no_aux_anterior->proximo);
  *aux = n_no;
  return 1;
}