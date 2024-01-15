#include <iostream>
#include <memory>

class Node
{
    public:
        int data;
        std::shared_ptr<Node> parent;
        std::shared_ptr<Node> leftChild;
        std::shared_ptr<Node> rightChild;
};

class binarySearchTree
{
    private:
        std::shared_ptr<Node> root;
    public:
        binarySearchTree();
        void insert_node(int);
        void delete_node(int);
        std::shared_ptr<Node> search_node(int);
        std::shared_ptr<Node> min_search(std::shared_ptr<Node> &subTree);
};