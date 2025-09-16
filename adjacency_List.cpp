#include <iostream>
using namespace std;
/*
graph DATA STRUCTURE
GRAPH HAS NODE AND EDGES    
we have directed graph and undirected graph
u->v
v->u

undirected

u->v

Node is an entity 
edge for connection of nodes

degree of nodes-> means how many nodes are connected to that particular node

in directed graph we have indegree and out degree

edges has weight
weight =2 
a->b  
b->c   weight =1
a->c weight =2


->if we have weight and direction then it's weighted directed graph

Path u->v->p
notPath u->v->p->u wrong thing

cyclic graph


a->b->c->d->a    cyclic directed graph and if it's has some weight then it's cyclic directed weight graph

a->b->c->d
a->d          this is acyclic directed graph graph


graph can be build using 
adjacency matrix 
adjacency list


input 

number of nodes
number of edges
n=3
m=3

0->1
1->2
2->0

using adjacency matix print graph


adjacency list

0 -> 1,4
1 -> 0,1,2
2 -> 1,3
3 -> 1,2,4
4 -> 0,3

entity and it's crossponding list

implementation
map<int,list<int>> graph;

input 
5
6
0 1
1 2
2 3
3 1
3 4
4 0

output adjacency list
4-> 3, 0, 
0-> 1, 4,
1-> 0, 2, 3,
2-> 1, 3,
3-> 2, 1, 4,
*/
#include <unordered_map>
#include <list>
#include <vector>
class graph {
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v,bool direction){
        //direction =0 --> undirected graph
        //direction =1 --> directed graph

        //creating an edge
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for (auto i :adj){
            cout<<i.first<<"-> ";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edges){
    vector<vector<int>> ans(n);
    for (int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        //adding to answer so that i can store it into neighbor
        ans[u].push_back(v);
        ans[v].push_back(u);

    }
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);    

        //adding all neighbor
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main(){
    // int n;
    // int m;
    // graph g;
    // cin>>n>>m;
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addEdge(u,v,0);
    // }
    // g.printAdjList();

    // int n=5;
    // int m=6;
    // vector<vector<int>> edges={
    //     {0,1},{0,4},{1,2},{1,3},{1,4},{2,3}
    // };
    // vector<vector<int>> adj=printAdjacency(n,m,edges);
    // for(int i=0;i<adj.size();i++){
    //     for(int j=0;j<adj[i].size();j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++){
            cin>>edges[i][0]>>edges[i][1];
        }
        vector<vector<int>> result=printAdjacency(n,m,edges);

        //printing result
        for(auto &row:result){
            for(auto x:row){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}