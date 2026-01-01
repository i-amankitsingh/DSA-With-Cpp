// BSF ( Breadth First Search ) Traversal in Graphs

#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph {
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int ind, int val){
        l[ind].push_back(val);
        l[val].push_back(ind);
    }

    void bfs(){ // O(V+E)
        queue<int> Q;
        vector<bool> vis(V, false);

        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0){
            int source = Q.front();
            Q.pop();
            cout<<source<<" ";

            for(int v: l[source]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }

};


 int main(){
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.bfs();

    return 0;
}