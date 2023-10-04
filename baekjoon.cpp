#include <bits/stdc++.h>

using namespace std;
const int INF = (int) 1e11;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

int parent[100001];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
   vpii v;
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (sameparent(a, b)) {
            merge(a, b);
        }
    }




    return 0;
}
