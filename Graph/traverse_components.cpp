#include <bits/stdc++.h>
using namespace std ;

int count_component(int V , vector<vector<int>> edges){
    int component = 0 ;
    vector<vector<int>> adj(V) ;
    vector<int> visited(V,0) ;

    for(auto e: edges){
        adj[e[0]].push_back(e[1]) ;
        adj[e[1]].push_back(e[0]) ;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            component++ ;

            queue<int> q ;
            q.push(i) ;
            visited[i]   =  1 ;

            while(!q.empty()){
                int node = q.front()  ;
                q.pop()  ;

                for(auto nbr : adj[node]){
                    if(!visited[nbr]){
                        visited[nbr] = 1 ;
                        q.push(nbr) ;
                    }
                }
            }
        }
    }
    return component ;
}

int count_component(int V , vector<vector<int>> edges){
    int component = 0 ;
    vector<vector<int>> adj(V) ;
    vector<int> visited(V,0) ;

    //creating a list of neighbour nodes 
    for(auto e:edges){
        adj[e[0]].push_back(e[1]) ;
        adj[e[1]].push_back(e[0]) ;

    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            component++ ;

            queue<int> q ;
            q.push(i) ;
            visited[i] = 1 ;

            while(!q.empty()) {
                int node = q.front() ;
                q.pop() ;

                for(auto nbr : adj[node]){
                    if(!visited[nbr]){
                        visited[nbr] =1 ;
                        q.push(nbr) ;
                    }
                }
            }
        }
    }
    return component ;
}