#include<iostream>
#include<queue>
#include<vector>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

    
    void K_Sum_Paths(TreeNode* root, int k,vector<int> output,vector<vector<int>> &res){

    if(root==NULL){
        return;
    }

    k-=root->val;
    output.push_back(root->val);
    
     if(k==0){
        if(root->left==NULL && root->right==NULL){
            res.push_back(output);
            return;
        }
     }

    K_Sum_Paths(root->left,k,output,res);
    K_Sum_Paths(root->right,k,output,res);
    return;
    
}

vector<vector<int> > pathSum(TreeNode* A, int B) {
 
    vector<int> output;
    vector<vector<int>> res;
    K_Sum_Paths(A,B,output,res);
    return res;
}
