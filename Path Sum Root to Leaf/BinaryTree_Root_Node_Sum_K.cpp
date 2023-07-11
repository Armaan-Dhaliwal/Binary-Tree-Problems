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

void K_Sum_Paths(BinaryTree<int>* root, int k,string output){

    if(root==NULL){
        return;
    }

    k-=root->data;
    output+=root->data+48;

     if(k==0){
        if(root->left==NULL && root->right==NULL){
            cout<<output<<endl;
        }
    }

    K_Sum_Paths(root->left,k,output);
    K_Sum_Paths(root->right,k,output);
    return;
    
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter value of sum: "<<endl;
    int k;
    cin>>k;

    string output="";

    cout<<output<<endl;
    K_Sum_Paths(root,k,output);
    delete root;
}
// 6 3 2 1 5 4 1 2 -1 -1 -1 1 -1 3 8 -1 -1 -1 -1 -1 -1 -1 -1
 