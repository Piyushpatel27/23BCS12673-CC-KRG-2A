#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    // Relax edges K+1 times
    for(int i = 0; i <= K; i++){
        vector<int> temp = dist;

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] == 1e9) continue;

            if(dist[u] + w < temp[v]){
                temp[v] = dist[u] + w;
            }
        }

        dist = temp;
    }

    return (dist[dst] == 1e9) ? -1 : dist[dst];
}

int main(){
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100},
        {1,3,600}, {2,3,200}
    };

    int src = 0, dst = 3, K = 1;

    cout << findCheapestPrice(n, flights, src, dst, K);

    return 0;
}