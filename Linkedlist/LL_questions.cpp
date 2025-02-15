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

// ADD TWO NUMBERS AS LINKED LIST :
/*  step1 : reverse both the linked list ;
    step2 : add each element using(sum,digit,carry) and put this new linkedlist (insertattail) ;
    step3 : again reverse the Linkedlist ;
*/

//T.C = O(n)[reverse]+O(m)[reverse]+O(max(n,m))[traverse for sum]+O(n+m)[max size of ans LL] = O(n+m)
//S.C = O(max(n,m))[making ans LL ] ;

Node<int>* reverse(Node<int>* head ){
    if(head ==NULL || head->next == NULL)
    return head ;

    Node<int>* chotahead = reverse(head->next ) ;
    head->next->next = head ;
    head->next = NULL ;
    return chotahead ;
}

void inserattail(Node<int>* &head,Node<int>* &tail ,int value){
    Node<int>* temp = new Node<int>(value) ;
    if(head == NULL){
        head = temp ;
        tail = temp ;
        return ;
    }
    tail->next = temp ;
    tail = temp ;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    first = reverse(first) ;
    second = reverse(second) ;

    Node<int>* anshead = NULL ;
    Node<int>* anstail = NULL ;


    int carry = 0 ;
    while(first != NULL || second != NULL || carry != 0){
        int val1 = 0 , val2 = 0 ;
        if(first != NULL)
        val1 = first->data ;
        if(second != NULL)
        val2 = second->data ;

        int sum = val1 + val2 + carry ;
        int digit = sum % 10 ;
        inserattail(anshead,anstail,digit) ;
        carry = sum /10 ;

        if(first != NULL)
        first = first->next ;

        if(second != NULL)
        second = second->next ;
    }
    anshead = reverse(anshead) ;
    return anshead ;
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
