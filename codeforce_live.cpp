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

int parent[200001];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        for (int i = 0; i < a; ++i) {
            parent[i] = i;
        }
        vi v(a);
        vi u(a);
        int cnt = 0;
        for (int i = 0; i < a-1; ++i) {
            cin >> u[i] >> v[i];
        }
        int i = 0;
        int ans = 1;
        while (cnt < a-1) {


         if(find(v[i]) != find(u[i]))



        }
        cout << ans + 1 << "\n";

    }
    return 0;
}
