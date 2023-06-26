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

int dis[100001];
vi Max(100001);
vi Min(100001);

vpii v[100001];

void bfs(int n) {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < v[current].size(); ++i) {
            int next = v[current][i].first;
            if (dis[next] < dis[current] + 1 && dis[next] != 0) continue;
            else {
                dis[next] = dis[current] + 1;
                q.push(next);
                int temp = v[current][i].second;
                if (temp < Min[next]) Min[next] = temp;
                else if (temp > Max[next]) Max[next] = temp;
            }
        }
    }

    cout << Max[n] - Min[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill(Min.begin(), Min.begin() + n + 1, 1000000001);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    bfs(n);

    return 0;
}

