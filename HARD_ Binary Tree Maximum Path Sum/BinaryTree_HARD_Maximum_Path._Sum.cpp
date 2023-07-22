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

    struct returner {
        int max_sum;
    };

    returner maxPathSum(TreeNode* root, int &maxSum){
        if(root==NULL){
            returner r;
            r.max_sum=-9999;
            return r;
        }

        returner newres;
        returner leftres = maxPathSum(root->left,maxSum);
        returner rightres = maxPathSum(root->right,maxSum);
        // int LR_max=max(leftres.max_sum,rightres.max_sum);
        // if(LR_max+root->val<LR_max){
            int tempSum=max(root->val,max(leftres.max_sum,max(rightres.max_sum,root->val+leftres.max_sum+rightres.max_sum)));
            if(maxSum<tempSum){
                maxSum=tempSum;
            }
       // }
        //else{
            // int tempSum=max(leftres.max_sum,max(rightres.max_sum,max(root->val,root->val+leftres.max_sum+rightres.max_sum)));           
        //     if(tempSum==(root->val+leftres.max_sum+rightres.max_sum)){
        //         if(tempSum>maxSum){
        //             maxSum=tempSum;
        //         }
        //     }
        //     else{
        //         if(tempSum>maxSum){
        //             maxSum=tempSum;
        //         }   
        //    } 
       // }
        newres.max_sum=max(root->val,max(root->val+leftres.max_sum,root->val+rightres.max_sum));
        // cout<<maxSum<<endl;
        // cout<<newres.max_sum<<endl;
        // cout<<"****"<<endl;
        return newres;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        returner result = maxPathSum(root,maxSum);
        return max(result.max_sum,maxSum);
    }
};