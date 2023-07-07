#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
 
 int Sum(Node* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        int left = Sum(root->left);
        int right = Sum(root->right);
        int temp=root->data;
        root->data=left+right;
        return root->data+temp;
    }

    void toSumTree(Node *node)
    {
        if(node==NULL){
            return ;
        }
        int num = Sum(node);
    }