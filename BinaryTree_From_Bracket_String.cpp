#include<iostream>
#include"BinaryTree_Node_Class.cpp"
#include<queue>
using namespace std;

void TreeMaker(BinaryTree<int>* root, string str, int &index ){
    if(index>=str.length()){
        return ;
    }
    
    if(root->left==NULL && str[index]=='(' && str[index+1]!=')'){
        BinaryTree<int>* newNode = new BinaryTree<int>(str[index+1]-48);
        root->left=newNode;
        index+=2;
        TreeMaker(root->left,str,index);
    }
    if(str[index]=='(' && str[index+1]==')'){
        index+=2;
    }
    if(root->right==NULL && str[index]=='('){
        BinaryTree<int>* newNode = new BinaryTree<int>(str[index+1]-48);
        root->right=newNode;
        index+=2;
        TreeMaker(root->right,str,index);
    }
        
    if(str[index]==')'){
        index++;
        return ;
    }  
}

BinaryTree<int>* treeFromBracket(string &str)
{   
    if(str.length()==0){
        return NULL;
    }
    BinaryTree<int>* root = new BinaryTree<int>(str[0]-48);
    int index=1;
    TreeMaker(root,str,index);
    return root;
}
