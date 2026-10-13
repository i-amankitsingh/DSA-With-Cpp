#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cstdarg>
#include<cstddef>
#include<cstdbool>

using namespace std;

int primsMST(int V, vector<vector<pair<int, int>>> adj){
    vector<bool> inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstCost = 0;
    
    pq.push({0, 0});
    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;
        mstCost += wt;
        for(auto &edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(!inMST[v]) pq.push({w, v});
        }
    }
    return mstCost;
}

int main(){
    int V = 4;
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[0].push_back({3, 30});
    adj[3].push_back({0, 30});

    adj[0].push_back({2, 15});
    adj[2].push_back({0, 15});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});


    adj[2].push_back({3, 50});
    adj[3].push_back({2, 50});


    cout << "Minimum cost of MST = "<<primsMST(V, adj)<<endl;

    return 0;
}