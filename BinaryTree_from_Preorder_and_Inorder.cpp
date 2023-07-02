#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

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

 BinaryTree<int>* TreeConstructor(vector<int> &inorder,vector<int> &preorder,int InS,int InE,int PrS,int PrE){
    if(InS>InE){
        return NULL;
    }

    int index=-1;
    int root_data=preorder[PrS];
    BinaryTree<int>* root = new BinaryTree<int>(root_data);
    for(int i=InS;i<=InE;i++){
        if(inorder[i]==root_data){
            index=i;
            break;
        }
    }
    int LInS = InS;
    int LInE = index-1;
    int LPrS = PrS+1;
    int LPrE = LInE-LInS + LPrS;
    
    int RInS = index+1;
    int RInE = InE;
    int RPrS = LPrE+1;
    int RPrE = PrE;
 
    root->left = TreeConstructor(inorder,preorder,LInS,LInE,LPrS,LPrE);
    root->right = TreeConstructor(inorder,preorder,RInS,RInE,RPrS,RPrE);
    return root;
 }

 BinaryTree<int>* TreePreorder_Inorder(vector<int> &inorder,vector<int> &preorder,int size){
    return TreeConstructor(inorder,preorder,0,size-1,0,size-1);
}

int main(){
    vector<int> inorder{2, 6, 3, 9, 5, 10};
    vector<int> preorder{5, 6, 2, 3, 9, 10 };
    BinaryTree<int>* root = TreePreorder_Inorder(inorder,preorder,inorder.size());
    PrintTree_Level(root);
    delete root;
    //1, 2, 4, 5, 3, 6, 7
}
