#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    ll s = 1;
    for (int i = 1; i <= a; i++) {
        s *= i;
    }
    string t = to_string(s);
    int len = t.size();
    ll cnt = 0;
    while (len > 0) {
        len--;
        if (t.at(len) == '0') {
            cnt++;
        } else {
            cout << cnt << "\n";
            return 0;
        }

    }


    return 0;
}


