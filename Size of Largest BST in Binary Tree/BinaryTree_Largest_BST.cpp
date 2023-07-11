#include<iostream>
#include<queue>
#include<limits.h>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
class returner{
    public:
    int min;
    int max;
    bool isBST;
    int max_height_so_far;
    int size;
};

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

returner LargestBST(BinaryTree<int>* root){
    if(root==NULL){
        returner r;
        r.max_height_so_far=0;
        r.isBST=true;
        r.min=INT_MAX;
        r.max=INT_MIN;
        r.size=0;
        return r;
    }

    returner left = LargestBST(root->left);
    returner right = LargestBST(root->right);
    returner res;
    res.max = max(left.max,max(right.max,root->data));
    res.min = min(left.min,min(right.min,root->data));
    int max_height = max(left.max_height_so_far,right.max_height_so_far);
    if(root->data>left.max && root->data<right.min && left.isBST && right.isBST){
        res.max_height_so_far=max_height+1;
        res.isBST=true;
        res.size=left.size+right.size+1;
    }
    else{
        res.max_height_so_far=max_height;
        res.isBST=false;
        res.size=max(left.size,right.size);
    }
    return res;
}

int main(){
    BinaryTree<int>* root = takeInput();
    returner res= LargestBST(root);
    cout<<"Height of max BST: "<<res.max_height_so_far<<" and size is: "<<res.size <<endl;
}
