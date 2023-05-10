#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using ll = long long;
using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;

    cin >> t;
    while (t--) {
        int r = 0, l = 0;
        int n, m;
        int temp3 = 0;
        cin >> n >> m;
        vi v(m);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a == -1) l++;
            else if (a == -2) r++;
            else v.push_back(a);
        }
        sort(v.begin(), v.end());





    }
    return 0;
}