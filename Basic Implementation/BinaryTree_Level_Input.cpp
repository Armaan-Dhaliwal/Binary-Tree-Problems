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
    int leftdata,rightdata;
    cout<<"enter left data: "<<endl;
    cin>>leftdata;
    cout<<"enter right data: "<<endl;
    cin>>rightdata;
    if(leftdata!=-1){
        BinaryTree<int>* node1 = new BinaryTree<int>(leftdata);
        root->left=node1;
        q.push(root->left);
    }
    if(rightdata!=-1){
        BinaryTree<int>* node2 = new BinaryTree<int>(rightdata);
        root->right=node2;
        q.push(root->right);
    } 
    q.pop();

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

void PrintTree(BinaryTree<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<root->left->data<<" , ";
    }
    if(root->right!=NULL){
        cout<<root->right->data;
    }
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree(root);
    delete root;
}