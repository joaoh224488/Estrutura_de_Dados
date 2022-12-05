#include "queue.h"

int main(){

    queue *q;

    q = create_queue();

    push(q, 1);
    push(q, 2);
    push(q, 3);

    print_queue(q);

    pop(q);

    print_queue(q);

    printf("%d \n", q->tail->info);

    free_queue(q);

    return 0;
}