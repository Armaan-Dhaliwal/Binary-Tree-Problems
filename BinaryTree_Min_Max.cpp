/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include<iostream>
#include<queue>
#include<climits>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

pair<int, int> getMinAndMax(BinaryTree<int> *root) {
	if(root==NULL){
		pair<int, int> p;
		p.first=INT_MAX;
		p.second=INT_MIN;
		return p;
	}

	pair<int,int> left = getMinAndMax(root->left);
	pair<int,int> right =getMinAndMax(root->right);
	int lmin=left.first;
	int lmax=left.second;

	int rmin = right.first;
	int rmax = right.second;

	int minimum = min(min(lmin,rmin),root->data);
	int maximum = max(max(lmax,rmax),root->data);
	pair<int,int> p;
	p.first=minimum;
	p.second=maximum;
	return p;

}