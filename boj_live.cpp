#include <bits/stdc++.h>

using namespace std;
int inp[5] = {1, 0, 0, 1, 0};
int movex[4] = {-1, 1, 0, 0};
int movey[4] = {0, 0, -1, 1};
int p[12118][6];
bool check[12118][6];
int r, c;

void dfs1(int x, int y, int idx) {
    check[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int dx = x + movex[i];
        int dy = y + movey[i];


    }

}


void dfs(int x, int y, int idx) {
    check[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int dx = x + movex[i];
        int dy = y + movey[i];
        if (dy < 0) dy = 4;
        else if (dy == 5) dy = 0;
        if(dx < 0 || dx >= c  || check[)

    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    int m = 5;
    if (r < 5) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                p[j][i] = inp[m % 5];
                m++;
            }
        }
    }

    return 0;
}
