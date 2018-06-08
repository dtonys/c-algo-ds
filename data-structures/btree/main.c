#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum orders { IN_ORDER, PRE_ORDER, POST_ORDER };

typedef struct btree_node {
    int value;
    struct btree_node *left;
    struct btree_node *right;
} btree_node;

typedef struct btree {
    int size;
    btree_node *root;
} btree;

btree * create_btree() {
    btree *t = (btree *) malloc(sizeof(btree));
    t->size = 0;
    t->root = NULL;
    return t;
}

bool btree_empty(btree *t) {
    return t->size == 0;
}

void btree_insert(btree *t, int value) {
    btree_node *node = (btree_node *) malloc(sizeof(btree_node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if( btree_empty(t) ) {
        t->root = node;
        t->size++;
        return;
    }
    btree_node *root = t->root;
    while( true ) {
        if( value == root->value ) return;
        if( value > root->value ) {
            if( root->right == NULL ) {
                root->right = node;
                t->size++;
                break;
            }
            else {
                root = root->right;
                continue;
            }
        }
        if( value < root->value ) {
            if( root->left == NULL ) {
                root->left = node;
                t->size++;
                break;
            }
            else {
                root = root->left;
                continue;
            }
        }
    }
}

void print_btree(btree_node *node, int order) {
    if ( node == NULL ) return;
    if( order == IN_ORDER ) {
        print_btree(node->left, order);
        printf("%i\t", node->value);
        print_btree(node->right, order);
        return;
    }
    if( order == PRE_ORDER ) {
        printf("%i\t", node->value);
        print_btree(node->left, order);
        print_btree(node->right, order);
        return;
    }
    if( order == POST_ORDER ) {
        print_btree(node->left, order);
        print_btree(node->right, order);
        printf("%i\t", node->value);
        return;
    }
}

int main() {
    // create btree
    btree *t =create_btree();

    // add -> 10, 7, 15, 3
    btree_insert(t, 10);
    btree_insert(t, 7);
    btree_insert(t, 15);
    btree_insert(t, 3);

    // print tree
    print_btree(t->root, IN_ORDER); // 3,7,10,15
    printf("\n");
    print_btree(t->root, PRE_ORDER); // 10,7,3,15
    printf("\n");
    print_btree(t->root, POST_ORDER); // 3,7,15,10
    printf("\n");
    return 0;
}
