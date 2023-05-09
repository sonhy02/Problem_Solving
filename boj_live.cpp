#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using vi = vector<int>;
bool check[2501][2501];
int cnt;

bool pali(string s, int a, int b) {
    for (int i = 0; i < s.length(); ++i) {
        if (a > b) return true;
        else if (s[a] != s[b - 1]) return false;
        a++;
        b--;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        check[i][i] = true;
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; i - j < 0 || i + j > s.length(); ++j) {
            if (check[i])
        }


    }


    return 0;
}
