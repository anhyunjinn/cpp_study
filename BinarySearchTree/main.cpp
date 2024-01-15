#include "BinarySearchTree.h"

int main(void){
    binarySearchTree bst;
    bst.insert_node(4);
    bst.insert_node(1);
    bst.insert_node(8);
    bst.insert_node(4); //중복 데이터를 삽입하는 경우
    bst.insert_node(6);

    bst.delete_node(2); //존재하지 않는 데이터 삭제하는 경우
    bst.delete_node(9); //존재하지 않는 데이터 삭제하는 경우
    bst.delete_node(8);
    bst.delete_node(1);

    bst.search_node(6);
    bst.search_node(1); //존재하지 않는 데이터 검색하는 경우
}