#include <bits/stdc++.h>
using namespace std ;

// Graph representation using adjecency matrix 

int main(){
    int n, m ;
    cin>>n >> m ;

    //undirected graph
    int adj[n+1][n+1]  ;
    for(int i=0;i<m;i++){
        int u,v ;
        cin>>u>>v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ; // this is only in case of undirected graph
    }
    
}
