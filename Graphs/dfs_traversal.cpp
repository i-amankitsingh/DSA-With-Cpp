// DFS ( Depth First Search ) Traversal

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int a, int b)
    {
        l[a].push_back(b);
        l[b].push_back(a);
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;

        for (int v : l[u])
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs()
    {
        int src = 0;
        vector<bool> vis(V, false);

        // For disconnected nodes(vertix)
        /*
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsHelper(i, vis);
            }
        }
        */

        dfsHelper(src, vis);
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.dfs();

    return 0;
}