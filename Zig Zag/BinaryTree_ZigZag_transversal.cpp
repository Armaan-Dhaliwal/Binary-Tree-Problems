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

void PrintTree_ZigZag(BinaryTree<int>* root){
    queue<BinaryTree<int>*> q;
    q.push(root);
    q.push(NULL);
    bool alternator=false;

    while(!q.empty()){ 
        vector<int> vec;
        while(q.front()!=NULL){
            vec.push_back(q.front()->data);
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        int size=vec.size();
        if(alternator==false){
            for(int i=0;i<size;i++){
                cout<<vec[i]<<" ";
            }
        }
        else{
            for(int i=size-1;i>=0;i--){
                cout<<vec[i]<<" ";
            }
        }
        cout<<endl;
        if(alternator==false){
            alternator=true;
        }
        else{
            alternator=false;
        }
        q.pop();
        if(!q.empty()){
            q.push(NULL);
        }
    }
}


int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree_ZigZag(root);
    delete root;
}

