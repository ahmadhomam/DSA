#include<iostream>
#include<stack>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if(top >=0 ) {
            top--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){
    Stack s_height(5) ;
    s_height.push(4) ;
    cout<<"the size is : "<<s_height.size<<endl ;
    cout<<"the peek of stack is : "<<s_height.peek()<<endl ;
    s_height.push(11) ;
    
    cout<<"the peek of stack is : "<<s_height.peek()<<endl ;
    s_height.pop() ;

    cout<<"the peek of stack is : "<<s_height.peek()<<endl ;
    cout<<"Is stack is empty : "<<s_height.isEmpty()<<endl ;
    s_height.pop() ;
    s_height.pop() ;
    cout<<"Is stack is empty : "<<s_height.isEmpty()<<endl ;

}
