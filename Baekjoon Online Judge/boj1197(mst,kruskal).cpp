#include <bits/stdc++.h>

using namespace std;


vector<pair<int, pair<int, int>>> v;
int parent[10001];

int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    parent[y] = x;
}

bool sameparent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int result = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            result += v[i].first;
        }
    }
    cout << result;


    return 0;
}

