#include <iostream>
using namespace std ;
//  CREATING A LINKEDLIST :
class node{
    public:
    int data ;
    node *next ;

    //constructor ;
    node(int data){
        this -> data = data ;
        this ->next = NULL ;
    }
    //destructor:
    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL ;
        }
        cout<<"this value is deleted : "<<this->data<<endl;
    }

};
void insertathead(node * &head,int data){
    //creating a node 
    node *temp = new node(data) ;
    //pointing this node pointer to previous node value ;
    temp->next = head ;
    //head now pointing to temp ;
    head = temp ;
}
void insertattail(node * &tail,int d){
    //creating a node 
    node *temp = new node(d) ;
    tail->next = temp ;
    tail = temp ;
}
void insertatposition(int position ,node* &head,node* &tail,int data){
    //dealing with head insertion ;
    if(position ==1 ){
        insertathead(head,data) ;
        return ;
    }
    node *temp = head ;
    int cnt =1 ;
    while(cnt < position-1 ){
        temp = temp->next ;
        cnt ++ ;
    }
    //creating a node ;
    node *nodetoinsert = new node(data) ;
    nodetoinsert->next= temp->next ;
    temp->next = nodetoinsert ;
    
    //dealing with tail insertion ;
    if(nodetoinsert->next == NULL){
        tail = nodetoinsert ;
    }
}
void deletionatposition (int position ,node *&head,node *tail){
    node *temp = head ;
    if(position == 1){
        head = temp->next ;
        temp->next = NULL ;
        delete temp ;
    }
    else{
        int cnt = 1;
        node *curr = head ;
        node *pre = NULL ;
        while(cnt < position){
            temp = temp->next ;
            cnt ++ ;
            pre = curr ;
            curr = temp ;
        }
        //deletion of node ;
        pre->next = curr->next;
        curr->next = NULL ;
        delete curr ;
        if(pre->next==NULL){
            tail->data = pre->data ;
        }
    }
}

//treversing the linkedlist or printing the linkedlist :
void print(node * &head ){
    node *temp = head ;
    cout<<"head : "<<head->data<<endl;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next ;
    }
    cout<<endl ;
}

//Approach 1 :
node* reverseLL_1(node *&head){
    //we have to reverse a singly linked list ;
    node *pre = NULL ;
    node *curr  = head ;
    while(curr != NULL ){
        node *forw = curr->next ;
        curr->next = pre ;
        pre = curr ;
        curr = forw ;
        head = pre ;
    }
    return head ;
}

// Approach 2 :
void solve(node *&head,node *&pre,node *&curr){
    if(curr == NULL){
        head = pre ;
        return ;
    }
    solve(head,curr,curr->next) ;
    curr->next = pre ;
}
node* reverseLL_2(node *&head ){
    node *pre = NULL ;
    node *curr  = head ;
    solve(head,pre ,curr) ;
    return head ;
}

// Approach 3 :
node* solve(node *&head){
    if(head == NULL || head->next == NULL)
    return head ;

    node* chotahead = solve(head->next) ;
    head->next->next = head ;
    head->next = NULL ;
    return chotahead ;
}
node* reverseLL_3(node *&head){
    head = solve(head) ;
}

//APPROACH 1:
int getlength(node *head){
    int len = 0 ;
    node *temp = head ;
    while(temp != NULL){
        len ++ ;
        temp = temp->next ;
    }
    return len ;
}
void middle(node *&head ){
    int len = getlength(head) ;
    int ans = len /2 ;

    node *temp = head ;
    int count =0 ;
    while(count < ans ){
        temp = temp->next ;
        count ++ ;
    }
    head = temp ;
}

bool iscircular(node *head){
    if(head == NULL){
        return true ;
    }
    node *temp = head->next ;
    while(temp != NULL && temp != head){
        temp = temp->next ;
    }
    if(temp == NULL){
        return false ;
    }
    return true ;
}

int main(){
    node *node1 = new node(10) ;
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    node *head = node1 ;
    node *tail = node1 ;
    print(head) ;
    //inserting a new node at head ;
    insertathead(head,20) ;
    print(head) ;
    insertattail(tail,33) ;
    print(head) ;
    insertatposition(1,head,tail,5) ;
    print(head) ;

    // deletionatposition(1,head,tail) ;
    // print(head) ;
    // cout<<"head : "<<head->data<<endl ;
    // cout<<"tail : "<<tail->data<<endl ;
    reverseLL_1(head) ;
    print(head) ;
    reverseLL_2(head) ;
    print(head) ;
    // reverseLL_3(head) ;
    // print(head) ;
    // middle(head) ;
    // print(head) ;
    if(iscircular(tail)){
        cout<<"the LL is circular "<<endl ;
    }
    else{
        cout<<"the LL is not circular"<<endl ;
    }
}
