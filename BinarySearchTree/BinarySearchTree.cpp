#include "BinarySearchTree.h"

binarySearchTree::binarySearchTree() : root(nullptr) {}

/*노드 삽입 함수
이진트리가 비어있을 경우: 루트 노드에 데이터 삽입
비어있지 않을 경우: 현재 노드와 크기 비교하며 삽입 위치 결정
기존에 있는 데이터를 삽입하려는 경우 이미 존재함을 알림*/
void binarySearchTree::insert_node(int value)
{
//새로운 노드 생성
std::shared_ptr<Node> addNode = std::make_shared<Node>();
addNode->data = value;

//제일 처음 삽입할 경우, 루트 노드로 설정
if (root == nullptr) {
    root = addNode;
    std::cout<<"루트 노드 "<<addNode->data<<" 삽입"<<std::endl;
    return;
}

//현재 노드를 루트 노드로 설정
std::shared_ptr<Node> curNode = std::make_shared<Node>();
curNode = root;

while(curNode) {
    //현재 노드의 데이터 > 삽입하려는 노드의 데이터
    while(curNode->data > value){
        //현재 노드가 왼쪽 자식 노드가 없을 경우
        if(curNode->leftChild == nullptr){
            //현재 노드의 왼쪽 자식 노드를 삽입하려는 노드로 설정
            curNode->leftChild = addNode;
            curNode->leftChild->parent = curNode;
            std::cout<<curNode->data<<"의 왼쪽 자식 노드로 "<<value<<" 삽입"<<std::endl;
            return;
        }
        //현재 노드가 왼쪽 자식 노드가 있을 경우
        else {
            //현재 노드의 왼쪽 자식 노드를 현재 노드로 재설정
            curNode = curNode->leftChild;
        }
    }
    //현재 노드의 데이터 < 삽입하려는 노드의 데이터
    while (curNode->data < value){
        //현재 노드가 오른쪽 자식 노드가 없을 경우
        if(curNode->rightChild == nullptr){
            //현재 노드의 오른쪽 자식 노드를 삽입하려는 노드로 설정
            curNode->rightChild = addNode;
            curNode->rightChild->parent = curNode;
            std::cout<<curNode->data<<"의 오른쪽 자식 노드로 "<<value<<" 삽입"<<std::endl;
            return;
        }
        //현재 노드가 오른쪽 자식 노드가 있을 경우
        else{
            //현재 노드의 오른쪽 자식 노드를 현재 노드로 재설정
            curNode = curNode->rightChild;
        }
    }
    //현재 노드의 데이터 = 삽입하려는 노드의 데이터
    while (curNode->data == value){
        std::cout<<value<<"는 이미 존재하는 데이터입니다."<<std::endl;
        return;
    }
}
}

/*노드 삭제 함수
트리의 형태에 따라 케이스 구분
case1: 자식이 없는 노드
case2: 자식이 하나만 있는 노드
case3: 자식이 둘 다 있는 노드*/
void binarySearchTree::delete_node(int value)
{
    //비어있을 경우
    if (root == nullptr) {
        std::cout<<"삭제할 데이터가 없습니다."<<std::endl;
        return;
    }

    //현재 노드를 루트 노드로 설정, 삭제할 노드를 저장할 노드 생성
    std::shared_ptr<Node> curNode = root;

    while(curNode){
        if(value == curNode->data) {    
            //case1 : 자식이 없는 노드
            if (curNode->leftChild == nullptr && curNode->rightChild == nullptr){
                if (curNode->parent->leftChild == curNode){
                    curNode->parent->leftChild = nullptr;
                }
                else if (curNode->parent->rightChild == curNode){
                    curNode->parent->rightChild = nullptr;
                }
                else {
                    root = nullptr;
                }
            }
            //case2 : 자식이 하나만 있는 노드
            else if (curNode->leftChild == nullptr || curNode->rightChild == nullptr){
                std::shared_ptr<Node> tempNode = std::make_shared<Node>();
                if (curNode->parent->leftChild == curNode) {
                    curNode->parent->leftChild = tempNode;
                }
                else if (curNode->parent->rightChild == curNode) {
                    curNode->parent->rightChild = tempNode;
                } else {
                    root = tempNode;
                }

                if (tempNode != nullptr){
                    tempNode->parent = curNode->parent;
                }
            }
            //case3 : 자식이 둘 다 있는 노드
            else if (curNode->leftChild != nullptr && curNode->rightChild != nullptr) {
                std::shared_ptr<Node> minNode = min_search(curNode->rightChild);

                if(minNode->parent != curNode) {
                    minNode->parent->leftChild = minNode->rightChild;
                    if (minNode->rightChild){
                        minNode->rightChild->parent = minNode->parent;
                    }
                }
                else {
                    curNode->rightChild = minNode->rightChild;
                    if (minNode->rightChild){
                        minNode->rightChild->parent = curNode;
                    }
                }
                curNode->data = minNode->data;
            }
            return;
        }
        else if (value < curNode->data) {
            curNode = curNode->leftChild;
        }
        else {
            curNode = curNode->rightChild;
        }
    }

    std::cout<<value<<"는 없는 데이터입니다."<<std::endl;
}

/*노드 검색 함수
비어있는 경우 : 검색할 데이터가 없음을 알림
안 비어있는 경우 : 검색한 데이터와 크기를 비교하며 탐색,
일치하는 값이 있으면 노드, 없으면 nullptr 반환*/
std::shared_ptr<Node> binarySearchTree::search_node(int value)
{
    //비어있을 경우
    if (root == nullptr) {
        std::cout<<"검색할 데이터가 없습니다."<<std::endl;
        return nullptr;
    }

    //현재 노드를 루트 노드로 설정
    std::shared_ptr<Node> curNode = std::make_shared<Node>();
    curNode = root;

    while(curNode){
        if (value == curNode->data) {
            std::cout<<"검색한 노드 발견: "<<curNode->data<<std::endl;
            return curNode;
        }
        else if (value < curNode->data) {
            curNode = curNode->leftChild;
        }
        else {
            curNode = curNode->rightChild;
        }
    }

    std::cout<<"검색한 값인 "<<value<<"를 찾지 못했습니다."<<std::endl;
    return nullptr;
}

/*서브트리의 가장 작은 값을 찾아 반환하는 함수
삭제 기능에서 사용*/
std::shared_ptr<Node> binarySearchTree::min_search(std::shared_ptr<Node> &subTree){
    while (subTree->leftChild){
        subTree = subTree->leftChild;
    }
    return subTree;
}