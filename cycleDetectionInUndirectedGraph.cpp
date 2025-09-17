#include <iostream>
#include <unordered_map>
#include <list>
#include<vector>
#include <queue>
using namespace std;

/*
Cycle detection in undirected graph
-> use bfs and dfs
->WE HAVE disconnected graph

1-2
2-3

4-5
5-6
6-8
8-7
8-9
7-5

need 
adjlist
visited
tell cycle present or not
we have to track parent
use queue 

ignore condition 
if parent && true -> not add queue
if visited ==True && !parent then cycle present true





*/

bool bfs(int src,unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited){
    queue<int> q;
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=true;
    q.push(src);


    while(!q.empty()){
        int front =q.front();
        q.pop();

        for (auto neighbor:adjlist[front]){
            if(visited[neighbor]==true && neighbor!=parent[front]){
                return true;
            }
            else if (!visited[neighbor]){
                q.push(neighbor);
                parent[neighbor]=front;
                visited[neighbor]=true;
            }
        }
    }
    return false;

}

string cycleDetection(vector<vector<int>> &edges,int n,int m){
    //make adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int,bool> visisted;

    //Traverse all the disconnected components
    for(int i=0;i<n;i++){
        if(!visisted[i]){
            bool ans=bfs(i,adjlist,visisted);
            if(ans==1){
                return "True";
            }
        }
    }
    return "False";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++){
            cin>>edges[i][0];
            cin>>edges[i][1];
        }
        string ans=cycleDetection(edges,n,m);
        cout<<ans<<endl;
    }

    return 0;
}