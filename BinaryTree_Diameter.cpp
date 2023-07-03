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

pair<int, int> heightDiameter( BinaryTree<int>*root){
    if(root==NULL){
        pair<int, int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int, int> left = heightDiameter(root->left);
    pair<int, int> right = heightDiameter(root->right);

    int lh=left.first;
    int ld = left.second;
    int rh =right.first;
    int rd = right.second;

    int height=1+max(lh,rh);
    int diameter = max(max(ld,rd),lh+rh);
    pair<int,int> p;
    p.first=height;
    p.second=diameter;
    return p;
}

int main(){
    BinaryTree<int>* root = takeInput();
    pair<int, int> p= heightDiameter(root);
    cout<<"Height is: "<<p.first<<" Diameter is: "<<p.second<<endl;
    //PrintTree_Level(root);
    delete root;
}
