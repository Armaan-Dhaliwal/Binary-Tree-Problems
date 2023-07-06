#include<iostream>
#include"BinaryTree_Node_Class.cpp"
#include<queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

    bool isSame(BinaryTree<int>* root, BinaryTree<int>* subRoot){

        if(root==NULL && subRoot==NULL){
            return true;
        }
        else if( (root==NULL && subRoot!=NULL) ||  (root!=NULL && subRoot==NULL)){
            return false;
        }
        else if(root->data==subRoot->data){
           return isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
            //cout<<"returning from isSame:  "<<res<<endl;
        }

        return false;
    }

    bool isSubtree(BinaryTree<int>* root, BinaryTree<int>* subRoot) {
        bool res=false;
        bool res1=false;
        bool res2=false;
        if(root==NULL && subRoot==NULL){
            return true;
        }
        else if( (root==NULL && subRoot!=NULL) ||  (root!=NULL && subRoot==NULL)){
            return false;
        }
        else if( root->data==subRoot->data){
            // cout<<"before isSame: "<<res<<endl;  
            // cout<<"calling is same at"<<endl;
            res=isSame(root,subRoot);
            // cout<<"Recieved from isSame:  "<<res<<endl;
        }
        
        if(res==false){
            if(root->left!=NULL){
                res1=isSubtree(root->left,subRoot);
            }
            if(root->right!=NULL){
                res2=isSubtree(root->right,subRoot);
            }
        
            res=res1 || res2;
            return res;
        }
        return res;
    }


BinaryTree<int>* takeInput(){
    cout<<"enter root data "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    queue<BinaryTree<int>*> q;
    BinaryTree<int>* root=new BinaryTree<int>(data);
     q.push(root);

    while(!q.empty()){
        cout<<"Enter left data for "<<q.front()->data<<endl;
        int data;
        cin>>data;
        if(data!=-1){
             BinaryTree<int>* node1 = new BinaryTree<int>(data);
            q.front()->left=node1;
            q.push(q.front()->left);
        }

        cout<<"Enter right data for "<<q.front()->data<<endl;
        cin>>data;
        if(data!=-1){
            BinaryTree<int>* node2 = new BinaryTree<int>(data);
            q.front()->right=node2;
            q.push(q.front()->right);
        }
        q.pop();
    }
    
    return root;
}

int main(){
    cout<<"Enter root1 data: "<<endl;
    BinaryTree<int>* root1 = takeInput();
    cout<<"Enter root2 data: "<<endl;
    BinaryTree<int>* root2 = takeInput();
    if(isSubtree(root1,root2)){
        cout<<"True"<<endl;
    }
    else{
        cout<<false;
    }
    delete root1;
    delete root2;
}
