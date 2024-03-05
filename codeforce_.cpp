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

ll dp[1000000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    // 1 3 6 10 15
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 3;
    dp[6] = 1;
    dp[7] = 2;
    dp[8] = 3;
    dp[9] = 2;
    dp[10] = 1;
    dp[11] = 2;
    dp[12] = 2;
    dp[13] = 2;
    dp[14] = 3;
    dp[15] = 1;
    vi c = {15, 10, 6, 3, 1};
    for (int i = 1; i < 1000000; i++) {
        dp[i] = i;
        for (int x: {1, 3, 6, 10, 15}) {
            if (i - x >= 0) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 1000000) cout << dp[n] << "\n";
        else {
            int temp = n / 15;
            n -= temp * 15;
            cout << dp[n + 30] + temp - 2 << "\n";
        }

    }
    return 0;
}