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

//BUILDING BINARY TREE BY LEVEL ORDER TRAVERSAL
void buildleveloftraversal(node* &root){
    queue<node*> q ;
    int data ;
    cout<<"Enter the data for root : "<<endl ;
    cin>>data ;
    root = new node(data) ;
    q.push(root) ;

    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        
        int leftdata; 
        cout<<"Enter the left data for"<<temp->data<<endl;
        cin>>leftdata ;
        if(leftdata != -1){
            temp->left = new node(leftdata) ;
            q.push(temp->left) ;
        }

        int rightdata; 
        cout<<"Enter the right data for"<<temp->data<<endl;
        cin>>rightdata ;
        if(rightdata != -1){
            temp->right = new node(rightdata) ;
            q.push(temp->right) ;
        }
    }
}

int main(){
    node* root  = NULL ;
    buildleveloftraversal(root) ;
    // root = Binarytree(root) ;
    cout<<"printing the level order traversal output"<<endl ;
    leveloftraversal(root) ;
    return 0 ;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1