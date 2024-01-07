#include <iostream>
#include "linked_list.h"

int main(void){
    LinkedList list;
    list.insert_node(1);
    list.insert_node(2);
    list.insert_node(3);

    list.search_node(1);
    list.search_node(3);

    list.delete_node(2);
    list.delete_node(3);

    list.print_list();
}