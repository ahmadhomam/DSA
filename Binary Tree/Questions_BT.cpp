#include <iostream>
#include <queue>
using namespace std ;

template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//HEIGHT OF BINARY TREE ;

int height(TreeNode<int> *root)
{
	if(root == NULL)
    return 0 ;

    int left = height(root->left) ;
    int right = height(root->right) ;
    int height  = max(left ,right) ;
    return height +1 ; 
}

//DIAMETER OF BINARY TREE
int diameterOfBinaryTree(TreeNode<int> *root){
	if(root == NULL)
    return 0 ;

    int op1 = diameterOfBinaryTree(root->left) ;
    int op2 = diameterOfBinaryTree(root->right) ;
    int op3 = height(root->left)  + height(root->right) ;

    int ans = max(max(op1,op2),op3) ;
    return ans ;
}

//CHECK A BALANCED OR NOT 
pair<int,int> combo(TreeNode<int>* root){
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0) ;
            return p ;
        }
        pair<bool,int> left = combo(root->left) ;
        pair<bool,int> right = combo(root->right) ;
        
        pair<bool,int> ans  ;
        bool diff = abs(left.second - right.second) <=1 ;
        
        ans.second = max(left.second,right.second) + 1 ;
        
        if(left.first && right.first&& diff)
        ans.first = true ;
        else
        ans.first = false ;
        
        return ans ;
        
    }

bool isBalancedBT(TreeNode<int>* root){
    return combo(root).first ;
}

//SUM TREE :

class Solution {
  private:
   pair<bool ,int> combo(Node* root){
       if(root == NULL ){
           pair<bool,int> p = make_pair(true,0) ;
           return p ;
       }
       else if((root->left == NULL && root->right == NULL) ){
           pair<bool,int> q = make_pair(true,root->data) ;
           return q ;
       }
       
       pair<bool,int> left = combo(root->left) ;
       pair<bool,int> right = combo(root->right) ;
       pair<bool,int> ans ;
       
       bool equal = left.second + right.second == root->data ;
       
       if(left.first && right.first && equal){
           ans.first = true ;
           ans.second = 2* root->data ;//left.second + right.second + root->data ;
       }
       else{
           ans.first = false ;
           ans.second =left.second + right.second + root->data ;
       }
       return ans ;
   }
   
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return combo(root).first ;
    }
};
