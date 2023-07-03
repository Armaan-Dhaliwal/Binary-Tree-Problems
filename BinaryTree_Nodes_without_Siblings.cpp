#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

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
void Print_No_Siblings(BinaryTree<int>* root){
    queue<BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
       
        if(q.front()->right==NULL && q.front()->left!=NULL){
            cout<<q.front()->left->data<<" ";
        }
        else if(q.front()->left==NULL && q.front()->right!=NULL ){
            cout<<q.front()->right->data<<" ";
        }
        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        q.pop();
    }
}


int main(){
    BinaryTree<int>* root = takeInput();
    Print_No_Siblings(root);
    delete root;
}
