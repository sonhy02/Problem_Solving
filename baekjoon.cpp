#include <bits/stdc++.h>

using namespace std;
const int INF = (int) 1e12;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

ll init(vi& v, vll& tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = init(v, tree, node * 2, start, mid)
                        + init(v, tree, node * 2 + 1, mid + 1, end);

}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vi v(n);
    int check = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        check += v[i];
    }
    if (check < m) {
        cout << 0;
        return 0;
    }



    return 0;

}
