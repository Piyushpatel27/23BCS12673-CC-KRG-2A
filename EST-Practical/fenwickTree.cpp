#include <bits/stdc++.h>
using namespace std;

class Fenwick {
    int n;
    vector<int> bit;

public:
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0); 
    }

    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i>0) {
            sum+=bit[i];
            i-= i&-i;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main(){
    
}