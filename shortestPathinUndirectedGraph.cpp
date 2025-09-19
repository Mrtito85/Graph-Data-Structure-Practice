#include <iostream>
#include <unordered_map>
#include<list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
we have undirected weighted graph we have to find the shortest path to src node to destination node
or we can find the path all path from source to destination

input graph :
n=8
m=9

1->2
1->3
1->4
2->5
5->8
3->8
4->6
6->7
7->8

source node is 1
destination node is 8
by default weight is 1
1->3->8 shortest path is 2
output 1->3->8

approach :
bfs the print the graph level by level
||||||
adjlist
visited ds
parent ds
queue because bfs

->adjlist 
1->2,3,4
2->1,5
3->1,8
4->1,6
5->2,8
6->4,7
7->6,8
8->3,5,7


backtrack through parent
and reverse the answer
*/

vector<int> shortestPathUndirectedWeightGraph(int n,int m,vector<pair<int,int>> &edges,int s,int d){
    //make an adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    //make visited ds parent ds and queue
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    parent[s]=-1;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
        for(auto neighbor:adjlist[frontNode]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                parent[neighbor]=frontNode;
                q.push(neighbor);
            }
            
        }
    }

    int currNode=d;
    vector<int> ans;
    ans.push_back(currNode);
    while(currNode!= s){
        currNode=parent[currNode];
        ans.push_back(currNode);
    }
    //reverse the answer and return
    reverse(ans.begin(),ans.end());
    return ans;

}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        
        int n,m,s,d;
        cin>>n>>m>>s>>d;
        vector<pair<int,int>> edges;
    
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            edges.push_back({u,v});
        }
        
        
        vector<int> result =shortestPathUndirectedWeightGraph(n,m,edges,s,d);
        for(auto i:result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}