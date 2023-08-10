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

//bool comp(pair<int, pii> x, pair<int, pii> y) {
//    if (x.first > y.first) return x.first > y.first;
//    else if (x.first == y.first) {
//        if (x.second.first < y.second.first) {
//            return x.second.first < y.second.first;
//        } else if (x.second.first == y.second.first) {
//            if (x.second.second == 0) {
//                return x.second.first < y.second.first;
//            }
//        }
//    }
//}
bool comp(pair<int, pii> x, pair<int, pii> y) {
    if (x.first == y.first) {
        if (x.second.first == y.second.first) {
            return x.second.second < y.second.second;
        } else {
            return x.second.first < y.second.first;
        }
    } else {
        return x.first > y.first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<vi> v(n);
        vector<vi> w(n);
        vector<vi> s(n);
        vector<pair<int, pii>> r;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int a;
                cin >> a;
                v[i].push_back(a);
            }
            sort(v[i].begin(), v[i].end());
        }
        for (int i = 0; i < n; ++i) {
            int temp = 0;
            for (int j = 0; j < m; ++j) {
                temp += v[i][j];
                w[i].push_back(temp);
            }
        }
        for (int i = 0; i < n; ++i) {
            s[i].push_back(v[i][0]);
            for (int j = 1; j < m; ++j) {
                s[i].push_back(s[i][j-1] + w[i][j]);
            }
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            int temp = 0;
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                temp += v[i][j];
                if (temp <= h) cnt++;
                else {
                    break;
                }
            }
            r.push_back({cnt, {s[i][cnt - 1], i}});

        }

        sort(r.begin(), r.end(), comp);
//        for (int i = 0; i < r.size(); ++i) {
//            cout << r[i].first << " " << r[i].second.first << " " << r[i].second.second << " \n";
//        }
        for (int i = 0; i < r.size(); ++i) {
            if (r[i].second.second == 0) {
                cout << i + 1 << "\n";
            }
        }

    }
    return 0;
}
