#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

    void lefter(BinaryTree<int>* root,vector<int> &left){
       
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL){
             left.push_back(root->data);
            lefter(root->left,left);
        }
        else if(root->right!=NULL){
             left.push_back(root->data);
             lefter(root->right,left);
        }
    }
    
    void righter(BinaryTree<int>* root,vector<int> &right){
        
        if(root==NULL){
            return;
        }
        
        if(root->right!=NULL){
            righter(root->right,right);
            right.push_back(root->data);
        }
        else if(root->left!=NULL){
            righter(root->left,right);
            right.push_back(root->data);
        }
    }
    
    void leafer(BinaryTree<int>* root,vector<int> &leafs){
        if(root==NULL){
            return;
        }
       
        if(root->left==NULL && root->right==NULL){
            leafs.push_back(root->data);
        }
        leafer(root->left,leafs);
        leafer(root->right,leafs);
    }
    
    vector <int> boundary(BinaryTree<int> *root)
    {   
        vector<int> res;
        if(root==NULL){
            return res;
        }
        res.push_back(root->data);

        lefter(root->left,res);
        leafer(root->left,res);
        leafer(root->right,res);
        righter(root->right,res);
 
    return res;
    }