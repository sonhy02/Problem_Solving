#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

struct segtree {
    ll n;
    vector<ll> tree;
    segtree(ll n) : n(n) { tree.resize(n*4); }

    void update(ll t, ll x, ll i, ll l, ll r) {
        if (l == r) {
            tree[i] = x;
            return;
        }

        ll m = l+r>>1;
        if (t <= m) update(t, x, i<<1, l, m);
        else update(t, x, i<<1|1, m+1, r);
        tree[i] = tree[i<<1] + tree[i<<1|1];
    }

    void update(ll t, ll x) {
        update(t, x, 1, 1, n);
    }

    ll query(ll b, ll e, ll i, ll l, ll r) {
        if (b > r || e < l) return 0;
        if (b <= l && r <= e) return tree[i];

        ll m = l+r>>1;
        return query(b, e, i<<1, l, m) + query(b, e, i<<1|1, m+1, r);
    }

    ll query(ll b, ll e) {
        return query(b, e, 1, 1, n);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);




    return 0;
}