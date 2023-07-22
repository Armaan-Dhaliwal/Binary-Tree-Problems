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


vector<int> pathFinder(BinaryTree<int> *root, int targetNodeVal, vector<int> path){
    if(root==NULL){
        vector<int> vec(0);
        return vec;
    }
    if(root->data==targetNodeVal){
        return path;
    }

    path.push_back(root->data);
    vector<int> left = pathFinder(root->left,targetNodeVal,path);
    vector<int> right = pathFinder(root->right,targetNodeVal,path);
    if(left.size()==0){
        return right;
    } 
        return left;

}

int main(){
    int targetNodeVal;
    cout<<"Enter target node: "<<endl;
    cin>>targetNodeVal;
    int k;
    cout<<"Enter k: "<<endl;
    cin>>k;
    BinaryTree<int>*root = takeInput();
    vector<int> path;
    int res=-1;
    path = pathFinder(root,targetNodeVal,path);
    cout<<"Path is: "<<endl;
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    if(path.size()<k){
        cout<<"Result is: "<< res<<endl;;
    }
    for(int i=0;i<path.size();i++){
        if(i==path.size()-k){
            res=path[i];
            break;
        }
    }
    cout<<"Result is: "<< res <<endl;
}