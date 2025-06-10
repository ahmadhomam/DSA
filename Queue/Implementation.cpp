#include <queue>

//IMPLEMENT A CIRCULAR QUEUE USING A ARRAY
class CircularQueue{
    public:
    int *arr ;
    int front ;
    int rear ;
    int n ;

    CircularQueue(int n){
        this->n = n ;
        arr = new int[n]  ;
        front= rear =-1 ;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //full
        if((front == 0 && rear == n-1) || (rear ==(front-1)%(n-1)))
        return false ;
        
        //empty
        if(front ==-1 ){
            front ++ ;
            rear++ ;
        }
        //rear is at last
        else if(rear == n-1){
            rear = 0 ;
        }
        else{
            rear++ ;
        }
            arr[rear] = value ;
        return true ;

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1 )
        return -1 ;

        int temp = arr[front] ;
        if(front == rear){
            front =-1  ;
            rear =-1 ;
            
        }
        else if(front == n-1){
            front = 0 ;
             
        }
        else{
            front ++ ;
            
        }
        return temp ;

    }
};
// IMPLEMENTING DOUBLE ENDED QUEUE ;
class Deque
{
public:
    int *arr ;
    int front ;
    int rear ;
    int n ;

    Deque(int n)
    {
        this->n = n ;
        front = -1 ;
        rear = -1 ;
        arr = new int[n] ;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //overflow 
        // modulo se bas limit case bachane ke liye + (front==0 hoga to 2nd condition shayad meet nhi kre )
        if((front == 0 && rear == n-1)|| (front !=0 && rear == (front-1)%(n-1))){
            return false ;
        }
        //only one element
        if(front == -1){
            front =0 ;
            rear =0 ;
        }
        //cyclic nature
        else if(front == 0 && rear != n-1){
            front = n-1 ;
        }
        else{
            front -- ;
        }
        arr[front] = x ;
        return true ;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        //overflow 
        if((front == 0 && rear == n-1)||(front !=0 && rear == (front-1)%(n-1))){
            return false ;
        }
        //only one element
        if(front == -1){
            front =0 ;
            rear =0 ;
        }
        //cyclic nature
        else if(rear == n-1 && front != 0){
            rear = 0 ;
        }
        else{
            rear++ ;
        }
        arr[rear] = x ;
        return true ;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front ==-1){
            return -1 ;
        }
        int temp = arr[front] ;
        arr[front] = -1 ;
        if(front == rear){
            front = -1 ;
            rear = -1 ;
        }
        else if(front == n-1){
            front = 0 ;
        }
        else{
            front ++ ;
        }
        return temp ;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(front == -1 )
        return -1 ;

        int temp = arr[rear] ;
        arr[rear] = -1 ;
        if(front == rear){
            front =-1  ;
            rear = -1 ;
        }
        else if(rear == 0){
            rear = n-1 ;
        }
        else{
            rear -- ;
        }
        return temp ;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(front == -1 )
        return -1 ;

        else{
            return arr[front] ;
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(front == -1 )
        return -1 ;
        else{
            return arr[rear] ;
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1 )
        return true ;
        
        else{
            return false ;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == n-1) || (rear == (front-1)%(n-1 ))){
            return true ;
        }
        else{
            return false ;
        }
    }
};