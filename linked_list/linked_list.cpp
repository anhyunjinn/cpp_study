#include <iostream>
#include "linked_list.h"

//삽입
void LinkedList::insert_node(int data) {
    Node* new_node = new Node(data);
    new_node->set_next(nullptr);

    if (head == nullptr){
        head = new_node;
    }
    else{
        tail->set_next(new_node);
    }

    std::cout<<new_node->get_data()<<"삽입"<<std::endl;
    tail = new_node;
}

//삭제
void LinkedList::delete_node(int data) {
    if (head == nullptr){
        return;
    }
    cur = head;
    Node* temp = nullptr;

    while(cur!=nullptr && cur->get_data() != data){
        temp = cur;
        cur = cur->get_next();
    }
    
    if(cur == nullptr){
        std::cout<<"해당 데이터를 찾을 수 없습니다"<<std::endl;
        return;
    }

    if(temp!=nullptr){
        temp->set_next(cur->get_next());
    }else{
        head=cur->get_next();
    }

    std::cout<<cur->get_data()<<"삭제"<<std::endl;

    delete cur;
}

//검색
void LinkedList::search_node(int data) {
    cur = head;
    while (cur!=nullptr){
        if (cur->get_data() == data){
            std::cout<<cur->get_data()<<std::endl;
            return;
        }
        cur = cur->get_next();
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
        std::cout<<cur->get_data()<<" ";
        cur = cur->get_next();
    }
    std::cout<<std::endl;
}

// 퀵소트 함수
void LinkedList::quick_sort(){
    quick_sort_recursive(head, tail);
}

/*퀵소트의 재귀적인 부분을 구현한 함수*/
Node* LinkedList::quick_sort_recursive(Node* low, Node* high) {
    if (low == nullptr || low == high) {
        return low;
    }

    Node* partition_point = partition(low, high);

    if (partition_point != nullptr) {
        if (partition_point != low) {
            partition_point = quick_sort_recursive(low, partition_point);
        }
        partition_point->set_next(quick_sort_recursive(partition_point->get_next(), high)); // 수정된 부분
    }

    if (partition_point != nullptr) {
        return low;
    } else {
        return low->get_next();
    }
}


/*피봇 선택 함수
퀵소트 전, 특정 기준을 찾을 때
가장 최선의 시간 복잡도를 위해 linked list의
중간 값을 pivot으로 두려고 함*/
Node* LinkedList::get_middle(Node* low, Node* high) {
    if (low == nullptr || high == nullptr) {
        return nullptr;
    }

    Node* one = low;
    Node* two = low->get_next();

    while (two != high && two != nullptr && two->get_next() != high) {
        one = one->get_next();
        two = two->get_next()->get_next();
    }

    return one;
}

/*분할 함수
linked list를 특정 기준(pivot)으로 나누는 함수*/
Node* LinkedList::partition(Node* low, Node* high) {
    if (low == nullptr || high == nullptr) {
        return nullptr;
    }

    Node* pivot = get_middle(low, high);
    if (pivot == nullptr) {
        return nullptr;
    }
    
    Node* i = low;
    Node* j = low->get_next();

    while (j != nullptr && i != nullptr && i != j) {
        if (j->get_data() <= pivot->get_data()) {
            i = i->get_next();
            if (i != nullptr) {
                int temp = i->get_data();
                i->set_data(j->get_data());
                j->set_data(temp);
            }
        }
        if (j != nullptr) {
            j = j->get_next();
        } else {
            j = nullptr;
        }
    }

    int temp = i->get_data();
    i->set_data(pivot->get_data());
    pivot->set_data(temp);

    return i;
}