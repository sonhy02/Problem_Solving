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
    vi v(t);
    for (int i = 0; i < t; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0;
    int r = t - 1;
    int min = INF;
    int ans1 = v[l], ans2 = 0, ans3 = v[r];
    while (l < r) {
        int sum = v[l] + v[r];
        for (int i = l + 1; i < r; ++i) {
            int temp = sum + v[i];
            if (abs(temp) < abs(min)) {
                ans1 = v[l];
                ans2 = v[i];
                ans3 = v[r];
                min = temp;
            }
            if (temp == 0) break;
        }
        if (v[l] + v[r] > 0) {
            r--;
        } else if (v[l] + v[r] < 0) {
            l++;
        }
    }

    cout << ans1 << " " << ans2 << "" << ans3 << "\n";
    return 0;
}
