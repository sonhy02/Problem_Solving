#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
        ll n, x, y;
        cin >> n >> x >> y;

        ll lcm = (x * y) / gcd(x, y);
        ll a = (n / x) - 1;
        ll b = (n / y) - 1;
        ll common = n / lcm;

        ll score = (a * (a + 1) / 2) * x + (b * (b + 1) / 2) * y - (common * (common + 1) / 2) * lcm;

        cout << score << "\n";
    }

    return 0;
}
