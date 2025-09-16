#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>

/*
Breath first search traversal print 
we have multiple components in graph called disconnected components
n=5
m=5

0-1
1-2
2-3
3-4
2-4

ouput 0,3,1,2,4
require adjacency list
require a ds for visited track
unordered_map<node,bool> visited
-> require a queue data structure 
fifo
-> make adj list
-> visited =False
0->false
1->false
2->false
3->false
4->false

*/
using namespace std;

void prepareAdjList(unordered_map<int,list<int>> &adjlist,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }

   
}
void BFS(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans
,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);

        //Traverse all the neighbor of frontNode
        for (auto i:adjlist[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> bfs(int vertex,vector<pair<int,int>> edges){
    unordered_map<int,list<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjlist,edges);
     //Traverse all the disconnected components of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            BFS(adjlist,visited,ans,i);
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int vertex,m;
        cin>>vertex>>m;
        vector<pair<int,int>> edges(m);
        for(int i=0;i<m;i++){
            cin>>edges[i].first;
            cin>>edges[i].second;
        }
        vector<int> result=bfs(vertex,edges);
        //printing result
        for(auto i:result){
            cout<<i<<" ";
        }
    }
    return 0;
}