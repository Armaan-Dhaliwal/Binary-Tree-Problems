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

vector<int> zigZagTraversal(BinaryTree<int> *root)
{
    vector<int> res;
    if(root==NULL){
        return res;
    }
    deque<BinaryTree<int>*> q;
    q.push_front(root);
    bool alternator=true;

    while(!q.empty()){ 
        int size=q.size();
        if(alternator){
            while(size>0){
            if(q.front()->left!=NULL){
                q.push_back(q.front()->left);
            }
            if (q.front()->right != NULL) {
              q.push_back(q.front()->right);
            }
            res.push_back(q.front()->data);
            //cout<<q.front()->data<<endl;
            q.pop_front();
            size--;
            }
        }

        else{
            while(size>0){
            if (q.back()->right != NULL) {
              q.push_front(q.back()->right);
            }
            if(q.back()->left!=NULL){
                q.push_front(q.back()->left);
            }
            
            res.push_back(q.back()->data);
            //cout<<q.back()->data<<endl;
            q.pop_back();
            size--;
            }
        }
    
        
        if(alternator==false){
            alternator=true;
        }
        else{
            alternator=false;
        }
    }
    return res;
}

int main(){
    BinaryTree<int>* root = takeInput();
    vector<int> vec = zigZagTraversal(root);
    int size=vec.size();
    for(int i=0;i<size;i++){
        cout<<vec[i]<<" ";
    }
    delete root;
}

