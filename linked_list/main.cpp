#include <iostream>
#include "linked_list.h"

int main(void){
    LinkedList list;

    //노드 삽입
    list.insert_node(7);
    list.insert_node(4);
    list.insert_node(1);
    list.insert_node(2);
    list.insert_node(3);
    list.insert_node(6);
    list.insert_node(5);

    list.search_node(1);
    list.search_node(3);

    list.delete_node(2);
    list.delete_node(6);

    std::cout<<"Quick Sort 실행 전 linked list: ";
    list.print_list();

    list.quick_sort();

    std::cout<<"Quick Sort 실행 후 linked list: ";
    list.print_list();
}