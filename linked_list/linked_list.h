#include <iostream>

class Node {
    friend class LinkedList;
    
    private:
        int data;
        Node* next;

    public:
        Node(int value) : data(value), next(nullptr){}

        int get_data() const {
            return data;
        }

        void set_data(int value) {
            data = value;
        }

        Node* get_next() const {
            return next;
        }

        void set_next(Node* next_node) {
            next = next_node;
        }
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
        void quick_sort();
        Node* quick_sort_recursive(Node*, Node*);
        Node* get_middle(Node*, Node*);
        Node* partition(Node*, Node*);
};