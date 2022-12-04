#include "binary_tree.h"


node * create_empty_tree(){
    return NULL;
}

int empty_tree(node *root){
    return root == NULL;
}

node * create_tree(int v, node *left, node *right){
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) return 0;
    new_node->info = v;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

int height_tree(node *root){
    int h_left, h_right;

    if(!root) return 0;

    h_left = height_tree(root->left);
    h_right = height_tree(root->right);

    if(h_left > h_right){
        return h_left + 1;
    }
    else{
        return h_right + 1;
    }

}


node * rotate_left(node *root){
    node * no;

    no = root->right;

    root->right = no->left;

    no->left = root;

    root = no;

    return root;

}

node * rotate_right(node *root){
    
    node * no;

    no = root->left;

    root->left = no->right;

    no->right = root;

    root = no;

    return root;
}


node * balance_tree(node *root){
    int balance_factor;


    if (height_tree(root->left) - height_tree(root->right) == 2){
        balance_factor = height_tree(root->left->left) - height_tree(root->left->right);
        if (balance_factor == -1){
            root->left = rotate_left(root->left);
        }
        root = rotate_right(root);}

    else if ((height_tree(root->left) - height_tree(root->right)) == -2){
        balance_factor = height_tree(root->right->left) - height_tree(root->right->right);
        if (balance_factor == 1){
            root->right = rotate_right(root->right);
        }
        root = rotate_left(root);

    }

    return root;
    }

node * recursive_balance_tree(node *root){
   
    if (root == NULL) return NULL;

    root->left = recursive_balance_tree(root->left);
    root->right = recursive_balance_tree(root->right);

    root = balance_tree(root);

    return root;
}

node * insert_tree(node *root, int v){
    if (empty_tree(root)){
        root = create_tree(v, NULL, NULL);
    } else if (v < root->info){
        root->left = insert_tree(root->left, v);
    } else {
        root->right = insert_tree(root->right, v);
    }
    return balance_tree(root);      // Funciona porque a árvore só pode se desbalancear uma situação por vez
}




void print_tree(node *root){
    
    if(root){
        printf("%d ", root->info);
        print_tree(root->left);
        //printf(" %d ", root->info);
        print_tree(root->right);
    }
    else printf("[]");
}

void ordered_print(node *root){
    if(root){
        ordered_print(root->left);
        printf(" %d ", root->info);
        ordered_print(root->right);
    }
    else return;
}



node * free_tree(node *root){
    if(root){
        root->left = free_tree(root->left);
        root->right = free_tree(root->right);
        printf("Liberando %d  \n", root->info);
        free(root);
        return NULL; // Retorna 
    }

    return NULL;

}

node * binary_search_tree(node *root, int v){
    if(root){
        if(root->info == v){
            return root;
        }
        else if(v <= root->info){
            return binary_search_tree(root->left, v);
        }
        else{
            return binary_search_tree(root->right, v);
        }
    }
    return NULL;
}

int is_in_tree(node *root, int v){
    if(root){
        if(root->info == v){
            return TRUE;
        }
        else if(v <= root->info){
            return is_in_tree(root->left, v);
        }
        else{
            return is_in_tree(root->right, v);
        }
    }
    return FALSE;
}


int q_nodes_tree(node *root){
    int q;

    if (!root) return 0;
    
    q = 1 + q_nodes_tree(root->left);           // mesmo que aqui seja 0 de cara, ele continua descendo
    q += q_nodes_tree(root->right);             // e soma 1 só quando necessário

    return q;
    
}

int node_level(node *root, int v){

    if ((root->info  == v)) return 0;


    else if (v <= root->info)
        return 1 + node_level(root->left, v);
    
    else
        return 1 + node_level(root->right, v);
    
}

node * remove_tree(node * root, int v){
    node * no;


    if (root == NULL) return NULL;

    else{
        if (root->info == v){

            if ((!root->left) && (!root->right)){ // folha
                free(root);
                return NULL;
            }

            else{
                if (root->left && root->right){     // dois filhos
                    no = root->left;

                    while (no->right)               // força esse nó a ser um nó com um filho à esquerda
                                                    // ou folha
                    {
                        no = no->right;
                    }

                    root->info = no->info;

                    no->info = v;

                    root->left = remove_tree(root->left, v); 
                }

                else{
                    if (root->left)         // filho à esquerda
                        no = root->left;

                    else 
                        no = root->right;   // filho à direita

                    free(root);

                    return no;      // retorna o filho pra árvore
        
                }


            }

        }

        else {
            if (v < root->info){
                root->left = remove_tree(root->left, v);
            }
            else{
                root->right = remove_tree(root->right, v);
            }
        }

        return balance_tree(root);          // recalcula o balanceamento dos nós que estão
                                            // acima do nó removido (simula de novo em caso de dúvida)

       // return root;

    }
}





