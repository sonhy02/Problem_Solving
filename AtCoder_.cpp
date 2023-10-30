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

struct Node {
    int prices;
    vi v;
};

bool comp(Node n1, Node n2) {
    return n1.prices < n2.prices;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n, k, p;
    cin >> n >> k >> p;
    Node node[n];
    for (int i = 0; i < n; ++i) {
        cin >> node[i].prices;
        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;
            node[i].v.push_back(a);
        }
    }
    sort(node, node + n, comp);
    int price = 0;
    vi rst(k);
    vi node_num;
    for (int i = 0; i < n; ++i) {
        node_num.push_back(i);
        bool flag = false;
        for (int j = 0; j < k; ++j) {
            rst[j] += node[i].v[j];
            if (rst[j] < p) {
                flag = true;
            }
        }
        price += node[i].prices;
        if (i == n - 1) {
            for (int l = 0; l < k; ++l) {
                if (rst[l] < p) {
                    cout << -1;
                    return 0;
                }
            }
        }
        if (!flag) break;
    }
    sort(node_num.begin(), node_num.end(), greater());
    for (int i = 1; i < node_num.size(); ++i) {
        bool flag = false;
        for (int j = 0; j < k; ++j) {
            if (rst[j] - node[node_num[i]].v[j] < p) {
                flag = true;
                break;
            }
        }
        if (flag)continue;
    }


    return 0;
}
