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

BinaryTree<int>* TreeConstructor(vector<int> inorder,vector<int> postorder,int InS,int InE,int PoS,int PoE){
    if(InS>InE){
        return NULL;
    }

    int index=-1;
    int root_data = postorder[PoE];
    for(int i=InS;i<=InE;i++){
        if(inorder[i]==root_data){
            index=i;
            break;
        }
    }

    int LInS = InS;
    int LInE = index-1;
    int LPoS = PoS;
    int LPoE = LInE-LInS +LPoS;

    int RInS = index+1;
    int RInE = InE;
    int RPoS = LPoE+1;
    int RPoE = PoE-1;

    BinaryTree<int>* root = new BinaryTree<int>(root_data);
    root->left = TreeConstructor(inorder,postorder,LInS,LInE,LPoS,LPoE);
    root->right = TreeConstructor(inorder,postorder,RInS,RInE,RPoS,RPoE);

    return root;
}

BinaryTree<int>* TreePostorder_Inorder(vector<int> inorder,vector<int> postorder,int size){
    return TreeConstructor(inorder,postorder,0,size-1,0,size-1);
} 

int main(){
    vector<int> inorder{2, 6, 3, 9, 5, 10};
    vector<int> postorder{2, 9, 3, 6, 10, 5 };
    BinaryTree<int>* root = TreePostorder_Inorder(inorder,postorder,inorder.size());
    PrintTree_Level(root);
    delete root;
    //1, 2, 4, 5, 3, 6, 7
}
