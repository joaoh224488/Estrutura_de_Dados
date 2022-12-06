#include "deque.h"


int main(){

    deque * d;

    d = create_deque();
    /*

    push_front(d, 1);
    push_front(d, 2);
    push_front(d, 3);
    push_front(d, 4);

    push_back(d, 5);
    push_back(d, 6);
    push_back(d, 7);

    printf("Fila cheia: \n\t\t");
    print_deque(d);

    printf("Pop front: \n\t\t");
    pop_front(d);
    print_deque(d);

    printf("Pop back: \n\t\t");
    pop_back(d);
    print_deque(d);
    */
   push_front(d, 1);
   print_deque(d);



    return 0;
}