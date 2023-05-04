#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fastpow(ll a, ll b, ll mod) {
    if (b == 0) {
        return 1;
    }

    ll sub = fastpow(a, b / 2, mod);
    ll result = sub * sub % mod;

    if (b % 2 == 1) {
        result = result * a % mod;
    }

    return result;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    cout << fastpow(a, b, c) << "\n";


    return 0;
}