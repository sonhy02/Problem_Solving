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

int dfs_cnt = 0;
void dfs() {


}


int m[500001];
vi edge[500001];
pii ett[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;
    cin >> m[1];
    for (int i = 2; i <= a - 1; ++i) {
        cin >> m[i];
        int c;
        cin >> c;
        edge[i].push_back(c);
    }


    return 0;
}
