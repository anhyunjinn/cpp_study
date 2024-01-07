#include "BinarySearchTree.h"

int main(void){
    binarySearchTree bst;
    bst.insert_node(4);
    bst.insert_node(1);
    bst.insert_node(8);
    bst.insert_node(4);
    bst.insert_node(6);
    bst.search_node(6);
    bst.search_node(3);
}