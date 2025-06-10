#include <queue>

//IMPLEMENT A QUEUE USING A ARRAY
class Queue {
public:

    int face ;
    int rear ;
    int size ;
    int *arr ;

    Queue() {
        size = 10001 ;
        arr = new int [size] ;
        face =0 ;
        rear = 0 ;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(face == rear)
        return true ;
        else
        return false ;
    }

    void enqueue(int data) {
        if(rear == size){
            return ;
        }
        else{
            arr[rear] = data ;
            rear++ ;
        }
    }

    int dequeue() {
        if(face == rear){
            return -1 ;
        }
        else{
            int temp = arr[face] ;
            arr[face] = -1 ;
            face ++ ;
            if(face == rear){
                // after pushing and poping the queue is empty at index 4.
            // and if we push again it will start from index 4 ,(wasting the staring 4 places)
                face =0 ;
                rear = 0 ;
            }
            return temp ;
        }
    }

    int front() {
        if(face == rear) 
        return -1 ;
        else 
        return arr[face ] ;
    }
};