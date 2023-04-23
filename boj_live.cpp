#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int ans;
int n, m, r, a, b, l;
int item[101];
int d[101];
vector<pair<int, int>> p[101];

void dijkstra(int start) {
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        int dist = d[node];
        q.pop();

        for (int i = 0; i < p[node].size(); i++) {
            int next_node = p[node][i].first;
            int next_dist = p[node][i].second;

            if (d[next_node] > dist + next_dist) {
                d[next_node] = dist + next_dist;
                q.push(next_node);
            }

        }
    }

    for (int i = 1; i <= n; i++)
        if (d[i] <= m) cnt += item[i];

    ans = max(ans, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;


    for (int i = 1; i <= n; i++) cin >> item[i];


    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        p[a].push_back({b, l});
        p[b].push_back({a, l});
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    cout << ans;

}