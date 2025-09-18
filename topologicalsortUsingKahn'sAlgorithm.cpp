#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;
/*
Topological sort using Kahn's algorithm
input :
n=4,m=4
0->1
0->3
1->2
3->2

adjlist 
0 -> 1,3
1 -> 2
3-> 2
2-> 


0 1 3 2 valid 


Question use bfs to do topological sort

bfs queue need

----------------------------important-------------------------------
step 1: find indegree all nodes
step 2: queue  all 0 indegree nodes add to queue
step 3: do bfs simple


input 
n=5
m=5
1->3
1->2
3->5
2->5
5->4

adjlist:
1-> 2,3
2-> 5,
3-> 5
5->4

*/

vector<int> topologicalSort(int n,int m,vector<vector<int>> &edges){
    //make adjlist
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        //make a directed graph
        adjlist[u].push_back(v);
    }

    // find all the indegree of nodes
    vector<int> indegree(n);
    for(auto i: adjlist){
        for(auto j:i.second){
            indegree[j]++;
        }
    }


    //make a queue and push all those nodes their indegree is zero
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //now do simple bfs
    vector<int> ans;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();

        ans.push_back(frontNode);

        //neighbor indegree update
        for(auto neighbor:adjlist[frontNode]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }


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