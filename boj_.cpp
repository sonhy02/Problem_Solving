#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


vi edge[500001];
pii ett[500001];
ll segTree[2000004];
ll lazy[2000004];
vector<pll> arr;

void setLazy(int ptr, int l, int r) {
    ll temp = lazy[ptr];
    lazy[ptr] = -1;
    segTree[ptr] = (r - l + 1) * temp;
    if (l != r) {
        lazy[ptr * 2] = temp;
        lazy[ptr * 2 + 1] = temp;
    }
}

void update(int ptr, int l, int r, int i, int j, ll val) {
    if (lazy[ptr] != -1) setLazy(ptr, l, r);

    if (j < l || r < i) return;
    if (i <= l && r <= j) {
        segTree[ptr] = (r - l + 1) * val;

        if (l != r) {
            lazy[ptr * 2] = val;
            lazy[ptr * 2 + 1] = val;
        }
        return;
    }
    update(ptr * 2, l, (l + r) / 2, i, j, val);
    update(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j, val);

    segTree[ptr] = segTree[ptr * 2] + segTree[ptr * 2 + 1];
}

ll getVal(int ptr, int l, int r, int i, int j) {
    if (lazy[ptr] != -1) setLazy(ptr, l, r);
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return segTree[ptr];

    return getVal(ptr * 2, l, (l + r) / 2, i, j)
           + getVal(ptr * 2 + 1, (l + r) / 2 + 1, r, i, j);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;


    return 0;
}
