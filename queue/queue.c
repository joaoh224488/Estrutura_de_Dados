#include "queue.h"


queue * create_queue(){
    queue * q;

    q = (queue *) malloc(sizeof(queue));

    q->head = NULL;
    q->tail = NULL;

    return q;
}

int queue_is_empty(queue *q){
    return (q->head == NULL);
}


int push(queue *q, int v){
    node * no;

    no = (node *) malloc(sizeof(node));

    if (!no) return FALSE;

    no->info = v;
    no->next = NULL;


    if (queue_is_empty(q))                  // verifica se a lista já possui ao menos um elemento            
    // adiciona o nó no final
        q->head = no;                      // caso a lista esteja vazia, faz head e tail apontarem para o mesmo nó
    else
        q->tail->next = no;                // adiciona o nó no final, caso exista um predecessor
    
    q->tail = no;                          // tail sempre aponta para o último nó adicionado


    return TRUE;
}


int pop(queue *q){                  // remove o elemento em head

    int n;
    node *no;

    if (queue_is_empty(q)){
        printf("ERRO! Empty queue\n");
        exit(1);
    }

    no = q->head;

    n = no->info;


    q->head = no->next;

    if (queue_is_empty(q))          // se o inicío estiver vazio, o final deve apontar pra NULL també,
        q->tail = NULL;

    free(no);

    return n;
}


void free_queue(queue *q){
    node * no, *aux;

    no = q->head;

    while (no){
        aux = no->next;

        free(no);

        no = aux;
    }

    free(q);
}


void print_queue(queue *q){

    node * no;

    no = q->head;

    while (no){
        printf("%d ", no->info);

        no = no->next;
    }

    printf("\n");
    
    
}