#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;
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
    vll v(t);
    for (int i = 0; i < t; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll ans1, ans2, ans3;
    ll min = INF;

    for (int i = 0; i < t - 2; ++i) {
        int l = i + 1;
        int r = t - 1;

        while (l < r) {
            ll sum = v[i] + v[l] + v[r];
            if (abs(sum) < abs(min)) {
                ans1 = v[i];
                ans2 = v[l];
                ans3 = v[r];
                min = sum;
            }
            if (sum > 0) {
                r--;
            } else {
                l++;
            }
        }
        if (min == 0) break;
    }

    vll a = {ans1, ans2, ans3};
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }

    return 0;
}
