#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

/*

we have to check the cycle detection in the directed graph
we can't use the way as we used in undirected graph

input :

n=8
m=9

1->2
2->4
2->3
3->9
3->8
8->9
4->5
5->6
6->7

what we need in the past
visited  ds
parent ds
adjlist list 
if some node is visited and it's not the parent of that node

new logic
visited ds
dfsVisited ds
adjlist

dfs visited true when  call  and when come back from call  dfsvisited set false



*/
bool dfs(int node,unordered_map<int,bool> &visited,
    unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int>> &adjlist){
    
    visited[node]=true;
    dfsVisited[node]=true;

    for(auto neighbor:adjlist[node]){
        if(!visited[neighbor]){
            bool ans=dfs(neighbor,visited,dfsVisited,adjlist);
            if(ans)return true;
        }
        else{
            if (dfsVisited[neighbor]){
                return true;
            }
        }
    }
    dfsVisited[node]=false;
    return false;
}


bool detectCycleInDirectedGraph(int n,int m,vector<pair<int,int>> &edges){
    unordered_map<int,bool> visited;
    //make adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        //making a directed graph
        adjlist[u].push_back(v);
    }
    unordered_map<int,bool> dfsVisited;

    //traverse all the nodes
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bool check=dfs(i,visited,dfsVisited,adjlist);
            if(check)return true;
        }
    }
    return false;


}



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges(m);
        for(int i=0;i<m;i++){
            cin>>edges[i].first;
            cin>>edges[i].second;
        }
        bool ans=detectCycleInDirectedGraph(n,m,edges);
        if(ans){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }
    
    return 0;
}