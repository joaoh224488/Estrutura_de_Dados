#include "list.h"


int main(){

    List l;
    int size;
    size = 8;

    create_list(&l, size);

    for (int i = 0; i < 10; i++){
        push_back(&l, i);
    }



    show(&l);

    free_list(&l);


    return 0;
}