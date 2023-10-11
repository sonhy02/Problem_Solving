#include <bits/stdc++.h>

using namespace std;
const int INF = (int) 1e12;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int ccw(pii p1, pii p2, pii p3) {
    int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, t, m, s, e;
    cin >> n >> t >> m >> s >> e;


}
