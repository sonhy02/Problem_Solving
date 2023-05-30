#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

int parent[100001];
int dist[100001];

int find(int x) {
    if (x == parent[x]) return x;
    dist[x] += dist[parent[x]];
    return parent[x] = find(parent[x]);
}

void merge(int x, int y, int w) {
    int px = find(x);
    int py = find(y);
    if (px == py) return;


    parent[y] = x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        for (int i = 0; i < b; ++i) {
            string s;
            if (s == "!") {
                int n, m, d;
                cin >> n >> m >> d;


            } else {
                int n, m;
                cin >> n >> m;
                if (parent[n] != parent[m]) cout << "UNKNOWN\n";
                else {

                }

            }


        }


    }

    return 0;
}

