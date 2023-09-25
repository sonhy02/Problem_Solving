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
        string s;
        cin >> s;
        int cnt = 1;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            bool flag = false;
            if (s[i] == s[i + 1] && s[i] == 'A') {
                if (i > 1 && s[i - 1] == 'B') flag = true;
                cnt++;
            } else if (s[i] == s[i - 1] && s[i] == 'A' && s[i + 1] == 'B' && i < s.size()) flag = true;
            if (s[i] != s[i + 1]) {
                if (flag) {
                    ans += cnt;
                    cnt = 1;
                }
            }

        }
        cout << ans << "\n";
    }

    return 0;
}