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

int Depth(BinaryTree<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(Depth(root->left),Depth(root->right));
}

bool TreeBalance(BinaryTree<int>* root){
    if(root==NULL){
        return true;
    }

    if(abs(Depth(root->left)-Depth(root->right))<=1){
        return true;
    }
    return false;
}

int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree_Level(root);
    if(TreeBalance(root)){
        cout<<"Tree is balanced ;)"<<endl;
    }
    else{
        cout<<"Tree is not balanced :/"<<endl;
    }
    delete root;
}
