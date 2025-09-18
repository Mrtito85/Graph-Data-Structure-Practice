#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>

using namespace std;


/*
DAG only valid topological sort use kahn's algorithm using bfs

what we do 
calculate indegree of all the nodes
if the indegree is zero push to queue
simple bfs
if count == nodes then then cycle is not present else present

*/

bool cycleDetectionUsingBFS(int n,int m,vector<pair<int,int>> &edges){
    //make adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        //Directed graph making
        adjlist[u].push_back(v);
    }

    //calculate the indegree of all nodes
    vector<int> indegree(n,0);
    for(auto i:adjlist){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //if the indegree is zero push to queue
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //simple bfs
    int count=0;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        //increment the count
        count++;

        //updating the neigbor nodes
        for(auto neighbor:adjlist[frontNode]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }

    if(count==n){
        //it's mean we have topoical sort and cycle is not present
        return false;
    }
    else{
        return true;
    }
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
        bool ans=cycleDetectionUsingBFS(n,m,edges);
        if(ans){
            cout<<"Cycle is Present "<<endl;
        }else{
            cout<<"Cycle not present "<<endl;
        }
    }
    
    return 0;
}