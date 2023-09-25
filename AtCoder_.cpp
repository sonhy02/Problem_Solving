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

int n, x;
vi v;

bool isPossible(int mid) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] < mid) {
            sum += mid - v[i];
        }
    }
    return sum <= x;
}

int binarySearch(int left, int right) {
    int ans = left;

    while (left < right) {
        int mid = left + right / 2;
        if (isPossible(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid ;
        }
    }
    return ans;
}

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
        cin >> n >> x;
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int ans = binarySearch(1, 1000000009);
        cout << ans << "\n";
    }

    return 0;
}
