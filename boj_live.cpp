#include <bits/stdc++.h>


const int INF = 0x3f3f3f3f;
using namespace std;

int pos[1001][1001];
bool check[1001][1001];
int cont[1001][1001]{0};
int movex[4]{0, 0, -1, 1};
int movey[4]{-1, 1, 0, 0};
deque<pair<int,int>> p;
int m,n, r, l;
int cr,cl;
int bfs(){
    while (!p.empty()){
    int x = p.front().first;
    int y = p.front().second;
    p.erase(p.begin());
    for (int k = 0; k < 4; k++) {
        int px = x + movex[k];
        int py = y + movey[k];

        if( px < 1 || py < 1 || px > n || px > m || pos[px][py] == 1 || check[px][py] == 1 || cl == l || cr == r) continue;
        else if(pos[px][py] == 0 && check[px][py] == 0) {
            if(k == 0 || k == 1 ) {
                p.push_front({px, py});
                check[px][py] = 1;
                cont[px][py] = cont[x][y] + 1;

            } else if(k == 2){
                cl++;
                p.push_back({px, py});
                check[px][py] = 1;
                cont[px][py] = cont[x][y] + 1;

            } else if (k == 3) {
                cr++;
                p.push_back({px, py});
                check[px][py] = 1;
                cont[px][py] = cont[x][y] + 1;
            }


        }
      }

    }
    int Max = cont[0][0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (Max < cont[j][i]) {
                Max = cont[j][i];
            }

        }
    }
    return Max;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> r >> l;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            pos[j][i] = a;
            if(a==2) { p.push_front({j,i}); }
        }
    }

    cout << bfs();

    return 0;
}

//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//const int MAX_N = 1001;
//const int INF = 987654321;
//
//int N, M, L, R;
//int map[MAX_N][MAX_N];
//int dist[MAX_N][MAX_N][2];
//
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
//
//void bfs(int sx, int sy) {
//    deque<pair<int, int>> dq;
//    memset(dist, 0x3f, sizeof(dist));
//
//    dist[sx][sy][0] = 0;
//    dq.push_front({sx, sy});
//
//    while (!dq.empty()) {
//        int x = dq.front().first;
//        int y = dq.front().second;
//        dq.pop_front();
//
//        for (int i = 0; i < 4; i++) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
//            if (map[nx][ny] == 1) continue;
//
//            int cost = 1;
//            if (i == 1) cost = R;
//            else if (i == 0) cost = L;
//
//            if (dist[nx][ny][0] > dist[x][y][0] + cost) {
//                dist[nx][ny][0] = dist[x][y][0] + cost;
//                if (cost == 1) dq.push_back({nx, ny});
//                else dq.push_front({nx, ny});
//            }
//
//            if (dist[nx][ny][1] > dist[x][y][1] + cost) {
//                dist[nx][ny][1] = dist[x][y][1] + cost;
//                if (cost == 1) dq.push_front({nx, ny});
//                else dq.push_back({nx, ny});
//            }
//        }
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    cin >> N >> M >> L >> R;
//
//    int start_x = -1, start_y = -1;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cin >> map[i][j];
//            if (map[i][j] == 2) {
//                start_x = i;
//                start_y = j;
//            }
//        }
//    }
//
//    bfs(start_x, start_y);
//
//    int ans = min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
//    if (ans == INF) cout << -1 << endl;
//    else cout << ans << endl;
//
//    return 0;
//}
