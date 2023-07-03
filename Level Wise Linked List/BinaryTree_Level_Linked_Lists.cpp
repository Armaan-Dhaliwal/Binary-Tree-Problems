#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next=NULL;
    }
};

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

void PrintTree_Level(BinaryTree<int>* root){
    if(root==NULL){
        return ;
    }

    queue<BinaryTree<int>*> q;
    BinaryTree<int>* temp = new BinaryTree<int>(-1);
    q.push(root);

    while(!q.empty()){
        int nodeCount = q.size();
        
        while(nodeCount>0){
             cout<<q.front()->data<<" ";

        if(q.front()->left!=NULL){
            q.push(q.front()->left);
        }
        
        if(q.front()->right!=NULL){
            q.push(q.front()->right);
        }
        q.pop();
        nodeCount--;
        }
       cout<<endl;
    }

}

Node* LL(Node* head, int data){
    Node* temp = new Node(data);
    Node* temphead = head;
    while(temphead->next!=NULL){
        temphead=temphead->next;
    }
    temphead->next = temp;
    return head;
}

Node* List_maker(vector<int> aux){
    Node* head = new Node(aux[0]);
    int size=aux.size();
    for(int i=1;i<size;i++){
       head = LL(head,aux[i]);
    }
    return head;
}

vector<Node*> Return_LL_heads(BinaryTree<int>* root){
    queue<BinaryTree<int>*> q;
    vector<Node*> vec;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        vector<int> aux;
        while(q.front()!=NULL){
            int root_data = q.front()->data;
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }

            aux.push_back(root_data);
            q.pop();
        }
        
        q.pop();
        Node* head = List_maker(aux);
        if(!q.empty()){
            q.push(NULL);
        }
        vec.push_back(head);
    }
    return vec;
}

void Print_LL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    BinaryTree<int>* root = takeInput();
    PrintTree_Level(root);
    vector<Node*> vec=Return_LL_heads(root);
    cout<<"vector's size is: "<<vec.size()<<endl;
    int size= vec.size();
    for(int i=0;i<size;i++){
        Print_LL(vec[i]);
        cout<<endl;
    }
    delete root;
}
