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

vector<int> Path(BinaryTree<int>* root, int x){
    if(root==NULL){
        vector<int> vec;
        return vec;
    }

    if(root->data==x){
        vector<int> vec;
        vec.push_back(x);
        return vec;
    }

    vector<int> left = Path(root->left,x);
    if(left.size()!=0){
        left.push_back(root->data);
        return left;
    }
    
    vector<int> right = Path(root->right,x);
    if(right.size()!=0){
        right.push_back(root->data);
        return right;
    }
    else{
        vector<int> vec;
        return vec;
    }
}


int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter node value: "<<endl;
    int x;
    cin>>x;
    vector<int> res = Path(root,x);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    delete root;
}
