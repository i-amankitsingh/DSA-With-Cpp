// Detect a cycle in Undirected Graph using DFS

#include<iostream>
#include<list>
using namespace std;

class Graph{

    int V;
    list<int> *l;

    public:
    Graph(int V): V(V), l(new list<int>[V]){}

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool dfs(int src, int parent, vector<int> &vis){
        vis[src] = true;

        cout<<src<<" ";
        for(int neigh: l[src]){
            if(!vis[neigh]){
                if(dfs(neigh, src, vis)){
                    return true;
                }
            } else if (neigh != parent){
                return true;
            }
        }
        return false;
    }

    bool isCycleUnDirDFS(){
        int src = 0;
        vector<int> vis(V, false);
        int parent = -1;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(src, parent, vis)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(5);

    g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    bool ans = g.isCycleUnDirDFS();
    cout<<"\nans: "<<ans<<endl;

    return 0;
}