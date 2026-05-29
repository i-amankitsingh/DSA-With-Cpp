// Course Schedule I Problem

#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v) : V(v), l(new list<int>[V]) {}

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }

    bool dfs(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &edges)
    {
        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src)
            {
                if (!vis[v])
                {
                    if (dfs(v, vis, recPath, edges))
                    {
                        return true;
                    }
                }
                else if (recPath[v])
                {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycle(int n, vector<vector<int>> &edges)
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, recPath, edges))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g(4);

    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}};

    cout << g.isCycle(4, edges) << endl;

    return 0;
}