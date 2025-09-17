#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
using namespace std;

/*
Topological sort using dfs
work only of dag

what?
linear ordering of vertices such that very edge of u is appearing before v in ordering

input 
4 4
0->1
0->3
1->2
3->2

valid topological sort
0 1 3 2 valid

3 2 1 0 invalid 

i have to print the valid topological sort using dfs

we can only apply to directed acyclic graph

if the loop is present we can't find valid topological sort


input :
n=6,m=7

1->2
1->3
2->4
4->5
4->6
5->6
3->4
adj list
1 : {2, 3}
2 : {4}
3 : {4}
4 : {5, 6}
5 : {6}
6 : {}

require
stack additional ds
adjlist
visited


*/
void dfs(int node,unordered_map<int,bool> &visited,stack<int> &s,
    unordered_map<int,list<int>> &adjlist){
    visited[node]=true;

    //dfs call of all the nodes of neighbor of that particular node
    for(auto neighbor:adjlist[node]){
        if(!visited[neighbor]){
            dfs(neighbor,visited,s,adjlist);
        }
    }

    //here at the end i have to push element in the stack base case i missed
    s.push(node);

}


vector<int> topologicalSort(int n,int m,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        //it's a directed graph
        adjlist[u].push_back(v);
    }

    //creating a visited a array and stack
    unordered_map<int,bool> visited;
    stack<int> s;

    //traverse all the disconnected notes
    for(int i=1;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,s,adjlist);
        }
    }

    //making a vector and return all the element in the form of list
    vector<int> ans;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        ans.push_back(top);
    }
    return ans;

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

        vector<int> ans=topologicalSort(n,m,edges);

        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}