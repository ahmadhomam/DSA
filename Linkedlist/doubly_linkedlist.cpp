#include <iostream>
using namespace std ;

//making DLL
class node{
    public:
    int data ;
    node *pre ;
    node *next ;

    //constructor ;
    node(int data){
         this->data= data  ;
        this->pre = NULL ;
        this->next  = NULL ;
    }
    //destructor :
    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL ;
        }
        cout<<"this value is deleted : "<<this->data<<endl;
    }
};

void insertathead(int data,node *&head,node *&tail){
    //creating a node 
    node *temp = new node (data) ;
    if(head == NULL){
        head = temp ;
        tail = temp ;
    }
    else{
        temp->next= head ;
    head->pre = temp ;
    head = temp ;
    }
    
}
void insertAtTail(int data,node *&tail,node *&head){
    node *temp = new node(data);
    if(tail == NULL && head == NULL){
        tail = temp ;
        head = temp ;
    }
    else
    {
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
}
void insertAtPosition(int data,int position,node *&head ,node *&tail){
    node *temp  = head ;
    if(position == 1 ){
        insertathead(data,head,tail) ;
        return ;
    }
    else{
        int cnt = 1 ;
    while(cnt < position-1){
        temp = temp->next ;
        cnt++ ;
    }
    //creating a node ;
    node *nodetoinsert = new node(data) ;
    nodetoinsert->pre= temp ;
    nodetoinsert->next = temp->next ;
    if(temp->next == NULL){
        insertAtTail(data,tail,head) ;
        return ;
    }
    temp->next->pre = nodetoinsert;
    temp->next = nodetoinsert ;
    }
    
}

void deletionatposition(int position,node *&head,node *&tail){
    node *temp = head ;
    //deleting the first element ;
    if(position == 1){
        temp->next->pre = NULL ;
        head = temp->next ;
        temp->next = NULL ;
        delete temp ;
    }
    else{
        node *curr = NULL ;
        int cnt =1 ;
        while(cnt < position){
            temp = temp->next ;
            curr = temp ;
            cnt ++ ;
        }
        if(curr->next == NULL){
            curr->pre->next = NULL ;
            tail = curr->pre ;
            curr->pre = NULL ;
            curr->next= NULL ;
            delete curr ;
        }
        else{
            curr->pre->next = curr->next ;
        curr->next->pre = curr->pre ;
        curr->pre = NULL ;
        curr->next= NULL ;
        delete curr ;
        }
        

    }
}
void print(node *head){
    node *temp = head ;
    while(temp != NULL){
        cout<<temp->data<<" " ;
        temp = temp->next ;
    }
    cout<<endl ;
    cout<<"head : "<<head->data<<endl;
}
int main(){
    //node *node1 = new node(10) ;
    node *head = NULL ;
    node *tail = NULL ;
    //print(head) ;
    insertathead(22,head,tail) ;
    print(head) ;
    insertathead(30,head,tail) ;
    print(head) ;
    insertAtTail(8,tail,head) ;
    print(head) ;
    cout<<"tail : "<<tail->data<<endl ;
    insertAtPosition(55,4,head,tail) ;
    print(head) ;
    cout<<"tail : "<<tail->data<<endl ;
    deletionatposition(4,head,tail) ;
    print(head) ;
    cout<<"tail : "<<tail->data<<endl ;
    
}