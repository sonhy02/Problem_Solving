#include <bits/stdc++.h>

#define endl "\n"
#define INF 0x3f3f3f3f
using namespace std;
vector<pair<int, int>> p[20001];
int d[20001];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        int c_d = q.top().first;
        int c = q.top().second;
        q.pop();
        if (d[c] < c_d) continue;
        for (int i = 0; i < p[c].size(); i++) {
            int next = p[c][i].first;
            int nd = c_d + p[c][i].second;
            if (d[next] > nd) {
                d[next] = nd;
                q.push(make_pair(nd, next));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, e, k;
    cin >> V >> e >> k;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        p[u].push_back(make_pair(v, w));

    }
    fill(d, d + 20001, INF);

    dijkstra(k);
    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        } else {
            cout << d[i] << endl;
        }
    }

    return 0;
}
