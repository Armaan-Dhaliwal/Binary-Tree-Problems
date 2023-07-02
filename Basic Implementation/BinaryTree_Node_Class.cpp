#include<iostream>
using namespace std;
template <typename T>
class BinaryTree{
    public:
    T data;
    BinaryTree<T>* left;
    BinaryTree<T>* right;

    BinaryTree(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

    ~BinaryTree(){
        delete left;
        delete right;
    }

};