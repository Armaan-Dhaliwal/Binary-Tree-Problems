#include<iostream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output="";
        if(root==NULL){
            return output;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(q.front()==NULL){
                output+='/';
                output+=',';
            }
            else{
                output+=to_string(q.front()->val);
                output+=',';
            }

            if(q.front()){
                q.push(q.front()->left);
                q.push(q.front()->right);   
            }
            q.pop();
            
        }
        cout<<output<<endl;
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return NULL;
        }

        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;;
        
        TreeNode* root = new TreeNode(stoi(str));
        getline(s,str,',');
        q.push(root);
        while(!q.empty()){

            TreeNode* leftNode= NULL;

            if(str!="/"){
                TreeNode* tempNode = new TreeNode(stoi(str));
                leftNode=tempNode;
                q.push(leftNode);
            }
            q.front()->left=leftNode;
            getline(s,str,',');
            
            TreeNode* rightNode= NULL;
            if(str!="/"){
                TreeNode* tempNode = new TreeNode(stoi(str));
                rightNode=tempNode;
                q.push(rightNode);
            }
            q.front()->right=rightNode;
            getline(s,str,',');

            q.pop();
        }     
        return root;
    }
};