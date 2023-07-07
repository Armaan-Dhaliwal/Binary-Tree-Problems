#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
 bool isIsomorphic(BinaryTree<int> *root1,BinaryTree<int> *root2)
    {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL||root2==NULL){
            return false;
        }
        if(root1->data!=root2->data){
            return false;
        }
        return
        (isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right))||
        (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
    }

    
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

int main(){
    BinaryTree<int>* root1 = takeInput();
    cout<<"********"<<endl;
    BinaryTree<int>* root2 = takeInput();
    cout<<isIsomorphic(root1,root2)<<endl;
}
// 6 6 4 -1 8 7 5 -1 9 9 
// 6 4 6 5 7 8 -1 -1 -1 -1 9 9