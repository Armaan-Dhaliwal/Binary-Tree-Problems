#include<iostream>
#include"BinaryTree_Node_Class.cpp"
#include<queue>
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

void PrintTree_Preorder(BinaryTree<int>* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    PrintTree_Preorder(root->left);
    PrintTree_Preorder(root->right);
}


int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree_Preorder(root);
    delete root;
}
// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
