#include <bits/stdc++.h>

using namespace std;
bool check[101];
vector<vector<string>>a;
vector<string>y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    a.push_back(y);
    int t;
    cin >> t;
    memset(check, 1, size(check));
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            string p;
            cin >> p;

            for (int j = 0; j < k; ++j) {
               a[i][j].push_back(p.at(j));
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[j][k];
                if (check[j] == 0) continue;
                if (a[0][k] != a[j][k] && check[j] == true) check[j] = false;
            }
            cout << "\n";
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (check[i]) cnt++;
        }

        cout << cnt << "\n";

    }

    return 0;
}