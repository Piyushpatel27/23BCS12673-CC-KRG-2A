#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++)
            parent[i]=i;
    }

    int find(int x) {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]); 
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px==py) return;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int kruskal(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end()); // sort by weight

    DSU dsu(n);
    int cost = 0;

    for(auto &e:edges) {
        int w=e[0], u=e[1], v=e[2];

        if(dsu.find(u)!=dsu.find(v)) {
            cost += w;
            dsu.unite(u, v);
        }
    }
    return cost;
}

int main() {
    int n = 4; 
    vector<vector<int>> edges = {
        {10, 0, 1},
        {6, 0, 2},
        {5, 0, 3},
        {15, 1, 3},
        {4, 2, 3}
    };

    int mstCost = kruskal(n, edges);

    cout<< mstCost << endl;

    return 0;
}
