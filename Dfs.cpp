#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

/*
Depth first traversal
visited
adjlist
ans

*/
void dfs(int node,unordered_map<int,bool> &visited,
    unordered_map<int,list<int>> &adjlist,vector<int> &component){
        visited[node]=1;
        component.push_back(node);
        for(auto i:adjlist[node]){
            if(!visited[i]){
                dfs(i,visited,adjlist,component);
            }
        }
}
vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>> &edges){
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    //traverse all the disconnected components
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjlist,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>> edges(E,vector<int>(2));
        for(int i=0;i<E;i++){
            cin>>edges[i][0];
            cin>>edges[i][1];
        }
        vector<vector<int>> result=depthFirstSearch(V,E,edges);
        //printing the result
        for(auto i:result){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }    
    return 0;
}