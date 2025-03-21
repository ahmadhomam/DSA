#include <iostream>
#include <stack>
using namespace std ;

//REVERSE A STRING USING STACK :

int main(){
    stack<char> st ;
    string s = "kazimi" ;
    for(int i=0;i<s.size();i++){
        char ch = s[i] ;
        st.push(ch) ;
    }
    string ans = "" ;
    while(st.empty() != true){
        char temp = st.top() ;
        ans.push_back(temp) ;
        st.pop() ;
    }
    cout<<"the reverse string is : "<<ans<<endl; 

}

// DELETING THE MIDDLE ELEMENT
void solve (stack<int>&inputStack, int N,int count){
    if(count == N/2){
       inputStack.pop() ;
       return ;
    }
 
    int temp = inputStack.top() ;
    inputStack.pop() ;
    solve(inputStack,N,count+1) ;
    inputStack.push(temp) ;
 }
 void deleteMiddle(stack<int>&inputStack, int N){
     
    // Write your code here
    int count =0 ;
    solve(inputStack,N,count) ;
 }



// CHECKING THE STRING IS BALANCED OR NOT
 bool isValidParenthesis(string s)
{
    int Size = s.size() ;
    stack<char> check ;
    int i=0 ;
    while(i<Size){
        char temp = s[i] ;

        if(temp == '(' || temp == '[' || temp == '{')
        check.push(temp) ;

       else if(check.size() == 0)
       return false ;

        else{
        if((temp == ')' && check.top() == '(') ||
        (temp == '}' && check.top() == '{') ||
        (temp == ']' && check.top() == '[')){
            check.pop() ;
        }
        }
        
        i++ ;
    }
    if(check.empty() == true){
        return true ;
    }
}



//PUSH ELEMENT AT THE BOTTOM OF STACK 
void solve(stack<int>& myStack, int x){
    if(myStack.size() ==0){
        myStack.push(x) ;
        return ;
    }
    int num = myStack.top() ;
    myStack.pop() ;
    solve(myStack,x) ;
    myStack.push(num) ;

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    //solving through recursion ;

    solve(myStack,x) ;
    return myStack ;
}


