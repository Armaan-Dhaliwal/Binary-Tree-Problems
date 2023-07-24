#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

    void inorderTransversal(Node* root,vector<int> &inorder){
        if(root==NULL){
            return;
        }
        
        inorderTransversal(root->left,inorder);
        inorder.push_back(root->data);
        inorderTransversal(root->right,inorder);
    }
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {   
        if(root==NULL){
            return NULL;
        }
        vector<int> inorder;
        inorderTransversal(root,inorder);
        Node* newRoot = new Node(inorder[0]);
        Node* tempRoot=newRoot;

        for(int i=1;i<inorder.size();i++){
            Node* newNode = new Node(inorder[i]);
            tempRoot->right=newNode;
            newNode->left=tempRoot;
            tempRoot=tempRoot->right;
        }
        
        return newRoot;
    }
