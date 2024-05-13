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
    int t;
    cin >> t;
    int p[501];
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        memset(p, 0, sizeof(p));
        for (int i = 0; i < a; ++i) {
            int aa;
            cin >> aa;
            if (!p[aa]) p[aa]++;
            else ans++;
        }
        cout << ans << "\n";


    }

    return 0;
}
