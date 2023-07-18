#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

vector<int> diagonal(BinaryTree<int> *root)
{
    vector<int> res;
    if(root==NULL){
        return res;
    }
   queue<BinaryTree<int>*> q;
   q.push(root);
   while(!q.empty()){
       BinaryTree<int>* temp=q.front();
       q.pop();
       while(temp){
           res.push_back(temp->data);
           if(temp->left){
               q.push(temp->left);
           }
           temp=temp->right;
          }
   }
   return res;
}