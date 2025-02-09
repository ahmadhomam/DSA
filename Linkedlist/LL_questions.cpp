#include <bits/stdc++.h>

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

// remove DUPLICATES in LL (1st Approach )
Node<int> *removeDuplicates(Node<int> *head)
{
    if(head == NULL || head ->next == NULL){
        return head ;
    }
    Node<int> * curr = head ;
    while(curr != NULL){
        Node<int> *temp = curr->next ;
        Node<int> *pre= curr ;
        while(temp != NULL){
            if(curr->data == temp->data){
                Node<int>* node_todelete = temp ;
                pre->next = temp->next  ;
                temp = temp->next ;
                delete node_todelete ;
               // continue ;
            }
            else{
            pre = temp ;
            temp = temp->next ;
            }

        }
        curr = curr->next ;
    }
    return head ;
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
