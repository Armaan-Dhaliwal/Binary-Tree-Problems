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

void PrintTree_Level(BinaryTree<int>* root){
    if(root==NULL){
        return ;
    }

    queue<BinaryTree<int>*> q;
    BinaryTree<int>* temp = new BinaryTree<int>(-1);
    q.push(root);

    while(!q.empty()){
        cout<<q.front()->data<<" : ";
        if(q.front()->left!=NULL){
            cout<<q.front()->left->data<<" ";
            q.push(q.front()->left);
        }
        
        if(q.front()->right!=NULL){
            cout<<q.front()->right->data<<" ";
            q.push(q.front()->right);
        }
        cout<<endl;
        q.pop();
    }

}
    void Mirror(BinaryTree<int>* root, BinaryTree<int>* Mirror_root){
    if(root->left==NULL){
        return ;
    }
    BinaryTree<int>* temp1 = new BinaryTree<int>(root->left->data);
    Mirror_root->right=temp1;
   Mirror(root->left,Mirror_root->right);

    if(root->right==NULL){
        return ;
    }
    BinaryTree<int>* temp2 = new BinaryTree<int>(root->right->data);
    Mirror_root->left=temp2;
    Mirror(root->right,Mirror_root->left);
}

int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree_Level(root);
    BinaryTree<int>* Mirror_root;
    Mirror_root->data=root->data;
    Mirror(root,Mirror_root);
    PrintTree_Level(Mirror_root);
    delete root;
}
// 1 2 3 4 5 -1 -1 -1 -1 -1 -1