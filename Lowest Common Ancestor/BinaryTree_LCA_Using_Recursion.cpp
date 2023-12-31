#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL){
           return NULL;
       }
        
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
       Node*left = lca(root->left,n1,n2);
       Node*right = lca(root->right,n1,n2);
       if(left&&right){
           return root;
       }
       
       return (left!=NULL)?left:right;
       
    }