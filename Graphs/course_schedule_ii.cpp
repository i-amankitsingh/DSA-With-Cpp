//  Course Schedule II problem

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

    void topoLogicalSorting(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &edges)
    {
        vis[src] = true;

        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src)
            {
                if (!vis[v])
                {
                    topoLogicalSorting(v, vis, s, edges);
                }
            }
        }
        s.push(src);
    }

    vector<int> isCycle(int n, vector<vector<int>> &edges)
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        vector<int> course;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, recPath, edges))
                {
                    return course;
                }
            }
        }

        stack<int> s;
        vis.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topoLogicalSorting(i, vis, s, edges);
            }
        }

        while (s.size() > 0)
        {
            course.push_back(s.top());
            s.pop();
        }

        return course;
    }
};

int main()
{
    Graph g(4);

    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        // {0, 1},
        {3, 1},
        {3, 2}};

    vector<int> ans = g.isCycle(4, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " << endl;
    }

    cout << endl;

    return 0;
}