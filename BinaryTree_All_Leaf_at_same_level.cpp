#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
 
 bool check(Node *root)
    {   bool res=true;
        queue<Node*> q;
        int flag=0;
        if(root==NULL){
            return res;
        }
        q.push(root);
        while(!q.empty()){
            flag=0;
            int size=q.size();
            while(size>0){
                if(q.front()->left==NULL && q.front()->right==NULL){
                    flag=1;
                }
                if(q.front()->left!=NULL){
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL){
                    q.push(q.front()->right);
                }
                size--;
                q.pop();
            }
            if(flag==1){
                if(q.size()!=0){
                    res = false;
                    break;
                }
            }
        }
        return res;
    }