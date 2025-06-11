#include <stdio.h>
using namespace std ;
#include <queue>
#include <stack>

// #APPROACH 1 ( STACK AS A AUXILARY SPACE )
class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        stack<int > s ;
        int second = q.size()/2 ;
        for(int i=0;i<second ;i++){
            s.push(q.front()) ;
            q.pop() ; 
        }
        while(!s.empty()){
            q.push(s.top()) ;
            s.pop() ;
        }
        for(int i=0;i<second;i++){
            int temp = q.front() ;
            q.push(temp);
            q.pop() ;
        }
        for(int i=0;i<second;i++){
            s.push(q.front()) ;
            q.pop() ;
        }
        while(!s.empty()){
            int temp = q.front() ;
            q.push(s.top()) ;
            s.pop() ;
            q.push(temp) ;
            q.pop() ;
        }
        return q ;
    }
};

//#APPROACH 2 ( QUEUE AS AUXILARY SPACE )
void interLeaveQueue(queue < int > & q) {
    int second = q.size()/2 ;
    queue <int> newq ;
    for(int i=0 ;i<second;i++){
        newq.push(q.front()) ;
        q.pop() ;
    }
    while(!newq.empty()){
        int temp = q.front() ;
        q.push(newq.front()) ;
        newq.pop() ;
        q.push(temp) ;
        q.pop() ;
    }
}