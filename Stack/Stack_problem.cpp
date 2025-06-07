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

// CELEBRITY PROBLEM :
class Solution {
  private: 
    bool knows(int i,int j,vector<vector<int> >& mat){
        if(mat[i][j] == 1)
        return true ;
        else
        return false ;
    }
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st ;
        int n = mat[0].size() ;
        for(int i =0;i<n;i++){
            st.push(i) ;
        }
        
        while(st.size() > 1){
        int a = st.top() ;
        st.pop() ;
        int b = st.top() ;
        st.pop() ;
            if(knows(a,b,mat)){
            st.push(b) ;
        }
        else{
            st.push(a) ;
        }
        }
        int potential = st.top() ;
        
        for(int i = 0; i < n; i++) {
            if(i != potential) {
                if(mat[potential][i] == 1 || mat[i][potential] == 0)
                    return -1;
            }
        }
        return potential;

    }
};

//MAXIMUM AREA OF RECTANGLE IN MATRIX.
class Solution {
  private:
    vector<int>nextelement(vector<int>arr,int n){
    stack<int> st ;
    st.push(-1) ;
    vector<int> ans(n) ;

    for(int i =n-1;i>=0;i--){
        int curr = arr[i] ;
        while(st.top() != -1 && arr[st.top()]>= curr){
            st.pop() ;
        }
        ans[i]  = st.top() ;
        st.push(i) ;
    }
    return ans ;
    }
    
    vector<int>prevelement(vector<int>arr,int n){
    stack<int> st ;
    st.push(-1) ;
    vector<int> ans(n) ;

    for(int i =0;i<n;i++){
        int curr = arr[i] ;
        while(st.top() != -1 && arr[st.top()]>= curr){
            st.pop() ;
        }
        ans[i]  = st.top() ;
        st.push(i) ;
    }
    return ans ;
    }
    
    int maxarea(vector<int>arr,int n){
            int area = 0 ;
            vector<int>next(n);
            next = nextelement(arr,n) ;
            
            vector<int>prev(n);
            prev= prevelement(arr,n) ;
        for(int i =0;i<n;i++){
            
            int l = arr[i] ;
            if(next[i] == -1) next[i] = n ;
            int b = next[i] - prev[i] -1 ;
            int newarea = l*b ;
            area = max(area,newarea) ;
            
        }
        return area ;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size() ;
        int m = mat[0].size() ;
        int area = maxarea(mat[0],m) ;
        
        for(int i =1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i][j]+ mat[i-1][j] ;
                }
                else{
                    mat[i][j] = 0 ;
                }
            }
            area = max(area,maxarea(mat[i],m)) ;
        }
        return area ;
        
    }
};