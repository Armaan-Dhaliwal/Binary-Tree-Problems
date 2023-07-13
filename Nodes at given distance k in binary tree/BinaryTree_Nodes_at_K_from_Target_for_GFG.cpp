//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

void Print_at_depth(Node* root, int depth,vector<int>& res){
    if(root==NULL){
        return;
    }

    if(depth==0){
        res.push_back(root->data);
        return;
    }

    Print_at_depth(root->left,depth-1,res);
    Print_at_depth(root->right,depth-1,res);
}

int Find(Node* root,int target,int depth){
    if(root==NULL){
        return -1;
    }

    if(root->data==target){
        return depth;
    }
    return(max(Find(root->left,target,depth+1),Find(root->right,target,depth+1)));
}

void RootPrinter(Node* root, int k, int target, vector<int>& res){
    if(root->data==target){
        Print_at_depth(root,k,res);
        return;
    }


    int rd = Find(root->right,target,0)+1;
    if(rd==k){
        res.push_back(root->data);
        RootPrinter(root->right,k,target,res);
    }
     if(rd!=0 && rd<k){
        Print_at_depth(root->left,(k-rd-1),res);
        RootPrinter(root->right,k,target,res);
        
    }
    else if(rd!=0 && rd>k){
        RootPrinter(root->right,k,target,res);
    }
    
    int ld = Find(root->left,target,0)+1;
        if(ld==k){
            res.push_back(root->data);
            RootPrinter(root->left,k,target,res);
        }
        else if(ld!=0 && ld<k){
            Print_at_depth(root->right,(k-ld-1),res);
            RootPrinter(root->left,k,target,res);
        }
        else if(ld!=0 && ld>k){
            RootPrinter(root->left,k,target,res);
        }
    return;
}

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {   
        vector<int> res;
        if(root==NULL){
            return res;
        }
        RootPrinter( root, k, target,res);
        sort(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends