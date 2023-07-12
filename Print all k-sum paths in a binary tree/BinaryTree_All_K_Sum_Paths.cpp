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

void K_Sum_Paths(BinaryTree<int>* root, int k,vector<int> &path){
   if(root==NULL){
        return;
   }

   path.push_back(root->data);
   K_Sum_Paths(root->left,k,path);
   K_Sum_Paths(root->right,k,path);

   int sum=0;
   for(int i=path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            for(int j=i;j<path.size();j++){
                cout<<path[j];
            }
            cout<<endl;
        }
   }

    path.pop_back();
    return;   
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter value of sum: "<<endl;
    int k;
    cin>>k;
    vector<int> path;
    K_Sum_Paths(root,k,path);
    delete root;
}
// 6 3 2 1 5 4 1 2 -1 -1 -1 1 -1 3 8 -1 -1 -1 -1 -1 -1 -1 -1
// 1 3 1 2 1 3 2 -1 -1 1 -1 -1 -1 1 9 -1 -1 -1 -1 -1 -1

/*2
10 5 -3 3 2 -1 11 3 -2 -1 1 -1 -1 -1 -1 -1 -1 -1 -1
8
1 3 -2 2 1 4 5 -1 -1 1 -1 1 2 -1 6 -1 -1 -1 -1 -1 -1 -1 -1 
5
    
*/