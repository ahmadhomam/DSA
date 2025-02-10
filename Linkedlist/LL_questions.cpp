#include <iostream>
#include <unordered_map> 
#include <vector>
using namespace std ;


/************************************************************

    Following is the linked list node structure.*/
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

    

// **********************************************************

//  PALINDROME IN LINKEDLIST )
// T.C = O(n)+ O(n) + O(n/2) == O(n) & S.C= O(1)[creating n size array] ;
Node<int>* getmid(Node<int>* head){
    Node<int>* slow = head ;
    Node<int>* fast = head->next  ;
    while(fast != NULL){
        fast = fast->next ;
        if(fast != NULL){
            fast = fast->next ;
        }
        slow = slow ->next ;
    }
    return slow ;
}

Node<int>* reverse(Node<int>* head){
    if(head == NULL || head->next == NULL){
        return head ;
    }
    Node<int>* temp = head ;
    Node<int>* chotahead = reverse(temp->next ) ;
    temp->next->next = temp  ;
    temp ->next = NULL ;
    return chotahead ;
}
/*
Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }*/

bool isPalindrome(Node<int> *head)
{
    // 1: find the mid 
    // 2: reverse the Linkedlist from mid ;
    // 3: check if all the data is same or not ;
    // return true (but also rearrange the LL

    if(head->next == NULL){
        return true ;
    }
    Node<int> *mid = getmid(head) ;
    Node<int>* temp = mid->next ;
    mid->next = reverse(temp) ;

    Node<int>* head1 = head ;
    Node<int>* head2 = mid->next ;
    while(head2 != NULL){
        if(head1->data != head2->data){
            return false ;
        }
        head1= head1->next ;
        head2 = head2->next ;
    }
    return true ;

}

// Merge two sorted linkedlist 

Node<int>* solve(Node<int>* first ,Node<int>* second ){
    Node<int>* curr1 = first  ;
    Node<int>* next1 = curr1->next ;
    Node<int>* curr2 = second ;
    Node<int>* next2 = curr2->next ;

    // if there is only one element in first list ;
    if(next1 == NULL){
        curr1->next = curr2 ;
        return first ;
    }


    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))  {
        //adding element in between two element ;
        curr1->next = curr2 ;
        next2 = curr2->next ;
        curr2->next = next1 ;

        //updating the the pointer after adding element in between ;
        curr1 = curr1->next ;
        curr2 = next2 ;
    }
    else{
        //updating pointer for next set condition ;
        curr1 = curr1->next ;
        next1 = next1->next ;

        //checking if the first list end , just adding remaining element of 2nd list ;
        if(next1 == NULL){
            curr1->next = curr2 ;
            return first ;
        }
    }

    }
     return first ;

}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL){
        return second ;
    }
    else if(second == NULL){
        return first ;
    }

    // condition to decide the first list ;

    if(first->data <= second->data){
        solve(first ,second) ;
    }
    else{
        solve(second ,first) ;
    }
}
