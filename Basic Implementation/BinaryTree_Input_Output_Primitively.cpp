#include<iostream>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

BinaryTree<int>* takeInput(){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    BinaryTree<int>* root = new BinaryTree<int>(data);
    BinaryTree<int>* left = takeInput();
    BinaryTree<int>* right = takeInput();
    root->left=left;
    root->right=right;
    return root;
}   

void PrintTree(BinaryTree<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<root->left->data<<" , ";
    }
    if(root->right!=NULL){
        cout<<root->right->data<<endl;
    }
}

int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree(root);
    delete root;
}