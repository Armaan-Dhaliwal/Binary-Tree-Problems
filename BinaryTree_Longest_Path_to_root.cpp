#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
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

int Depth(BinaryTree<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(Depth(root->left),Depth(root->right));

}

void LongestPath(BinaryTree<int>* root,vector<int> &res, int depth){
    if(root==NULL){
        if(depth==0){
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    res.push_back(root->data);
    LongestPath(root->left,res,depth-1);
    if(depth-1!=0){
        LongestPath(root->right,res,depth-1);
    }
    
    res.pop_back();
}

int main(){
    BinaryTree<int>* root = takeInput();
    int depth = Depth(root);
    cout<<"depth is: "<<depth<<endl;
    vector<int> res;
    LongestPath(root,res,depth);
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1