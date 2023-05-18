#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
bool dp[2501][2501];
vector<int> num(2001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
        if (i != 0 && s[i - 1] == s[i]) dp[i - 1][i] = true;
    }

    for (int i = 2; i < s.size() - 1; ++i) {
        for (int j = 0; i + j < s.size(); ++j) {
            if (dp[j + 1][i + j - 1] && s[j] == s[i + j]) dp[j][i + j] = true;
        }
    }

    int b = 0, e = s.size() - 1, cnt = 0;

    while (b < s.size()) {
        cout << dp[b][e] << "\n";
        if (dp[b][e]) {
            cnt++;
            b = e + 1;
            e = s.size() - 1;
            cout << b << " " << e << "\n";
        }
        if (b >= s.size()) break;
        e--;
    }

    cout << cnt << "\n";
    return 0;
}
