#include <bits/stdc++.h>

using namespace std;
vector<long long> v;
vector<long long> v2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long mi = 1e18;
        long long sum = 0;
        long long sum1 = 0;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p;
            v2.push_back(p);
        }

        sort(v2.begin(), v2.end());
        int j = 0;
        for (int i = 0; i < k; ++i) {
            int p2 = v2[j] + v2[j + 1];
            v.push_back(p2);
            j = j + 2;
        }

        for (int i = 0; i <= k; ++i) {

            for (int j = 0; j < i; ++j) {
                sum1 += v[j];
            }
            for (int j = v2.size() - 1; j > v2.size() - 1 - (k - i); --j) {
                sum1 += v2[j];
            }
            if (mi > sum1) mi = sum1;
            sum1 = 0;
        }

        for (int i = 0; i < v2.size(); ++i) {
            sum += v2[i];
        }

        cout << sum - mi << "\n";
        v.clear();
        v2.clear();
    }

    return 0;
}