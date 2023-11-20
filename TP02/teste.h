#include "TravelBooking.h"

/* TAD: Lista (lista encadeada) */
typedef struct lista_passageiro Lista;

typedef struct no_passageiro No;

/* Aloca espaço em memória e retorna uma lista */
Lista *lista_cria();

/* Libera a memória de uma lista previamente criada e atribui NULL ao ponteiro
 * lista. Retorna 1 caso seja possível fazer a liberação e 0 caso a lista
 * informada seja NULL. */
int lista_libera(Lista **lista);

/* Insere um passageiro na lista. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um passageiro com a mesma matricula (nesse caso, o passageiro não pode ser
 * adicionado) e -1 caso a lista ou passageiro sejam NULL
 */
int lista_insere(Lista *lista, Passageiro *passageiro);

/* Remove um passageiro na lista. Retorna o passageiro ou NULL caso a lista esteja vazia ou
 * seja NULL */
Passageiro *lista_retira(Lista *lista);

/* Recupera o primeiro passageiro da lista. Retorna o passageiro ou NULL caso a lista esteja
 * vazia ou seja NULL */
Passageiro *lista_primeiro(Lista *lista);

/* Busca passageiro pelo número de matricula. Retorna o passageiro se este estiver na
 * lista e NULL caso contrário, isto é, (i) lista vazia; (ii) não exista passageiro
 * com a matricula fornecida; ou (iii) a lista seja NULL */
Passageiro *lista_busca(Lista *lista, int matricula);

/* Verifica se a lista está vazia. Retorna 1 se a lista estiver vazia, 0 caso não
 * esteja vazia e -1 se a lista for NULL
 */
int lista_vazia(Lista *lista);

/* Computa a quantidade de passageiros passageiros na lista. Retorna a quantidade de passageiros
 * ou -1, caso a lista for NULL.
 */
int lista_quantidade(Lista *lista);














Passageiro *cria_passageiro(int id,char *nome, char *endereco){
  if(teste_id(id) == 1){
    return NULL;
  }
  Passageiro *passageiro = (Passageiro*) malloc(sizeof(Passageiro));
  passageiro->id = id;
  strcpy(passageiro->nome, nome);
  strcpy(passageiro->endereco, endereco);
  return passageiro;
}
Passageiro remover_passageiro(Passageiro **passageiro){
  if(passageiro != NULL){
    free(*passageiro);
    *passageiro = NULL;
  }
}