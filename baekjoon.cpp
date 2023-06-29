#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

unordered_multiset<int> c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            c.insert(s[i]);
        }
        int a;
        cin >> a;
        vi v[a];
        string l, r;
        cin >> l >> r;
        for (int i = 0; i < a; ++i) {
            int b = (int)l[i];
            int e = (int)r[i];
            for (int j = b; j <= e; ++j) {
                v[i].push_back(j);
            }
        }
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (c.find(v[i][j]) != c.end())
            }
        }
    }


    return 0;
}