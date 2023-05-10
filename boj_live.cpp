#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using vi = vector<int>;
bool check[2500][2500];
string s;
int cnt;

void pali(int a) {
    if (a > s.size()) return;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (check[a][i]) {
            cnt++;
            pali(i + 1);
            return;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    check[s.size()][s.size()] = true;
    for (int i = 0; i < s.size() - 1; ++i) {
        check[i][i] = true;
        if (s[i] == s[i + 1]) check[i][i + 1] = true;
    }
    for (int i = s.size()/2 + 1; i >=0; --i) {
        for (int j = 0; j < s.size(); ++j) {

            if (check[i][j] && (s[i - 1] == s[j + 1])) check[i - 1][j + 1] = true;

        }
    }
    pali(0);
    cout << cnt << "\n";
    return 0;
}
