#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

vector<pair<int, string>> block;
vi chain;
bool check[100001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        int t;
        cin >> s1 >> s2 >> t;
        block.push_back({t, s1});
        check[t] = true;
    }
    for (int i = 1; i < 2 * n; ++i) {
        if (!check[i])
            chain.push_back(i);
    }

    return 0;
}
