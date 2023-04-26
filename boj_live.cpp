#include <bits/stdc++.h>

using namespace std;
int p[1001][1001];
bool check[1001][1001];
int n, m;
int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, -1, 1};
int jump[1001][1001];

void bfs() {
    queue<pair<int, int>> pos;
    check[0][0] = true;
    pos.push({0, 0});
    while (!pos.empty()) {
        int x = pos.front().first;
        int y = pos.front().second;
        pos.pop();
        for (int i = 0; i < 4; ++i) {
            x = x + movex[i];
            y = y + movey[i];
            if (x < 0 || y < 0 || x > m || y > n || check[x][y] == true) continue;
            if (p[x][y] == 1){
                if(jump[x][y] == 0 && p[x + movex[i]][y + movey[i]] == 0){
                  jump[x][y] = 1;


                } else continue;
            }


                check[x][y] = true;
            pos.push({x, y});

        }


    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string inp;
        cin >> inp;
        for (int j = 0; j < m; ++j) {
            p[j][i] = inp.at(j);
        }
    }
bfs();

    return 0;
}