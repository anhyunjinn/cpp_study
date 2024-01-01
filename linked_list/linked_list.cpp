#include <iostream>

class Node {
    public:
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

//삽입
void LinkedList::insert_node(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (head == nullptr){
        head = new_node;
    }
    else{
        tail->next = new_node;
    }

    std::cout<<new_node->data<<"삽입"<<std::endl;
    tail = new_node;
}

//삭제
void LinkedList::delete_node(int data) {
    if (head == nullptr){
        return;
    }
    cur = head;
    Node* temp = new Node;

    while(cur!=nullptr && cur->data != data){
        temp = cur;
        cur = cur->next;
    }
    
    if(cur == nullptr){
        std::cout<<"해당 데이터를 찾을 수 없습니다"<<std::endl;
        return;
    }

    if(temp!=nullptr){
        temp->next = cur->next;
    }else{
        head=cur->next;
    }

    std::cout<<cur->data<<"삭제"<<std::endl;
    delete(cur);
}

//검색
void LinkedList::search_node(int data) {
    cur = head;
    while (cur!=nullptr){
        if (cur->data == data){
            std::cout<<cur->data<<std::endl;
            return;
        }
        cur = cur->next;
    }
}

//전체 연결리스트 출력
void LinkedList::print_list(){
    cur = head;

    if (head == nullptr){
        std::cout<<"빈 리스트"<<std::endl;
        return;
    }

    while (cur!=nullptr){
        std::cout<<cur->data<<" ";
        cur = cur->next;
    }
    std::cout<<"출력 완료"<<std::endl;
}

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