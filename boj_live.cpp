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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n > 32) {
            cout << 0 << "\n";
        } else {
            vi p;
            vector<string> v;
            for (int i = 0; i < n; ++i) {
                string s;
                cin >> s;
                v.push_back(s);
            }
            for (int i = 0; i < n - 1; ++i) {
                for (int j = i+1; j < n; ++j) {
                    int sum = 0;
                    for (int k = 0; k < 4; ++k) {
                        if (v[i][k] != v[j][k]) sum++;
                    }
                    p.push_back(sum);
                }
            }
            sort(p.begin(), p.end());
            cout << p[0] + p[1] + p[2] << "\n";


        }


    }
    return 0;
}
