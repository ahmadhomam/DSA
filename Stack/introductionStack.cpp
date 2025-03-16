#include<iostream>
#include<stack>
using namespace std;



    class Node{
        public :
        int data ;
        Node* next ;
    
        Node(int data){
            this->data = data ;
            this->next = NULL ;
        }
    
    } ;
    
    
    // IMPLEMENTING STACK USING LINKED LIST ;
    class Stack{
    
        public :
        int size =0;
        Node* top = NULL ;
    
    
        void push(int element ){
                size ++ ;
                Node* temp = new Node(element) ;
                temp->next = top ;
                top = temp  ;
            
        }
    
        void pop(){
            Node* temp = top ;
            top= top->next ;
            delete temp ;
            size -- ;
            
        }
    } ;
    
    int main(){
        Stack s_height ;
        s_height.push(4) ;
        cout<<"the size is : "<<s_height.size<<endl ;
        s_height.push(7) ;
        cout<<"the size is : "<<s_height.size<<endl ;
        s_height.push(1) ;
        cout<<"the size is : "<<s_height.size<<endl ;
        cout<<"the top is at : "<<s_height.top->data<<endl ;
        s_height.pop() ;
        cout<<"the top is at : "<<s_height.top->data<<endl ;

}
