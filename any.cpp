#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n; cin >> n;
    string s, t; cin >> s >> t;

    set<char> st;
    for (char c : s) st.insert(c);
    for (char c : t) {
        if (!st.count(c)) {
            cout << 0;
            return 0;
        }
    }

    vvll psum(26, vll(s.size()));
    for (int c = 0; c < 26; c++) {
        psum[c][0] = (s[0]-'a' == c);
        for (int i = 1; i < s.size(); i++) psum[c][i] = psum[c][i-1] + (s[i]-'a' == c);
    }

    auto func = [&] (ull cycle, ll begin, char target, ull count) -> pair<ull, ll> {
        auto &p = psum[target-'a'];

        ull what = count + (begin-1 >= 0 ? p[begin-1] : 0);
        auto it = lower_bound(p.begin()+begin, p.end(), what);
        if (it != p.end()) return pair<ull, ll>{cycle, it-p.begin()};

        cycle++;
        count -= p[s.size()-1] - (begin-1 >= 0 ? p[begin-1] : 0);

        ull whole = p[s.size()-1];
        cycle += count / whole;
        count %= whole;
        if (count == 0) {
            cycle--;
            it = lower_bound(p.begin(), p.end(), whole);
            return pair<ull, ll>{cycle, it-p.begin()};
        }

        it = lower_bound(p.begin(), p.end(), count);
        return pair<ull, ll>{cycle, it-p.begin()};
    };

    ull lo = 0, hi = 2e18;
    while (lo+1 < hi) {
        ull mid = lo+hi>>1;

        ull cycle = 1;
        ll begin = 0;
        for (char c : t) {
            auto [ncycle, nend] = func(cycle, begin, c, mid);
            cycle = ncycle;
            begin = nend+1;
            if (begin == n) {
                cycle++;
                begin = 0;
            }
        }

        begin--;
        if (begin < 0) cycle--;

        if (cycle > n) hi = mid;
        else lo = mid;
    }
    cout << lo;
}