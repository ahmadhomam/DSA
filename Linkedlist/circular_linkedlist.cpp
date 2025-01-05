#include <iostream>
using namespace std ;

class  node {
    public:
    int data ;
    node *next ;

    node(int data){
        this->data = data ;
        this->next = NULL ;
    }

    ~node(){
        if(this->next != NULL){
            delete next ;
            this->next  = NULL ;
        }
        cout<<"this value is deleted : "<<this->data <<endl;
    }
} ;

void insertatposition(int element ,int data ,node *&tail ){
    //empty list ;
    node *temp = new node(data) ;
    if(tail == NULL ){
        tail = temp ;
        temp->next= temp ;
    }
    else{
        node *curr = tail ;
        while(curr->data != element){
            curr = curr->next ;
        }
        //element found at curr ;
        temp->next  = curr->next ;
        curr->next = temp ;

    }
}
void delete_element(int element ,node *&tail){
    if(tail == NULL ){
        cout<<"there is no element to delete "<<endl ;
        return ;
    }
    else{
        node *pre = tail ;
        node *curr = pre->next ;
        
        while(curr->data != element){
            pre = curr ;
            curr = curr->next ;
        }
        pre->next  = curr->next ;
        if(pre == curr){
            tail = NULL ;
        }
        else if(curr == tail){
            tail= pre ;
        }
        curr->next = NULL ;
        delete curr ;
        

    }

    //
}
void print(node *&tail){
    node *temp = tail ;
    if(tail == NULL){
        cout<<"the list is empty ."<<endl ;
        return ;
    }
    do{
        cout<<temp->data<<" " ;
        temp=temp->next ;
    }
    while(tail != temp) ;
    cout<<endl; 
}
int main(){
    node *tail = NULL ;
    insertatposition(5,3,tail) ;
    print(tail) ;
    // insertatposition(3,5,tail) ;
    // print(tail) ;
    // insertatposition(3,10,tail) ;
    // print(tail) ;
    // insertatposition(5,17,tail) ;
    // print(tail) ;
    // insertatposition(5,33,tail) ;
    // print(tail) ;
    // insertatposition(17,25,tail) ;
    // print(tail) ;
    // cout<<"tail : "<<tail->data<<endl;
    delete_element(3,tail) ;
    print(tail) ;
}