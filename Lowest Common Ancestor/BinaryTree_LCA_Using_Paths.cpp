#include<iostream>
#include<queue>
#include<algorithm>
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


void PrintLevel(BinaryTree<int>* root){
    queue<BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size>0){
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            cout<<q.front()->data<<" ";
            q.pop();
            size--;
        }
        cout<<endl;
    }
}

vector<int> PathFinder(BinaryTree<int>* root,int x){
    vector<int> vec;
    if(root==NULL){
        return vec;
    }

    if(root->data==x){
        vec.push_back(x);
        return vec;
    }
    vector<int> left=PathFinder(root->left,x);
    if(left.size()!=0){
        left.push_back(root->data);
        return left;
    }

    vector<int> right=PathFinder(root->right,x);
    if(right.size()!=0){
        right.push_back(root->data);
        return right;
    }

    return vec;
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter the two nodes:"<<endl;
    int node1,node2;
    cin>>node1;
    cin>>node2;
    vector<int> res1=PathFinder(root,node1);
    vector<int> res2=PathFinder(root,node2);
    int LCA=-1;
    // for(int i=0;i<res1.size();i++){
    //     cout<<res1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<res2.size();i++){
    //     cout<<res2[i]<<" ";
    // }
    // cout<<endl;
    int i=res1.size()-1;
    int j=res2.size()-1;
    while(i>=0 && j>=0){
        if(res1[i]==res2[j]){
            LCA=res1[i];
        }
        i--;
        j--;
    }
    cout<<LCA<<endl;
}