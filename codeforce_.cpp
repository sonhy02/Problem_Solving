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
    while (t--) {
        int a;
        cin >> a;
        string s;
        cin >> s;
        set<string> ss;

        for (int i = 0; i < s.size() - 1; ++i) {
            string n1 = s.erase(i, 1);
            string n2 = s.erase(i + 1, 1);
            ss.insert(n1);
            ss.insert(n2);
        }

        cout << ss.size() << "\n";
    }
    return 0;
}
