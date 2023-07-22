#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int distanceFinder(Node* root, int a,int height=0){
        
        if(root==NULL){
            return -1;
        }
        
        if(root->data==a ){
            return height;
        }
        
        return max(distanceFinder(root->left,a,height+1),distanceFinder(root->right,a,height+1));
    }
    
    Node* LCA(Node* root,int n1, int n2){
        if(root==NULL){
            return root;
        }
        
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* left = LCA(root->left,n1,n2);
        Node* right = LCA(root->right,n1,n2);
        if(left && right){
            return root;
        }
        
        return (left!=NULL)?left:right;
    }
    
    int findDist(Node* root, int a, int b) {
        int da=distanceFinder(root,a);
        int db=distanceFinder(root,b);
        int dlca = distanceFinder(root,LCA(root,a,b)->data);
    
        return (db+da-2*dlca);
    }