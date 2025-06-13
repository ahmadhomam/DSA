using namespace std ;
#include <unordered_map>
#include <queue>
#include <string>
#include <stack>

//FIRST -VE INTEGER IN WINDOW OF SIZE K
vector<int> firstNegative(vector<int> arr, int n, int k) {
	queue<int> q ;
	vector<int>ans ;

	for(int i=0;i<k;i++){
		if(arr[i]<0){
			q.push(i) ;
		}
	}
	if(q.empty())
	ans.push_back(0) ;
	else
	ans.push_back(arr[q.front()]) ;

	for(int i=k;i<arr.size();i++){
			//removal ;
			if(!q.empty() && i-q.front() >= k){
				q.pop() ;
			}
			//addition
			if( arr[i]<0){
				q.push(i) ;
			}
			if(q.empty())
			ans.push_back(0) ;
			
			else
			ans.push_back(arr[q.front()]) ;
	}
	return ans ;

}

//FIRST NON REPEATING CHARACTER IN STREAM OF STRING 
class Solution {
  public:
    string FirstNonRepeating(string &s) {
         unordered_map<char,int> count ;
         queue<char>q ;
         string ans = "" ;
         
         for(int i= 0;i<s.length();i++){
             char ch = s[i] ;
             count[ch]++ ;
             
             q.push(ch) ;
             while(!q.empty()){
                 if(count[q.front()] > 1){
                     q.pop() ;
                 }
                 else{
                     ans.push_back(q.front()) ;
                     break ;
                 }
             }
             if(q.empty())
             ans.push_back('#') ;
             
         }
         return ans ;
    }
};