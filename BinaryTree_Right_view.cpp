#include<iostream>
#include<queue>
#include<vector>
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

vector<int> rightView(Node *root)
    {
       vector<int> res;
       queue<Node*> q;
       if(root==NULL){
           return res;
       }
       q.push(root);
       while(!q.empty()){
           int size=q.size();
           while(size>0){
               if(q.front()->left!=NULL){
                   q.push(q.front()->left);
               }
               if(q.front()->right!=NULL){
                   q.push(q.front()->right);
               }
               if(size==1){
                   res.push_back(q.front()->data);
               }
               q.pop();
               size--;
           }
       }
       return res;
    }