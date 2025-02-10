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

//  PALINDROME IN LINKEDLIST (using array creation)
// T.C = O(n) & S.C= O(n)[creating n size array] ;
bool checkpalindrome(vector<int> arr){
    int size = arr.size() ;
    int i =0 ;
    int e = size-1 ;
    while(i<=e){
        if(arr[i] != arr[e]){
            return false ;
        }
        i++ ;
        e-- ;
    }
    return true ;
}

bool isPalindrome(Node<int> *head)
{
    if(head->next == NULL){
        return true ;
    }
    vector<int> arr ;
    Node<int>* temp = head ;
    while(temp != NULL){
        arr.push_back(temp->data ) ;
        temp = temp->next ;
    }
    if(checkpalindrome(arr)){
        return true ;
    }
    else{
        return false ;
    }
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
