#include <stdio.h>
using namespace std ;
#include <queue>
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