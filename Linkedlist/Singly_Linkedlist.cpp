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
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next ;
    }
    cout<<endl ;
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
    deletionatposition(1,head,tail) ;
    print(head) ;
    cout<<"head : "<<head->data<<endl ;
    cout<<"tail : "<<tail->data<<endl ;

}
