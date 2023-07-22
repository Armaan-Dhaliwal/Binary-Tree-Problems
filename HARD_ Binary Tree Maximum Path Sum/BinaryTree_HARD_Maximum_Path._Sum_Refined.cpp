#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {

    
public:
    int maxPathSum(TreeNode* root, int &maxSum){
        if(root==NULL){
            return -9999;
        }

        int newres;
        int leftres = maxPathSum(root->left,maxSum);
        int rightres = maxPathSum(root->right,maxSum);
        int tempSum=max(root->val,max(leftres,max(rightres,root->val+leftres+rightres)));
            if(maxSum<tempSum){
                maxSum=tempSum;
            }

        newres=max(root->val,max(root->val+leftres,root->val+rightres));
        return newres;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int result = maxPathSum(root,maxSum);
        return max(result,maxSum);
    }
};