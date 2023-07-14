#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

// struct returner{
//     BinaryTree<int>* parent;
//     int depth;
// };

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

// returner Depth_parent(BinaryTree<int>* root,int node){
//     if(root==NULL){
//         returner r;
//         r.parent=NULL;
//         r.depth=-1;
//         return r;
//     }
//     if(root->data==node){
        
//     }
//     returner result;
//     result.parent = root;
//     returner left = Depth_parent(root->left,node); 
//     returner right = Depth_parent(root->right,node);
//     int max_depth = max(left.depth,right.depth);
//     if(root->data=node){
//         return 1;
//     }
//     else{
//         result.depth= ;
//     }
    
//     return result;
// }

int Depth(BinaryTree<int>* root,int node, BinaryTree<int>* &parent){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 1;
    }
    int returning_depth;
    int temp_max_depth = max(Depth(root->left,node,parent),Depth(root->right,node,parent));
    if(temp_max_depth!=-1){
        returning_depth=temp_max_depth+1;
    }
    else{
        returning_depth=temp_max_depth;
    }
    if(returning_depth==2){
        parent = root;
    }
    return returning_depth;
}

bool areCousins(BinaryTree<int>* root,int node1,int node2, BinaryTree<int>* &parent1, BinaryTree<int>* &parent2 ){
    if(root==NULL){
        return false;
    }

    int d1 = Depth(root,node1,parent1);
    int d2 = Depth(root,node2,parent2);
    cout<< " d1 is: "<<d1<<" parent is "<<parent1->data<<endl;
    cout<< " d2 is: "<<d2<<" parent is "<<parent2->data<<endl;
    if(d1==d2 && parent1!=parent2){
        return true;
    }
    return false;
}

int main(){
    BinaryTree<int>* root = takeInput();
    int node1,node2;
    cout<<"Enter node1: "<<endl;
    cin>>node1;
    cout<<"Enter node2: "<<endl;
    cin>>node2;
    BinaryTree<int>* parent1 = new BinaryTree<int>(-1);
    BinaryTree<int>* parent2 = new BinaryTree<int>(-1);
    if(areCousins(root,node1,node2,parent1,parent2)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1