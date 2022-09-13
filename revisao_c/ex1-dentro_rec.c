#include <stdio.h>

#define TRUE 1
#define FALSE 0


int dentro_ret (int x0, int y0, int x1, int y1, int x, int y);

int main(){



    return 0;
}

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y){

    if (((x0 <= x)  && (x <= x1)) && ((y0 <= y)  && (y <= y1))){

        return TRUE;
    }

    else 
        return FALSE;
}
