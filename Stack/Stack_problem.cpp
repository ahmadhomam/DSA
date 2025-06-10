#include <iostream>
#include <stack>
#include <vector>
#include <climits>
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



// IS REBUNDANT BRACKET OR NOT
bool findRedundantBrackets(string &s)
{
    stack<char > bra ;
    bool isredundant = true ;
    for(int i = 0;i<s.size();i++){
        char ch = s[i] ;
        if(ch == '(' ||ch == '+' ||ch == '-' ||ch == '*' ||ch == '/'){
            bra.push(ch) ;
        }
        else{
            if(ch == ')'){
                bool isredundant = true ;
                while(bra.top() != '('){
                char top = bra.top() ;
                    if(top == '+' ||top == '-' ||top == '*' ||top == '/'){
                        isredundant = false ;
                    }
                bra.pop() ;
                }
                if(isredundant == true){
                    return true ;
                }
                bra.pop() ;
            }
        }
    }
    return false ;
}

// NEXT SMALLER ELEMENT : 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st ;
    vector<int>ans(n) ;
    st.push(-1) ;
    for(int i = n-1;i>=0;i--){
        int curr = arr[i] ;
        while(st.top() >= curr){
            st.pop() ;
        }
        ans[i] = st.top() ;
        st.push(curr) ;
    }
    return ans ;
}

// Design a stack that supports getMin() in O(1) time and O(1) extra space
class SpecialStack {
    public:
    int mini = INT_MAX;
    stack<int>s ;
        
    void push(int data) {
        if(s.empty()){
            s.push(data) ;
            mini = data ;
        }
        else{
            if(data < mini){
                s.push(2*data - mini);
                mini = data ;
            }
            else{
                s.push(data) ;
            }
        }
    }

    void pop() {

        int curr = s.top() ;
            s.pop() ;
        if(curr< mini){
            int prevmini = mini ;
            int val = 2*mini - curr ;
            mini = val ;
        }
    }

    int top() {
        int curr = s.top( ) ;
        if(curr<mini){
            return mini ;
        }
        else{
            return curr ;
        }
    }

    int getMin() {
        return mini ;
    }  
};