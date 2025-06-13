#include <iostream>
#include <queue>
using namespace std ;

class node{
    public:
    int data ;
    node* left ;
    node* right ;

    node(int data){
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
} ;

node* Binarytree(node* root){
    //take the value of node
    cout<<"Enter the data: "<<endl ;
    int data ;
    cin>>data ;

    root = new node(data) ;

    if(data == -1){
        return NULL;
    }

    //take the left child data ;
    cout<<"Enter the data for inserting left of "<<data<<endl ;
    root->left = Binarytree(root->left) ;
    cout<<"Enter the data for inserting right of"<<data<<endl ;
    root->right = Binarytree(root->right) ;
    
    return root ;
}

void leveloftraversal(node* root){
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;

        if(temp == NULL){ // peeche wala level traverse ho chuka hai
            cout<<endl ;
            if(!q.empty()){
                q.push(NULL) ;
            }
        }
        else
            {
                cout<<temp->data<<" " ;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                    q.push(temp->right);
            }
    }
}

int main(){
    node* root  = NULL ;

    root = Binarytree(root) ;
    cout<<"printing the level order traversal output"<<endl ;
    leveloftraversal(root) ;
    return 0 ;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1