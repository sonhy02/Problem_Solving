#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;


class heap {
public:
    heap() {
        v.push_back(0);
    }

    void insert(int a) {
        v.push_back(a);
        size++;
        int temp = size;
        while (temp != 1) {
            if (v[temp / 2] > v[temp]) swap(v[temp / 2], v[temp]);
            temp /= 2;
        }
    }

    int pop() {
        int rst = v[1];
        int temp = v[size];
        v.erase(v.end());
        size--;
        v[1] = temp;
        temp = 1;
        while (temp <= v.size()) {
            if (v[temp] < v[temp * 2] && v[temp] < v[temp * 2 + 1]) break;
        }

        return rst;
    }


    int size = 0;
    vi v;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif


    return 0;
}