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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll w, h, n, m, k;
    cin >> w >> h >> k;
    cin >> n;
    vll v1(n);
    for (auto &i: v1) cin >> i;
    v1.insert(v1.begin(), 0);
    v1.push_back(h);
    cin >> m;
    vll v2(m);
    for (auto &i: v2) cin >> i;
    v2.insert(v2.begin(), 0);
    v2.push_back(w);
    vi x, y;
    for (int i = 0; i < v1.size() - 1; ++i) {
        x.push_back(v1[i + 1] - v1[i]);
    }
    for (int i = 0; i < v2.size() - 1; ++i) {
        y.push_back(v2[i + 1] - v2[i]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = 0;
    for (int i = 0; i < x.size(); ++i) {
        ans += upper_bound(y.begin(), y.end(), k / x[i]) - y.begin();
    }
    cout << ans;
    return 0;
}
