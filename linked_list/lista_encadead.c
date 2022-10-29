#include "lista_encadeada.h"

#define TRUE 1
#define FALSE 0

node * create_ll(){
    return NULL;
}

// A lista começa apontando para nulo

int ll_size(node **ll){
    node *p;
    int i = 0;

    for (p = *ll; p != NULL; p = p->next){
        i++;
    }

    return i;
}

int ll_add_begin(node **ll, int v){
    //cria node
    node * new;

    new = (node *) malloc(sizeof(node));
    if (!new) return (FALSE);

    //preenche node

    new->info = v;
    new->next = *ll;

    // insere node
    *ll = new;

    return TRUE;

}

int ll_show(node **ll){

    node *p;
    
    if (ll_is_clear(ll)) {
        printf("[ ]\n");
        return TRUE;
    }


    putchar('[');
    for(p = *ll; p->next != NULL; p = p->next){
        printf("  %d,", p->info);
    }

    printf("  %d  ]\n", p->info);

    return TRUE;

}

int ll_is_clear(node **ll){
    return (*ll == NULL);
}

node* ll_search(node **ll, int v){
    node *p;

    for(p = *ll; p != NULL; p = p->next){
        if (p->info == v) return p;
    }

    return NULL;
}


int ll_add_back(node **ll, int v){
    node *new;
    node *p;

    new = (node *) malloc(sizeof(node));
    
    if (!new) return (FALSE);

    new->info = v;
    new->next = NULL;

    if (ll_is_clear(ll)) *ll = new;

    else{
        for (p = *ll; p->next != NULL; p = p->next);

        p->next = new;
    }

    return TRUE;
}
int ll_insert_at(node **ll, int pos, int v){

    node *new;
    node *p;
    node *q;
    int i = 0;
    int size;

    size = ll_size(ll);

    if (size == 0) return FALSE;

    if (pos < 0 || pos > size) return FALSE;

    if (pos == 0) return ll_add_begin(ll, v);

    if (pos == size) return ll_add_back(ll, v);

    for (p = *ll; p != NULL; p = p->next){
        if (i == pos - 1) break;
        i++;
    }
    if (p == NULL) return FALSE;

    q = p->next;

    new = (node *) malloc(sizeof(node));

    if (!new) return FALSE;

    new->info = v;
    new->next = q;

    p->next = new;

    return TRUE;
}

int ll_ordered_insert(node **ll, int v){
    node *new;
    node *p;
    node *q;

    new = (node *) malloc(sizeof(node));

    if (!new) return FALSE;

    new->info = v;
    new->next = NULL;

    if (ll_is_clear(ll)) *ll = new;

    else{
        for (p = *ll; p != NULL; p = p->next){
            if (p->info > v) break;
            q = p;
        }

        if (p == *ll) return ll_add_begin(ll, v);

        if (p == NULL) return ll_add_back(ll, v);

        new->next = p;
        q->next = new;
    }

    return TRUE;
}

int ll_remove(node **ll, int v){
    node *p, *q;

    if (ll_is_clear(ll)) return FALSE;

    if(((*ll)->info == v) && (*ll)->next == NULL){
        p = *ll;
        free(p);

        *ll = NULL;

        return TRUE;

    }

    if ((*ll)->info == v){
        p = *ll;
        *ll = (*ll)->next;
        free(p);
        return TRUE;
    }

    for (p = *ll; p->next != NULL; p = p->next){
        if (p->next->info == v){
            q = p->next;
            p->next = q->next;
            free(q);
            return TRUE;
        }
    }

    return FALSE;
}

void ll_free(node **ll){
    node *p, *q;

    for (p = *ll; p != NULL; p = q){
        q = p->next;
        free(p);
    }

    *ll = NULL;
}

int ll_remove_begin(node **ll){
    node *p;

    if (ll_is_clear(ll)) return FALSE;

    if ((*ll)->next == NULL){
        p = *ll;
        free(p);
        *ll = NULL;
        return TRUE;
    }

    p = *ll;
    *ll = (*ll)->next;
    free(p);

    return TRUE;
}

int ll_remove_back(node **ll){
    node *p, *q;

    if (ll_is_clear(ll)) return FALSE;
    
    if ((*ll)->next == NULL){
        p = *ll;
        free(p);
        *ll = NULL;
        return TRUE;
    }

    for (p = *ll; p->next->next != NULL; p = p->next);

    q = p->next;
    
    p->next = NULL;

    free(q);
    

    return TRUE;
}

int ll_remove_at(node **ll, int pos){
    node *p, *q;
    int i = 0;
    int size;

    size = ll_size(ll);

    if (size == 0) return FALSE;

    if (pos < 0 || pos > size) return FALSE;

    if (pos == 0) return ll_remove_begin(ll);

    if (pos == size) return ll_remove_back(ll);

    for (p = *ll; p != NULL; p = p->next){
        if (i == pos - 1) break;
        i++;
    }
    if (p == NULL) return FALSE;
    q = p->next;

    p->next = q->next;

    free(q);

    return TRUE;
}


