#include <iostream>
using namespace std ;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

//Approach 2 without data replacement : T.C = O(n) and S.C = O(1) ;
Node* sortList(Node *head){
   Node* zerohead = new Node(0) ;
   Node* zerotail = zerohead ;
   Node* onehead = new Node(0) ;
   Node* onetail = onehead ;
   Node* twohead = new Node(0) ; 
   Node* twotail = twohead ;

   Node* temp = head ;
   while(temp != NULL){
       if(temp->data == 0){
           zerotail->next = temp ;
           zerotail = zerotail->next ;
       }
       else if(temp->data == 1 ){
           onetail->next = temp ;
           onetail = onetail->next ;
       }
       else{
           twotail->next = temp ;
           twotail = twotail->next ;
       }
       temp = temp->next ;
   }
   if(onehead->next != NULL){
       zerotail->next = onehead->next ;
   }
   else{
       zerotail->next = twohead->next ;
   }
   onetail->next = twohead->next ;
   twotail->next = NULL ;

   head = zerohead->next  ;
   return head ;
}