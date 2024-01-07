#include <iostream>

class Node {
    private:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        Node* cur;
    
    public:
        LinkedList() : head(nullptr), tail(nullptr), cur(nullptr){}
        void insert_node(int);
        void search_node(int);
        void delete_node(int);
        void print_list();
};