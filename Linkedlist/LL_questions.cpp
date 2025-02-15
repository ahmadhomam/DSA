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
        Node* random ;

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

// CLONE A LINKEDLIST WITH RANDOM POINTERS ;

// step 1 : create an linkedlist and mapping corresponding element to the LL ;
// step2 : then the random of clone element = map[original->random] ;
#include <unordered_map> 
void insertattail(Node<int>* &head ,Node<int>* &tail,int value){
	Node<int>* temp = new Node<int>(value) ;
	if(head == NULL){
		head = temp ;
		tail = temp ;
		return ;
	}
	tail->next = temp ;
	tail = temp ;
}

Node<int> *cloneLL(Node<int> *head){
	Node<int> *temp = head ;
	Node<int>* clonehead = NULL ;
	Node<int>* clonetail = NULL ;
	unordered_map<Node<int>*,Node<int>*> oldnew ;
	while(temp != NULL){
		insertattail(clonehead,clonetail,temp->data) ;
		oldnew[temp] = clonetail ;
		temp = temp->next ;
	}
	temp = head ;
	Node<int>* temp2 = clonehead ;
	while(temp2 != NULL){
		temp2->random = oldnew[temp->random] ;
		temp2= temp2->next ;
		temp = temp->next ;
	}
	return clonehead ;
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
