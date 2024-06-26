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
    while (t--) {
        int n;
        cin >> n;
        vll a(n);
        vll b(n);
        for (auto &i: a) {
            cin >> i;
        }
        for (auto &i: b) {
            cin >> i;
        }
        int ans = 0;
        int l = 0, r = 0;
        while (r != n - 1) {
            if (a[l] > b[r]) {
                r++;
                ans++;
            } else {
                l++;
                r++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
