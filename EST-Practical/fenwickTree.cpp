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

int main() {
    int n = 5;
    Fenwick ft(n);

    ft.update(1, 5);
    ft.update(2, 3);
    ft.update(3, 2);
    ft.update(5, 10);

    cout << ft.rangeQuery(1, 3) << endl;
    cout << ft.rangeQuery(2, 5) << endl;

    return 0;
}