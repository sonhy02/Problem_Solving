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


int table[10000];

vi fun(vi v, int n, int m, ll X, ll Y, ll Z) {
    vi a;
    for (ll i = 0; i < n; ++i) {
        a.push_back(v[i % m]);
        v[i % m] = (X * v[i % m] + Y * (i + 1)) % Z;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int n, m;
    ll X, Y, Z;
    int cnt = 1;
    while (t--) {
        cin >> n >> m >> X >> Y >> Z;
        vi v(m);
        for (auto &i: v) {
            cin >> i;

        }
        vi a = fun(v, n, m, X, Y, Z);
        int rst = 0;
        for (int i = 0; i < n; ++i) {
            table[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i]) {
                    table[i] = (table[i] + table[j]) % 1000000007;
                }
            }
            rst = (rst + table[i]) % 1000000007;
        }
        cout << "Case #" << cnt << ": " << rst << "\n";
        cnt++;
    }
}