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

void Print_at_depth(BinaryTree<int>* root, int depth){
    if(root==NULL){
        return;
    }

    if(depth==0){
        cout<<root->data<<" ";
        return;
    }

    Print_at_depth(root->left,depth-1);
    Print_at_depth(root->right,depth-1);
}

int Find(BinaryTree<int>* root,int target,int depth){
    if(root==NULL){
        return -1;
    }

    if(root->data==target){
        return depth;
    }
    return(max(Find(root->left,target,depth+1),Find(root->right,target,depth+1)));
}

void RootPrinter(BinaryTree<int>* root, int k, int target){
    if(root->data==target){
        Print_at_depth(root,k);
        return;
    }

    int ld = Find(root->left,target,0)+1;
    if(ld==k){
        cout<<root->data<<" ";
        RootPrinter(root->left,k,target);
    }
    else if(ld!=0 && ld<k){
        Print_at_depth(root->right,(k-ld-1));
        RootPrinter(root->left,k,target);
    }
    else if(ld!=0 && ld>k){
        RootPrinter(root->left,k,target);
    }

    int rd = Find(root->right,target,0)+1;
    if(rd==k){
        cout<<root->data<<" ";
        RootPrinter(root->right,k,target);
    }
     if(rd!=0 && rd<k){
        Print_at_depth(root->left,(k-rd-1));
        RootPrinter(root->right,k,target);
    }
    else if(rd!=0 && rd>k){
        RootPrinter(root->right,k,target);
    }

    return;
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter value of target: "<<endl;
    int target;
    cin>>target;
    cout<<"Enter distance: "<<endl;
    int k;
    cin>>k;
    cout<<"*****"<<endl;
    RootPrinter(root,k,target);

    delete root;
}
// 12 6 7 4 3 -1 10 5 -1 8 10 -1 -1 -1 -1 -1 9 12 20 15 -1 -1 -1 18 -1 -1 -1 -1 -1
