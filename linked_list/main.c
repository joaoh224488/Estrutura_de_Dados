#include "linked_list.h"


int main(){
    node * ll;
    int i = 0;

    ll = create_ll();
    
    for (i; i < 11; i++){
        ll_add_back(&ll, i);
    }

    ll_show(&ll);

    ll_remove_at(&ll, 5);

    ll_show(&ll);

    ll_ordered_insert(&ll, 5);

    ll_show(&ll);

    return 0;

}