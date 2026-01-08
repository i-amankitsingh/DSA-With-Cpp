// Detect cycle in undirected graph using BFS

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v): V(v), l(new list<int>[V]){}
    
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool bfs(int src, vector<int> &vis){
        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = true;
        while(q.size() > 0){
            int index = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int neigh: l[index]){
                if(!vis[neigh]){
                    q.push({neigh, index});
                    vis[neigh] = true;
                } else if(vis[neigh]) {
                    if(neigh != parent){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool isCycle() {
        vector<int> vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, vis)){
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
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    vector<int> vis(5, false);
    bool ans = g.bfs(0, vis);

    cout<<ans<<endl;

    return 0;
}