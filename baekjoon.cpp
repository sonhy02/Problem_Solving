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

vector<pii> p[16];
bool check[16];

struct sub {
    int food;
    int hobby;
    int family;
    int philosophy;
};

void dfs(int n) {
    for (int i = 0; i < p[n].size(); ++i) {




    }
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
    sub f[n];
    vector<int> v[n];
    for (int i = 0; i < n; ++i) {
        cin >> f[i].family >> f[i].food >> f[i].hobby >> f[i].philosophy;
    }
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(i);
        if (a != b)
            v[b].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        p[a].push_back({b, c});
        p[b].push_back({a, c});
    }
    for (int i = 0; i < p[1].size(); ++i) {
        dfs(i);
    }


    return 0;
}
