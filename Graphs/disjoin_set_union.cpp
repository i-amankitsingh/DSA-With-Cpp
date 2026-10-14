#include<iostream>
#include<vector>

using namespace std;


class DisjointSetUnion {
    public: 
    int n;
    vector<int> parent, rank;

    DisjointSetUnion(int n){
        this->n = n;

        for(int i = 0; i < n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void unionByRank(int a, int b){
        int parentA = find(a);
        int parentB = find(b);
        if(parentA == parentB) return;

        if(rank[parentA] == rank[parentB]){
            parent[parentB] = parentA;
            rank[parentA]++;
        } else if(rank[parentA] > rank[parentB]){
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void getInfo(){
        for(int i = 0; i < n; i++){
            cout<< parent[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < n; i++){
            cout<< rank[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout<< dsu.find(2)<<endl;

    dsu.unionByRank(1,3);
    dsu.unionByRank(2,5);
    dsu.unionByRank(0,3);

    dsu.unionByRank(0, 4);

    dsu.getInfo();

    return 0;
}